#include "motor_test_1.h"
//g++ motor_test_1.cpp -I ../../include/motor_test -std=c++11
//need sudo to run exec
//#define MOTOR_PATH "/dev/i2c-10"  //may have to do this instead of passing in!

#define MOTORS_OFF 870
#define MOTORS_FULL 1550


motor::motor(){};

motor::motor(uint8_t motor_id, uint8_t i2c_handle, uint8_t i2c_address)
{
    printf("Motor object is being created, motor = %i \n", motor_id);
    motorId_ = motor_id;
    i2cHandle_ = i2c_handle;
    i2cAddress_ = i2c_address;
    send_force_i2c(0,MOTORS_OFF);

    
}


void motor::write8(uint8_t addr, uint8_t d, uint8_t handle)
{

          uint8_t data[2];
          data[0] = addr;
          data[1] = d;
          if(write(handle,data,2)!= 2)     printf("error using write8 \n");
          else                             printf("success using write8 \n");

}

uint8_t motor::read8(uint8_t addr, uint8_t handle)
{
          uint8_t buf[2];
          buf[1] = addr;
          if(write(handle,buf,1) != 1) printf("error when trying to set read register");

          if(read(handle,buf,1) != 1)  printf("failed to read from i2c bus");
          return buf[1];
}

uint8_t motor::open_motors_i2c(std::string PATH2MOTOR, uint8_t addr, float freq)
{
        printf("opening i2c port...\n");
        uint8_t handle = open(PATH2MOTOR.c_str(),O_RDWR);

        if (handle > 0) printf("Done!: file descriptor: %i \n",handle);
        else            printf("Fail to open port \n");
        ioctl(handle, I2C_SLAVE, addr); // set slave address    

        //write8(PCA9685_MODE1, 0x0); // this is reset in motordriver.cpp

        uint8_t data[2];
        data[0] = PCA9685_MODE1;
        data[1] = 0x0;
        if(write(handle,data,2)!= 2) printf("error in resetting chip \n");
        else                                printf("success in ressetting chip \n");

        freq *= 0.9;  // Correct overshoot in the frequency setting (see issue #11).
        float prescaleval = 25000000;
        prescaleval /= 4096;
        prescaleval /= freq;
        prescaleval -= 1;
        uint8_t prescale = floor(prescaleval + 0.5);

        uint8_t oldmode = read8(PCA9685_MODE1, handle);
        uint8_t newmode = (oldmode&0x7F) | 0x10; // sleep
        motor::write8(PCA9685_MODE1,     newmode,     handle); // go to sleep
        motor::write8(PCA9685_PRESCALE, prescale,    handle); // set the prescaler
        motor::write8(PCA9685_MODE1,    oldmode,     handle);
        usleep(5000);
        motor::write8(PCA9685_MODE1, oldmode | 0xa1, handle);

        return handle;
}
void motor::send_force_i2c(uint16_t on, uint16_t off) {

        //NEED TO USE IDENTIFIER FOR THE MOTOR: channel id's the motor 0-3
        uint8_t buf[5];
        buf[0] = LED0_ON_L + 4*motorId_;
        buf[1] = on;
        buf[2] = on >> 8;
        buf[3] = off;
        buf[4] = off >> 8;
        write(i2cHandle_,buf,5);
/*	if(first_call)
    	{
        	first_call = false;
        	clock_gettime(CLOCK_REALTIME,&oldT);
   	}
	calcDt(oldT,newT);
	*/
}

