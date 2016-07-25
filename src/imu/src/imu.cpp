#include "imu.h"

//g++ imu.cpp logger.cpp utility.cpp -I ../include -std=c++11

int Imu::get_imu_calibrated_data(State& imu_data){
//identical to get_imu__data, but return calibrated values instead
        //get_raw_data
		
		imu_data.succ_read = -1;
        imu_data.succ_read = get_imu_data(imu_data);

        if(!(this->calibrated)) {printf( "WARNING: RETURNING CALIBRATED IMU VALUES BEFORE PERFORMING CALIBRATION");}
        
	//if successfuly recieved data, subtract off bias
        if(imu_data.succ_read==1 && (this ->calibrated))
        {
        	
        	//imu_data.phi_dot    = imu_data.phi_dot_cal;
        	//imu_data.theta_dot = imu_data.theta_dot_cal;
        	//imu_data.psi_dot   = imu_data.psi_dot_cal;
        	//imu_data.psi	   = imu_data.psi_gyro_integration;


/*

				//subtract bias
                imu_data.phi_dot   += - gyro_bias.phi_dot;
                imu_data.theta_dot += - gyro_bias.theta_dot;
                imu_data.psi_dot   += - gyro_bias.psi_dot;

                imu_data.psi                  += - gyro_bias.psi;
                imu_data.psi_gyro_integration += - gyro_bias.psi_dot*(this->dt); //may have to use pg object
*/  
      } 

	return imu_data.succ_read;

}
int Imu::get_imu_data(State& imu_data)
{
//select: clear read_ds(set of file_descriptors to watch for reading), add port to this set, set time to 0 to returnimmediately,
    // select returns the number of fd's ready
    FD_ZERO(&read_fds);
    FD_SET(port, &read_fds);
    no_timeout.tv_sec  = 0;
    no_timeout.tv_usec = 0;
    int num_fds = select(port+1, &read_fds, NULL, NULL, &no_timeout);

    int a = -10;
    //No data ready to read
    if(num_fds == 0)  {a = 2;}

    //select returned an error
    else if(num_fds ==-1) { a = -3; }

    //A file descriptor is ready to read: check which one
    else if(FD_ISSET(port , &read_fds))
         {
		unsigned char sensor_bytes2[(this->data_size)]; //= {0.0};

		lseek(port, -(this->data_size), SEEK_END);

		//read in 26 bytes of data from port to the address in memory &sensor_bytes2
		//result1 indicates success of reading
		int result = read(port, &sensor_bytes2[0], data_size);

		//track dt between reads
		/*clock_gettime(CLOCK_REALTIME,&newT);
		(this->calc_dt) = UTILITY::timespec2float(UTILITY::time_diff(oldT, newT));
		clock_gettime(CLOCK_REALTIME,&oldT);*/
		timer.update();
		
		//printf("%i\n",a);
		
		



                //check first and last byte
                if((sensor_bytes2[0] == 0xbd) && (sensor_bytes2[data_size-1] == 0xff) ){
                    unpack_data(imu_data, sensor_bytes2);
                    a=1;
		    //                    a = imu_check(imu_data);
                }else{
                    if (result == -1) printf("get_imu_data: FAILED read from port \n");
                    printf("\n\n\x1b[31mCHECK BYTES WRONG:FLUSHED PORT\x1b[0m\n\n");
                    tcflush(port, TCIFLUSH);
                    if(!(sensor_bytes2[0]== 0xbd))       {printf("FIRST BYTE WRONG%04x \x1b[0m\n\n", sensor_bytes2[0]); a=-5;}
                    else if(!(sensor_bytes2[25] == 0xff)) {printf("LAST BYTE WRONG%04x \x1b[0m\n\n", sensor_bytes2[25]); a=-6;}
                    else a = -1;
                }
         }

	return a;
}
void Imu::unpack_data(State& imu_data, const unsigned char arr[])
{
//distributes data from the input buffer to the imu_data data structure
//we make a char[] to recieve imu data (imu outputs byte by byte)
//the cast to a float pointer takes the first four bytes in the array 'arr',
//thus constructing a float

     //RAW VALUES
        float att_vel[3] = {0.0};
        /*att_vel[0]         = *(int32_t *)&arr[13]; //printf("att_vel 1: %i \n", att_vel[0]);
        att_vel[1]         = *(int32_t *)&arr[17]; //printf("att_vel 2: %i \n", att_vel[1]);
        att_vel[2]         = *(int32_t *)&arr[21]; //printf("att_vel 3: %i \n", att_vel[2]);*/
        att_vel[0]         = *(float *)&arr[13]; //printf("att_vel 1: %i \n", att_vel[0]);
        att_vel[1]         = *(float *)&arr[17]; //printf("att_vel 2: %i \n", att_vel[1]);
        att_vel[2]         = *(float *)&arr[21]; //printf("att_vel 3: %i \n", att_vel[2]);

        imu_data.phi_dot   = -att_vel[1];
        imu_data.theta_dot = -att_vel[0];
        imu_data.psi_dot   = -att_vel[2];
        
        //printf("psi_dot: %f \n", imu_data.psi_dot);

        imu_data.psi_magn_raw     = *(float *)&arr[1]; //printf("psi 1: %f \n", imu_data.psi);
        imu_data.theta     = *(float *)&arr[5]; //printf("theta 1: %f \n", imu_data.theta)state2rawBytes(imu_data);
        imu_data.phi       = *(float *)&arr[9]; //printf("phi 1: %f \n", imu_data.phi);
	//make psi continuos here
		
	imu_data.numPsiRot = p.getIter();
    
    
	imu_data.dt = timer.getDt();

     //CALIBRATED

 	imu_data.psi_magn_continuous  =  p.make_contin(imu_data.psi_magn_raw);
	
	if((this->calibrated)) 
	  {
	    //printf("Psi Freq: %f, Cal Psi_dot: %f, Uncal Psi_dot: %f, bias.psi_dot %f, Psi update out: %f, Psi returned: %f \n", 1/timer.getDt(), imu_data.psi_dot_cal, imu_data.psi_dot, bias.psi_dot, gyroEstimate.updatePsi(imu_data.psi_dot_cal), gyroEstimate.getPsi() );

	    //gyroEstimate.updatePsi(imu_data.psi_dot_cal);
	    //printf("Psi dt: %f, Psi freq: %f \n",  gyroEstimate.getDt(),  1/gyroEstimate.getDt());
	    //pg->setDt(timer.getDt());
		
		
		
	    imu_data.psi_gyro_integration = gyroEstimate.getPsi();
	   
	    imu_data.phi_dot_cal    =  imu_data.phi_dot    - bias.phi_dot;
	    imu_data.psi_dot_cal    =  imu_data.psi_dot    - bias.psi_dot;
	    imu_data.theta_dot_cal  =  imu_data.theta_dot  - bias.theta_dot;
	    imu_data.psi_magn_continuous_calibrated =  imu_data.psi_magn_continuous  - bias.psi_magn_continuous;
  	    gyroEstimate.updatePsi(imu_data.psi_dot_cal);
  	    imu_data.psi = imu_data.psi_magn_continuous_calibrated;
	    
	    // imu_data.altitude_calibrated = imu_data.altitude_raw - bias.altitude_raw;

	  }

}



