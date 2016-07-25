/*
 * ________________________________________________________________________________________________________
 * Copyright (c) 2015-2015 InvenSense Inc. All rights reserved.
 *
 * This software, related documentation and any modifications thereto (collectively “Software”) is subject
 * to InvenSense and its licensors' intellectual property rights under U.S. and international copyright
 * and other intellectual property rights laws.
 *
 * InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
 * and any use, reproduction, disclosure or distribution of the Software without an express license agreement
 * from InvenSense is strictly prohibited.
 *
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES, THE SOFTWARE IS
 * PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES, IN NO EVENT SHALL
 * INVENSENSE BE LIABLE FOR ANY DIRECT, SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, OR ANY
 * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THE SOFTWARE.
 * ________________________________________________________________________________________________________
 */

/**
 * @file
 * @brief This sketch print on the serial interface quaternion data read from device until 
 *        a char is received on the serial interface.
 *        You can restart the demo by sending a new char on the serial interface
 *
 *        WARNING : you must use the calibration sketch before using this one in 
 *        order to have a correct orientation. The bias computed are displayed in
 *        the Serial monitor window. Copy/paste the value in this sketch
 *        See bias table below in this sketch
 */
 
// Be sure that you choose Arduino Zero board in Tools => Board
#ifndef ARDUINO_SAMD_ZERO
#	error "You must choose Arduino Zero in IDE Tools => Board"
#endif

// We can not processs warning as error on whole code since Arduino libraries
// has warnings in -Wall
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-Werror"

// Required for spi use in library
#include <SPI.h>
#include "ArduinoEmdAdapter.h"
#include "DeviceIoHal.h"
#include "Invn/Devices/DeviceIcm30xxx.h"
#include "Invn/Utils/Message.h"
#include <stdarg.h>
#include "EasyDevice.h"

/* Private define ------------------------------------------------------------*/
float gyro_data[3];
float acc_data[3];
float eul_data[3];
uint8_t send_byte[255];
float t, t_, del_t;
float psi = 0;
float psi_scaled = 0;


/**
 * Define target
 */
#define USE_ICM30670

/**
 * Define msg level
 */
#define MSG_LEVEL INV_MSG_LEVEL_WARNING

/**
 * Comment this line to avoid ICM-M0 fw programming
 */
#define ENABLE_FW_M0_PROG

/**
 * Define where traces are transmitted
 */
#define SERIAL_TRACES Serial

/**
 * Max string size for trace display
 */
#define MAX_TRACES_STRING_SIZE   (200)

 /**
  * Macro for testing return code and return from function with a FAIL message
  */
#define TEST_RC(rc) if(rc) \
					{ \
						printTraces("FAIL"); \
						return rc; \
					}
				
/* Public function prototypes ------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/******************************************************************************
 * WARNING : you must use the calibration sketch before using this one in 
 * order to have a correct orientation. The bias computed are displayed in
 * the Serial monitor window. Copy/paste the value in this sketch
 ******************************************************************************/

/**
 * Accel bias
 * You must change this table from data computed from the calibration sketch
 */

static float acc_bias[3] = { 0.000092, -0.006287, 0.021484 };
static float gyr_bias[3] = { -0.221252, -0.308990, 0.377655 };

/**
 * Gyro bias
 * You must change this table from data computed from the calibration sketch 
 */


/**
 * Some memory to be used by the Icm30xxx driver (must be >= 4k)
 */
static uint8_t device_buffer[1024*4]; 

/** 
 * event counter
 */
static unsigned event_count = 0;

/**
 * Flag = true if a gpio interrupt was asserted
 */
static bool data_int_occured = false;

/**
 * Flag = true if a timer overflow interrupt was asserted
 */
static bool watchdog_int_occured = false;
 
/*
 * The device requires a FW and DMP images to be loaded on init
 * Images will be provided as a byte array
 */
 
/**
 * M0 image
 */
#ifdef ENABLE_FW_M0_PROG
#if defined(USE_ICM30630)
static const uint8_t flash_image[] = {
	#include "Images/icm30630_img.flash.m0.h"
	};
#elif defined(USE_ICM30631)
static const uint8_t flash_image[] = {
	#include "Images/androidl/icm30630_img.flash.m0.h"
	};	
#elif defined(USE_ICM30670)
static const uint8_t flash_image[] = {
	#include "Images/icm30670_img.flash.m0.h"
	};
#endif

#endif


#if defined(USE_ICM30630)
/**
 * DMP3 image
 */
