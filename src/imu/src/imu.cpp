#include "imu.h"


int nn = 4; // Number of states
int mm = 2; // Number of measurements

double dt_kalman = 1.0/390.0; // Time step

Eigen::MatrixXd A(nn, nn); // System dynamics matrix
Eigen::MatrixXd C(mm, nn); // Output matrix
Eigen::MatrixXd Q(nn, nn); // Process noise covariance
Eigen::MatrixXd R(mm, mm); // Measurement noise covariance
Eigen::MatrixXd P(nn, nn); // Estimate error covariance
KalmanFilter kf; 




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
    /*FD_ZERO(&read_fds);
    FD_SET(port, &read_fds);
    no_timeout.tv_sec  = 0;
    no_timeout.tv_usec = 0;
    int num_fds = select(port+1, &read_fds, NULL, NULL, &no_timeout);*/

    int a = -10;
    //No data ready to read
    //if(num_fds == 0)  {a = 2;}

    //select returned an error
    //else if(num_fds ==-1) { a = -3; }


	unsigned char sensor_bytes2[(this->data_size)]; //= {0.0};

	//lseek(port, -(this->data_size), SEEK_END);

	//read in 26 bytes of data from port to the address in memory &sensor_bytes2
	//result1 indicates success of reading
	//tcflush(port, TCIFLUSH);
	int result = read(port, &sensor_bytes2[0], data_size);


	timer.update();
		

	//check first and last byte
	if((sensor_bytes2[0] == 0xbd) && (sensor_bytes2[data_size-1] == 0xff) )
	{
	   unpack_data(imu_data, sensor_bytes2);
	   a=1;

	}else
	{
		if (result == -1) printf("get_imu_data: FAILED read from port \n");
		printf("\n\n\x1b[31mCHECK BYTES WRONG:FLUSHED PORT\x1b[0m\n\n");
		tcflush(port, TCIFLUSH);
		if(!(sensor_bytes2[0]== 0xbd))       {printf("FIRST BYTE WRONG%04x \x1b[0m\n\n", sensor_bytes2[0]); a=-5;}
		else if(!(sensor_bytes2[data_size-1] == 0xff)) {printf("LAST BYTE WRONG%04x \x1b[0m\n\n", sensor_bytes2[data_size-1]); a=-6;}
		else a = -1;
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
		float acc[3] = {0.0};
        float att_vel[3] = {0.0};
        float x_corr, y_corr, z_corr, a_corr;
        /*att_vel[0]         = *(int32_t *)&arr[13]; //printf("att_vel 1: %i \n", att_vel[0]);
        att_vel[1]         = *(int32_t *)&arr[17]; //printf("att_vel 2: %i \n", att_vel[1]);
        att_vel[2]         = *(int32_t *)&arr[21]; //printf("att_vel 3: %i \n", att_vel[2]);*/
        att_vel[0]         = *(float *)&arr[17]; //printf("att_vel 1: %i \n", att_vel[0]);
        att_vel[1]         = *(float *)&arr[21]; //printf("att_vel 2: %i \n", att_vel[1]);
        att_vel[2]         = *(float *)&arr[25]; //printf("att_vel 3: %i \n", att_vel[2]);
        
        uint32_t pressure_data = *(uint32_t * )&arr[29];
        imu_data.altitude_raw = (float)pressure_data;
        
        
        imu_data.acc_x = *(float *)&arr[33];
        imu_data.acc_y = *(float *)&arr[37];
        imu_data.acc_z = *(float *)&arr[41];
        
        //imu_data.acc_z = (imu_data.acc_z * -9.81) ;
        
        //printf("acc_z : %f \n",imu_data.acc_z);

        imu_data.phi_dot   = -att_vel[1];
        imu_data.theta_dot = -att_vel[0];
        imu_data.psi_dot   = -att_vel[2];
        
        //printf("psi_dot: %f \n", imu_data.psi_dot);

        imu_data.psi_magn_raw     = *(float *)&arr[1]; //printf("psi 1: %f \n", imu_data.psi);
        imu_data.theta     = *(float *)&arr[5]; //printf("theta 1: %f \n", imu_data.theta)state2rawBytes(imu_data);
        imu_data.phi       = *(float *)&arr[9]; //printf("phi 1: %f \n", imu_data.phi);
        
        imu_data.quat[0] = *(float *)&arr[1];
        imu_data.quat[1] = *(float *)&arr[5];
        imu_data.quat[2] = *(float *)&arr[9];
        imu_data.quat[3] = *(float *)&arr[13];
        
        imu_data.acc_x = imu_data.acc_x * 9.80665;
        imu_data.acc_y = imu_data.acc_y * 9.80665;
        imu_data.acc_z = imu_data.acc_z * 9.80665;
        
        //correction factor for accelerometer z reading based on tilt of quadrotor
        /*x_corr = sin(imu_data.phi * PI / 180.0);
        y_corr = sin(imu_data.theta * PI / 180.0);
        z_corr = sqrt((x_corr*x_corr) + (y_corr*y_corr));
        a_corr = sqrt(1 - (z_corr*z_corr));
        //printf("acc_z : %f \n",imu_data.acc_z);
        imu_data.acc_z = imu_data.acc_z - a_corr ;
        
       // printf("acc_corr: %f \n", a_corr);
        imu_data.acc_z = imu_data.acc_z * 9.80665 -.36;*/
        
        Eigen::VectorXd accel_meas(3);
        accel_meas << imu_data.acc_x , imu_data.acc_y , imu_data.acc_z;
        //cout << "accel_meas: " << accel_meas << endl;
        
       
        
        Eigen::Matrix3d rotm;
         	    
        Eigen::AngleAxisd yawAngle(-imu_data.psi*M_PI/180 + M_PI/2 , Eigen::Vector3d::UnitZ());
        Eigen::AngleAxisd pitchAngle(imu_data.theta*M_PI/180 , Eigen::Vector3d::UnitX());
        Eigen::AngleAxisd rollAngle(imu_data.phi*M_PI/180 + M_PI , Eigen::Vector3d::UnitY());
        Eigen::Quaternion<double> q =  pitchAngle * rollAngle * yawAngle;
        rotm = q.matrix().transpose();
        //cout <<"rotm = "<< rotm << endl;
        Eigen::Vector3d grav_vector;
        grav_vector << 0.0 , 0.0 , 9.80655;
        Eigen::Vector3d accel_inertial = rotm * accel_meas - grav_vector;
        //cout << "accel_inertial = " << accel_inertial.transpose() << endl;
        
        imu_data.acc_z = accel_inertial(2);
        
      /*  acc[0] = *(float *)&arr[1]; //x
        acc[1] = *(float *)&arr[5]; //y
        acc[2] = *(float *)&arr[9]; //z */
	
		
        imu_data.numPsiRot = p.getIter();
    
    
        imu_data.dt = timer.getDt();

	
     //CALIBRATED

        imu_data.psi_magn_continuous  =  p.make_contin(imu_data.psi_magn_raw);
 	
 	//float pitchAcc,rollAcc,accMag;
	
	if((this->calibrated)) 
	  {
	    //printf("Psi Freq: %f, Cal Psi_dot: %f, Uncal Psi_dot: %f, bias.psi_dot %f, Psi update out: %f, Psi returned: %f \n", 1/timer.getDt(), imu_data.psi_dot_cal, imu_data.psi_dot, bias.psi_dot, gyroEstimate.updatePsi(imu_data.psi_dot_cal), gyroEstimate.getPsi() );

	    //gyroEstimate.updatePsi(imu_data.psi_dot_cal);
	    //printf("Psi dt: %f, Psi freq: %f \n",  gyroEstimate.getDt(),  1/gyroEstimate.getDt());
	    //pg->setDt(timer.getDt());
		
		/*accMag = abs(acc[0]) + abs(acc[1]) + abs(acc[2]);
		printf("accMag[0]: %f     accMag[1]: %f        accMag[2]: %f \n", abs(acc[0]), abs(acc[1]), abs(acc[2]));
		pitchAcc = atan2f(acc[1],acc[2]) * 180 / 3.14;
		rollAcc = atan2f(acc[0],acc[2]) * 180 / 3.14;*/
		
	    imu_data.psi_gyro_integration = gyroEstimate.getPsi();
	   
	    imu_data.phi_dot_cal    =  imu_data.phi_dot    - bias.phi_dot;
	    imu_data.psi_dot_cal    =  imu_data.psi_dot    - bias.psi_dot;
	    imu_data.theta_dot_cal  =  imu_data.theta_dot  - bias.theta_dot;
	    imu_data.psi_magn_continuous_calibrated =  imu_data.psi_magn_continuous  - bias.psi_magn_continuous;
  	    gyroEstimate.updatePsi(imu_data.psi_dot_cal);
  	    imu_data.psi = imu_data.psi_magn_continuous_calibrated;
  	    imu_data.altitude_calibrated = -HEIGHT_SCALE*log((imu_data.altitude_raw - bias.altitude_raw + P_SEA)/P_SEA); //relative height in meters from start point
  	    imu_data.barometer = imu_data.altitude_calibrated;
  	    
  	 	//update kalman state
  	    Eigen::VectorXd y(mm);
  	    y << imu_data.altitude_calibrated, imu_data.acc_z;
  	    kf.update(y);
  	    //cout << " x_hat = " << kf.state().transpose() << endl; 
  	    Eigen::VectorXd currState = kf.state();
  	    imu_data.altitude_calibrated = currState(0);
  	    
  	    

	  }

}