int motor::send_motor_data(uint16_t on, uint16_t off)
{
  /*  // select returns the number of fd's ready
    FD_ZERO(&write_fds);
    FD_SET(i2cHandle_, &write_fds);
    no_timeout.tv_sec  = 0;
    no_timeout.tv_usec = 0;

   int num_fds = select(i2cHandle_+1, NULL, &write_fds, NULL, &no_timeout);
   int returnval = 0;

   //printf("returnval in select: %i \n\n\n", num_fds);

 //No data ready to read 
        if(num_fds == 0)
        {
                returnval= -1;
		printf("No File_Descriptor Available to write! \n");
                return -1;
        }
        //select returned an error 
        else if(num_fds ==-1)
        {
                returnval= -2;
                return -2;
        }
        else if(num_fds ==1)
        {
                //channel/motor_id tells us which motor should get signal. On/Off is the pwm frequency. Need to map this from origianl (0-255) to new (700-???)
	  // printf("file descriptor ready to write! \n");
		send_force_i2c(on,off);//on, off);
                returnval = num_fds;
        }


        return returnval;
        */
}
void motor::set_force( int force_in)
{
	force_ = force_in;

}
int motor::get_force( void )
{
	return force_;
}

/*int motor::ensure_valid_force(int force_in)
{
        //check if requested force of this motor is in the acceptable bounds
        // if not cap it at the max/min
        if(force_in > max_force) {return max_force;}
        if(force_in < min_force) {return min_force;}
        return force_in;
	}*/


//timer functions 
float motor::calcDt(timespec& oldT, timespec& newT)
{
                //track dt between reads
                clock_gettime(CLOCK_REALTIME, &newT);
                float dt = UTILITY::timespec2float(UTILITY::time_diff(oldT, newT));
                clock_gettime(CLOCK_REALTIME ,&oldT);
		calc_dt = dt;
                return dt;
}

float motor::getDt(void)
{
                return this->calc_dt;
}

float motor::timeSinceLastRead(void)
{
		
		timespec currentTime;
                clock_gettime(CLOCK_REALTIME,&currentTime);
                //printf("xbee time %f \n",UTILITY::timespec2float(UTILITY::time_diff(this->oldT, currentTime)));
                return UTILITY::timespec2float(UTILITY::time_diff(this->oldT, currentTime));

}

//map values from 0-255 to 900-1550 returns a uint16_t to be passed to sned_motor_data parameter "on"

uint16_t motor::map_values(double force){
	int min = 880;
	int max = 1550;
	int val = (int)round((min + ((max-min)*force)/255));
	if (val < min) {val = min;}
	else if(val > 1550){val = 1550;}
	return (uint16_t)val;
}


Motors::Motors(uint8_t i2c_handle, uint8_t i2c_address){
	m0 = motor(0,i2c_handle,i2c_address);
	m1 = motor(1,i2c_handle,i2c_address);
	m2 = motor(2,i2c_handle,i2c_address);
	m3 = motor(3,i2c_handle,i2c_address);
	cmdSub_ = n.subscribe<quad_msgs::MotorCommands>("/controller/cmd_motors",3,&Motors::cmdCallBack,this);
	ROS_INFO("successfully created Motors\n");
	i2cHandle_ = i2c_handle;
}