static const uint8_t dmp3_image[] = {
	#include "Images/icm30630_img.sram.dmp3.h"
};

/**
 * DMP4 image
 */
static const uint8_t dmp4_image[] = {
	#include "Images/icm30630_img.sram.dmp4.h"
	};
#elif defined(USE_ICM30631)
/**
 * DMP3 image
 */
static const uint8_t dmp3_image[] = {
	#include "Images/androidl/icm30630_img.sram.dmp3.h"
};

/**
 * DMP4 image
 */
static const uint8_t dmp4_image[] = {
	#include "Images/androidl/icm30630_img.sram.dmp4.h"
	};
	
#elif defined(USE_ICM30670)
/**
 * DMP3 image
 */
static const uint8_t dmp3_image[] = { 0 };

/**
 * DMP4 image
 */
static const uint8_t dmp4_image[] = {
	#include "Images/icm30670_img.sram.dmp4.h"
};
#endif



/* Private function code ------------------------------------------------------*/

/** @brief Display a message (through means of printer function)
 *  Called from INV_MSG macro defined in Utils/Message.h
 *  @param[in]  level  level for the message
 *  @param[in]  str    message string
 *  @param[in]  ap     optional arguments
 *  @return none
 */
 void inv_msg_printer_arduino(int level, const char * str, va_list ap)
 {
	char String[MAX_TRACES_STRING_SIZE];
	
	const char * s[INV_MSG_LEVEL_MAX] = {
		"",    // INV_MSG_LEVEL_OFF
		" [E] ", // INV_MSG_LEVEL_ERROR
		" [W] ", // INV_MSG_LEVEL_WARNING
		" [I] ", // INV_MSG_LEVEL_INFO
		" [V] ", // INV_MSG_LEVEL_VERBOSE
		" [D] ", // INV_MSG_LEVEL_DEBUG
	};
	
	// Print the traces
	SERIAL_TRACES.print(s[level]);
	
	// Print format in a string
	vsnprintf(String, MAX_TRACES_STRING_SIZE, str, ap);
	String[MAX_TRACES_STRING_SIZE-1] = '\0'; // Avoid overflow if string is >= MAX_TRACES_STRING_SIZE char
	
	// print string
	SERIAL_TRACES.println(String);
 }
 
 
/** @brief Display a trace from sketch, manage warning as a gcc printf
 *  Data are printed on the Serial defined by SERIAL_TRACES
 *  @param[in]  str   message string
 *  @param[in]  ...   optional arguments
 *  @return none
 */
void printTraces(const char * str, ...) __attribute__ ((format (printf, 1, 2)));
void printTraces(const char * str, ...)
{
	char String[MAX_TRACES_STRING_SIZE];
	
	// Print a sketch
	SERIAL_TRACES.print("[SKETCH] ");
	
	// Print the traces
	va_list ap;
	va_start(ap, str);
	vsnprintf(String, MAX_TRACES_STRING_SIZE, str, ap);
	va_end(ap);
	String[MAX_TRACES_STRING_SIZE-1] = '\0'; // Avoid overflow if string is >= MAX_TRACES_STRING_SIZE char
	
	// Print string
	SERIAL_TRACES.println(String);
}


/** @brief Convert timestamp 64 bit in us to day, hour, min, sec, ms, us
 *  @param[in]  timestamp timestamp 64 bit in us
 *  @param[out] day       day
 *  @param[out] hr        hour
 *  @param[out] min       minute
 *  @param[out] sec       second
 *  @param[out] ms        milli-second
 *  @param[out] us        micro-second
 *  @return none
 */
void conv_timestamp_to_time(uint64_t timestamp, uint32_t *day, uint8_t *hr, uint8_t *min, uint8_t *sec, uint16_t *ms,  uint16_t *us)
{
	// uint64_t max value is +18,446,744,073,709,551,615
	// convert timestamp
	*us = (timestamp % 1000);
	timestamp /= 1000;
	
	*ms = (timestamp % 1000);
	timestamp /= 1000;
	
	*sec = (timestamp % 60);
	timestamp /= 60;
	
	*min = (timestamp % 60);
	timestamp /= 60;
	
	*hr = (timestamp % 60);
	timestamp /= 60;
	
	*day = timestamp;
}


/** @brief Sensor listener event callback definition
 *  @param[in] event     reference to sensor event
 *  @param[in] arg       listener context
 *  @return    none
 */