int main(int argc, char** argv){

std::string path = "/dev/ttyACM0";
Imu imu = Imu(path, 26, .00112);
State new_data = {0.0};

//int cal = imu.calibrate();
//logging 
/*std::string log_filename = "file.txt";
logger logger(log_filename, 100, true);
Data_log d;*/
ros::init(argc,argv,"imu");
ros::NodeHandle n;
ros::Publisher imu_pub;

imu_pub = n.advertise<imu::ImuData>("imu/imu_data",1); 
//int cal = imu.calibrate();
float psi_t = 0;
int suc = 0;
int cal = imu.calibrate();
while(ros::ok())
{
	
	//begin = ros::Time::now().toSec();
	////int suc = imu.get_imu_calibrated_data(imu_data);
	 suc = imu.get_imu_calibrated_data(new_data);
	
	/*psi_t = psi_t + new_data.dt * new_data.psi_dot_cal*.0065;
	printf("test psi = %f \n",psi_t);*/
	if(suc == 1)
	{       
		//printf("imu_data.psi = %f \n", imu_data.psi);
		imu::ImuData imuMsg;
		imuMsg.phi = new_data.phi;
		imuMsg.theta = new_data.theta;
		imuMsg.psi =  new_data.psi_gyro_integration;
		imuMsg.phi_dot = new_data.phi_dot_cal;
		imuMsg.theta_dot = new_data.theta_dot_cal;
		imuMsg.psi_dot = new_data.psi_dot_cal;
		imuMsg.psi_gyro_integration = new_data.psi_gyro_integration;
		imuMsg.dt = new_data.dt;
		imuMsg.succ_read = new_data.succ_read;
		imu_pub.publish(imuMsg);
		//end = ros::Time::now().toSec();
		//printf("%f \n" , end-begin);

	} else if (suc == 2) {
	  //printf("suc = %i \n",suc);
		//imu::ImuData imuMsg;
		//imuMsg.succ_read = new_data.succ_read;
		//imu_pub.publish(imuMsg);
	}
	
	
}
 return 1;
}