void Motors::cmdCallBack(const quad_msgs::MotorCommands::ConstPtr& cmdMsg){
	/*if(motorId_ == 0){
	  //ROS_INFO("I recieved %f\n",cmdMsg->m0);
		send_force_i2c(0,motor::map_values((uint16_t)cmdMsg->m0));
	} else if(motorId_ == 1) {
	  //ROS_INFO("I recieved %f\n",cmdMsg->m1);
		send_force_i2c(0,motor::map_values((uint16_t)cmdMsg->m1));
	} else if(motorId_ == 2) {
	  //	ROS_INFO("I recieved %f\n",cmdMsg->m2);
		send_force_i2c(0,motor::map_values((uint16_t)cmdMsg->m2));
	} else if (motorId_ == 3){
	  //	ROS_INFO("I recieved %f\n",cmdMsg->m3);
		send_force_i2c(0,motor::map_values((uint16_t)cmdMsg->m3));
	} 
	return; */
	//ros::Time start = ros::Time::now();
	m0.set_force(motor::map_values(cmdMsg->m0));
	m1.set_force(motor::map_values(cmdMsg->m1));
	m2.set_force(motor::map_values(cmdMsg->m2));
	m3.set_force(motor::map_values(cmdMsg->m3));
	write_motors = true;
	/*m0.send_force_i2c(0,motor::map_values(cmdMsg->m0));
	m1.send_force_i2c(0,motor::map_values(cmdMsg->m1));
	m2.send_force_i2c(0,motor::map_values(cmdMsg->m2));
	m3.send_force_i2c(0,motor::map_values(cmdMsg->m3));*/
	
	//ros::Time end = ros::Time::now();
	//ros::Duration dur = end - start;
	//double freq = 1/(dur.toSec());
	//printf("freq: %f \n", freq);
	return;
}
void Motors::send_motor_forces() {
	uint8_t buf[20];
	buf[0] = LED0_ON_L + 4*0;
	buf[1] = 0;
	buf[2] = 0;
	buf[3] = m0.get_force();
	buf[4] = m0.get_force() >> 8;
	buf[5] = LED0_ON_L + 4*1;
	buf[6] = 0;
	buf[7] = 0;
	buf[8] = m1.get_force();
	buf[9] = m1.get_force() >> 8;
	buf[10] = LED0_ON_L + 4*2;
	buf[11] = 0;
	buf[12] = 0;
	buf[13] = m2.get_force();
	buf[14] = m2.get_force() >> 8;
	buf[15] = LED0_ON_L + 4*3;
	buf[16] = 0;
	buf[17] = 0;
	buf[18] = m3.get_force();
	buf[19] = m3.get_force() >> 8;
	
	
	
	write(i2cHandle_,buf,20);
	
}
int main(int argc, char** argv)
{

  std::string PATH2MOTOR = "/dev/i2c-1";
  uint8_t handle;
  handle =  motor::open_motors_i2c(PATH2MOTOR, 0x40, 200);
  
  //init ros 
  ros::init(argc,argv,"motors");

  
  Motors motors = Motors(handle,0x40);
  
  int motors_off;
  ros::Time start;
  //motors.n.setParam("all_off",0);
  double freq = 0;
  while(ros::ok())
  {
	 /* motors.n.getParam("all_off",motors_off);
	  if(motors_off == 1){
		  motors.m0.send_force_i2c(0,MOTORS_OFF);
		  motors.m1.send_force_i2c(0,MOTORS_OFF);
		  motors.m2.send_force_i2c(0,MOTORS_OFF);
		  motors.m3.send_force_i2c(0,MOTORS_OFF);
		  while(motors_off == 1){ motors.n.getParam("all_off",motors_off); }
  
	  }*/
	  if(write_motors == false) start = ros::Time::now();
	  ros::spinOnce();
	  
	  if(write_motors == true)
	  {
		  
		  motors.m0.send_force_i2c(0,motors.m0.get_force());
		  motors.m1.send_force_i2c(0,motors.m1.get_force());
		  motors.m2.send_force_i2c(0,motors.m2.get_force());
		  motors.m3.send_force_i2c(0,motors.m3.get_force());
		  //motors.send_motor_forces();
		  write_motors = false;
		  ros::Time end = ros::Time::now();
		  ros::Duration dur = end - start;
		  freq = 1/(dur.toSec());
		  //ROS_INFO("freq: %f \n", freq);
		  if(freq < 500) ROS_WARN("frequency below 500: %f \n ", freq);
		  
	  }
	  
  }
  
  ROS_INFO("EXITING MOTOR NODE AND SHUTTING OFF MOTORS\n");
  motors.m0.send_force_i2c(0,MOTORS_OFF);
  motors.m1.send_force_i2c(0,MOTORS_OFF);
  motors.m2.send_force_i2c(0,MOTORS_OFF);
  motors.m3.send_force_i2c(0,MOTORS_OFF);
  
  

 }
 
  
  