void sensor_event_cb(const inv_sensor_event_t * event, void * arg)
{
	uint32_t day;
	uint8_t  hr, min, sec;
	uint16_t ms, us;
	char     string[MAX_TRACES_STRING_SIZE];

	switch(event->sensor) 
	{
		case INV_SENSOR_TYPE_GAME_ROTATION_VECTOR:
			if(event->status == INV_SENSOR_STATUS_DATA_UPDATED)
			{
				// Increase event counter
				event_count++;
				
				conv_timestamp_to_time(event->timestamp, &day, &hr, &min, &sec, &ms, &us);
				
				//
				// Display sensor info. printf in Arduino doesn't support %f so we can not use trace function
				//
				SERIAL_TRACES.print("[SKETCH] ");
				snprintf(string, MAX_TRACES_STRING_SIZE, "%lud %02dh%02dm%02ds.%03hums.%03huus : evt cnt : %10u" , day, hr, min, sec, ms, us, event_count);
				string[MAX_TRACES_STRING_SIZE-1] = '\0';
				SERIAL_TRACES.print(string);
				
				SERIAL_TRACES.print(" : W = ");
				SERIAL_TRACES.print(event->data.quaternion.quat[0], 6);
				SERIAL_TRACES.print(" : X = ");
				SERIAL_TRACES.print(event->data.quaternion.quat[1], 6);
				SERIAL_TRACES.print(" : Y = ");
				SERIAL_TRACES.print(event->data.quaternion.quat[2], 6);
				SERIAL_TRACES.print(" : Z = ");
				SERIAL_TRACES.print(event->data.quaternion.quat[3], 6);
				SERIAL_TRACES.println("");
			}
			break;

    case INV_SENSOR_TYPE_UNCAL_GYROSCOPE:
      if(event->status == INV_SENSOR_STATUS_DATA_UPDATED)
      {
      //gyro_data[0] = (double)(event->data.gyr.vect[0]*1000);
      //gyro_data[1] = (double)(event->data.gyr.vect[1]*1000);
      //gyro_data[2] = (double)(event->data.gyr.vect[2]*1000);
      gyro_data[0] = (event->data.gyr.vect[0]);
      gyro_data[1] = (event->data.gyr.vect[1]);
      gyro_data[2] = (event->data.gyr.vect[2]);

      /* t = ((float)millis())*.001;
       del_t = t-t_;
       t_ = t;
       psi = psi + (gyro_data[2]-.45)*del_t;
  //psi_scaled = psi*(-0.065)*1.5/100;
  
       SERIAL_TRACES.print("psi_int:  ");
       SERIAL_TRACES.print(psi);
       SERIAL_TRACES.print("  dt:  ");
       SERIAL_TRACES.print(del_t,6);
       SERIAL_TRACES.print("  GYRO:  ");
       SERIAL_TRACES.println(gyro_data[2],6);*/
      
      
  
      }
      break; 
      
     


   /* case INV_SENSOR_TYPE_RAW_GYROSCOPE:
      if(event->status == INV_SENSOR_STATUS_DATA_UPDATED)
      {
      gyro_data[0] = (double)(event->data.gyr.vect[0]);
      gyro_data[1] = (double)(event->data.gyr.vect[1]);
      gyro_data[2] = (double)(event->data.gyr.vect[2]);
      
      t = ((double)millis())*.001;
      del_t = t-t_;
      t_ = t;
  
      }
      break;*/

    case INV_SENSOR_TYPE_ORIENTATION:
      if(event->status == INV_SENSOR_STATUS_DATA_UPDATED)
      { 
        eul_data[0] = event->data.orientation.x; 
        eul_data[1] = event->data.orientation.y;
        eul_data[2] = event->data.orientation.z;
        
        //SERIAL_TRACES.println(eul_data[0]);
        
      }
      break;
			
		default:
		    printTraces("UNEXPECTED SENSOR EVENT %d", event->sensor);
			break;
	}
	
	// Avoid a warning
	(void) arg; // We don't need this arg
}


/** @brief Callback Registered to the adapter
 *  WARNING : CALLED UNDER IRQ ! CODE INSIDE MUST BE THREAD SAFE !
 *  @param[in]  context         context passed to callback
 *  @param[in]  int_num         interrupt number
 *  @return     none
 */