int main(int argc, char** argv){

std::string path = "/dev/ttyACM0";
Imu imu = Imu(path, 46, .00112);
State new_data = {0.0};

ros::init(argc,argv,"imu");
ros::NodeHandle nh;
ros::Publisher imu_pub;

imu_pub = nh.advertise<quad_msgs::ImuData>("imu/imu_data",1); 
//int cal = imu.calibrate();
float psi_t = 0;
int suc = 0;
int cal = imu.calibrate();

A << 1, (dt_kalman*dt_kalman)/2, dt_kalman, -(dt_kalman*dt_kalman)/2 ,         .0, 1.0, .0, -1.0,       .0, dt_kalman, 1.0,  -dt_kalman,         .0 , .0, .0, 1.0 ;
C << 1, 0, 0, 0, 0, 1, 0 , 0;

/*Q << .0001, .0, .0, 0, 1000, .0, .0, .0, .001;
R << 1000, 0, 0, .0001; 
P << 1, 0, 0, 0, 1, 0, 0, 0, 1; */

Q << 10.0, .0, .0, .0,    .0, 1e8, .0, .0,       .0, .0, 10, .0,      .0, .0, .0, .01;
R << 7e5, 0, 0, 1e-4; 
P << 10, .0, .0, .0,      .0, 1000, .0, .0,      .0, .0, 10, .0,      .0, .0, .0, 1;

kf = KalmanFilter(dt_kalman,A, C, Q, R, P);

Eigen::VectorXd x0(nn);
x0 << 0, 0, 0, imu.bias.acc_z ;
kf.init(dt_kalman,x0); 

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
		quad_msgs::ImuData imuMsg;
		imuMsg.header.stamp = ros::Time::now();
		imuMsg.phi = new_data.phi;
		imuMsg.theta = new_data.theta;
		imuMsg.psi =  new_data.psi_gyro_integration;
		imuMsg.phi_dot = new_data.phi_dot_cal;
		imuMsg.theta_dot = new_data.theta_dot_cal;
		imuMsg.psi_dot = new_data.psi_dot_cal;
		imuMsg.psi_gyro_integration = new_data.psi_gyro_integration;
		imuMsg.dt = new_data.dt;
		imuMsg.succ_read = new_data.succ_read;
		imuMsg.altitude = new_data.altitude_calibrated;
		imuMsg.barometer = new_data.barometer;
		imuMsg.acc_z = new_data.acc_z;
		imuMsg.quat[0] = new_data.quat[0];
		imuMsg.quat[1] = new_data.quat[1];
		imuMsg.quat[2] = new_data.quat[2];
		imuMsg.quat[3] = new_data.quat[3];
		                              
		                               
		
			
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