void device_interrupt_cb(void * context, int int_num)
{
	switch(int_num)
	{
	case INV_DEVICE_IO_INTERRUPT:
		// Set data interrupt flag
		data_int_occured = true;
		break;
	case INV_DEVICE_TIMER_0_INTERRUPT:
		// Set watchdog interrupt flag
		watchdog_int_occured = true;
		break;
	default:
		break;     
	}
	
	// Avoid warning. We don't need this parameter for our function
	(void) context;
}


// We don't diagnostic "missing-field-initializer" for "device_settings" struct
// There are too much fields to initialize by lib and it's a nonsense to
// initialize all values in variable declaration
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

/**
 * Handle settings for easy device
 */
inv_easy_device_settings_t device_settings = 
{
	.interrupt_cb = device_interrupt_cb,
	.context      = NULL,
	.device       = NULL,
	.pserif       = NULL,
	.buffer       = device_buffer,
	.buffer_size  = sizeof(device_buffer),
	.icm30xxx       = {0},
	.sensor_listener = 
	{
		sensor_event_cb, /* callback that will receive sensor events */
		(void *)0xDEAD   /* some pointer passed to the callback */
	},
#ifdef ENABLE_FW_M0_PROG
	.fw_image_buffer        = flash_image,
	.fw_image_buffer_size   = sizeof(flash_image),
#else	
	.fw_image_buffer        = NULL,
	.fw_image_buffer_size   = 0,
#endif
	.dmp3_image_buffer      = dmp3_image,
	.dmp3_image_buffer_size = sizeof(dmp3_image),
	.dmp4_image_buffer      = dmp4_image,        
	.dmp4_image_buffer_size = sizeof(dmp4_image),
	
	.acc_gyr_mounting_matrix = {1.0, 0.0, 0.0,
	                            0.0, 1.0, 0.0,
	                            0.0, 0.0, 1.0},
	// Align mag axis with accel and gyro
	// Update this matrix if you mount a magnetometer with a different axis referential
	.mag_mounting_matrix     = {0.0, -1.0, 0.0,
	                            1.0, 0.0, 0.0,
	                            0.0, 0.0, 1.0},
};

#pragma GCC diagnostic pop // Now "missing-field-initializer" is tested


/** @brief Start sensor
 *  @return return code of driver function
 */
int start_sensor(void)
{
	int rc;
	
	// Start sensor at 20 Hz and data are bufferized for a maximum of 500 ms
	rc = inv_easy_device_start_sensor(&device_settings, INV_SENSOR_TYPE_UNCAL_GYROSCOPE, 1, 0);
	TEST_RC(rc);
  
  //rc = inv_easy_device_start_sensor(&device_settings, INV_SENSOR_TYPE_RAW_GYROSCOPE, 1, 0);
  //TEST_RC(rc);
  rc = inv_easy_device_start_sensor(&device_settings, INV_SENSOR_TYPE_ORIENTATION, 2, 0);
  TEST_RC(rc);
	
	return(rc);
}


/** @brief Stop sensor
 *  @return return code of driver function
 */
int stop_sensor(void)
{
	int rc;
	uint8_t i;
	
	// Stop sensor
	rc = inv_easy_device_stop_sensor(&device_settings, INV_SENSOR_TYPE_UNCAL_GYROSCOPE);
	TEST_RC(rc);
  //rc = inv_easy_device_stop_sensor(&device_settings, INV_SENSOR_TYPE_RAW_GYROSCOPE);
  //TEST_RC(rc);
  // Stop sensor
  rc = inv_easy_device_stop_sensor(&device_settings, INV_SENSOR_TYPE_ORIENTATION);
  TEST_RC(rc);
	
	// wait 500 ms for all data to be outputed
	for (i = 0; i < 100; i++)
	{
		rc = inv_device_poll(device_settings.device);
		inv_icm30xxx_sleep(5);
	}
	
	return rc;
}


/** @brief Init sensor
 *  @return Last return code of last driver function called
 */
int initSketch(void)
{
	int              rc;
	uint8_t          whoami;
	inv_fw_version_t fw_version;

	// Reset event counter
	event_count = 0;
	
	// Setup driver messages if you want to see device driver traces
	printTraces("Setup msg level as warning");
	inv_msg_setup(MSG_LEVEL, inv_msg_printer_arduino);
	
	// Device easy init
	printTraces("Easy device init");
	rc = inv_easy_device_init(&device_settings, &whoami, &fw_version);
	TEST_RC(rc);

	// Test who am i
#if defined (USE_ICM30630) || defined (USE_ICM30631)
	if(whoami != 0xC0)
#elif defined (USE_ICM30670)
	if((whoami != 0xC2) && (whoami != 0xC1))
#endif
	{
		// who am i incorrect
		rc = INV_ERROR_UNEXPECTED;
		printTraces("FAIL : Unexpected device who am i %x", whoami);
		return rc;
	} 
	
	// Set accel and gyro bias
	//rc = inv_device_set_sensor_bias(device_settings.device, INV_SENSOR_TYPE_ACCELEROMETER, acc_bias);
	//TEST_RC(rc);
	
	//rc = inv_device_set_sensor_bias(device_settings.device, INV_SENSOR_TYPE_GYROSCOPE, gyr_bias);
	//TEST_RC(rc);
	
	// Start sensor at 20 Hz and data are bufferized for a maximum of 500 ms
	rc = start_sensor();
	TEST_RC(rc);
	
	// Reset interrupt flags
	data_int_occured = false;
	watchdog_int_occured = false;
	
	return(rc);
}


/* Public function code ------------------------------------------------------*/


/** @brief Sleep implementation for Icm30xxx.
 *  @param[in]  ms  millisecond  of sleep
 *  @return     none
 */
void inv_icm30xxx_sleep(int ms)
{
	/*
	 * You must provide a sleep function that blocks the current programm
	 * execution for the specified amount of ms
	 */
	delay(ms);
}

/** @brief Arduino sketch setup function
 *  Called at init by Arduino Sketch
 *  @return     none
 */
void setup() 
{
	// Open native serial port through USB programming port (for debug purpose)
	SERIAL_TRACES.begin(230400); // Max speed for arduino monitor
	
	// Wait before starting example
	while(! SERIAL_TRACES); // Wait only on open of the native port
	
	// Init sketch
	printTraces("Sketch start");
	initSketch();
}

/** @brief Arduino sketch loop function
 *  called in loop by Arduino sketch
 *  @return     never
 */



void loop()
{
  /*t = (double)millis()*.001;
  del_t = t-t_;
  t_ = t;*/
  //del_t = 0.003;
  //del_t = 0.001;
  //psi = psi + (-0.065*(gyro_data[2]-.457)*1.5/100)*del_t;
/*  psi = psi + ((double)(gyro_data[2]))*del_t;
  //psi_scaled = psi*(-0.065)*1.5/100;
  
  SERIAL_TRACES.print("psi_int:  ");
  SERIAL_TRACES.print(psi);
  SERIAL_TRACES.print("  dt:  ");
  SERIAL_TRACES.print(del_t,6);
  
  SERIAL_TRACES.print("  GYRO:  ");
  SERIAL_TRACES.println(gyro_data[2],6);*/
  
  send_byte[0] = 0xbd; //start byte
  memcpy(&send_byte[1], eul_data, 12);
  memcpy(&send_byte[13],gyro_data,12);
  send_byte[25] = 0xff; //last byte */
  Serial.write(send_byte, 26); //send data over serial
	// Test if there is any char in buffer


	if(SERIAL_TRACES.available() == 0)
	{
		// Now, test if interrupt occured
		if(data_int_occured != false)
		{
			// Reset interrupt flag
			data_int_occured = false;
			
			// Interrupt occur poll device
			//printTraces("Poll device");
			inv_device_poll(device_settings.device);
		}
		
		// Test if watchdog needs to be polled
		if(watchdog_int_occured != false)
		{
			// Reset interrupt flag
			watchdog_int_occured = false;
		
#if defined (USE_ICM30670)
			// Check that device firmware is running properly
			if(inv_device_icm30670_watchdog_poll(&device_settings.icm30xxx) == INV_ERROR_WATCHDOG)
			{
				INV_MSG(INV_MSG_LEVEL_ERROR, "Watchdog error, device is in reset state");
				// Trap watchdog error
				while(1);
			}
#endif
		}
	}
	else
	{
		
		// Char in buffer Stop Sensor
		/*stop_sensor();
		printTraces("Sensor STOPPED !");
				
		// Empty serial buffer
		while(SERIAL_TRACES.available() != 0)
		{
			SERIAL_TRACES.read();
		}
		
		// Display restart info
		printTraces("Send a char for restarting sensor");
		while(SERIAL_TRACES.available() == 0);
		
		// Wait all incoming char
		delay(100); */
		
		 //Flush serial buffer
		while(SERIAL_TRACES.available() != 0)
		{
			SERIAL_TRACES.read();
		}
		
		//start_sensor();
   
	} 
}
