#include "controller.h"
//g++ controller.cpp imu.cpp sonar.cpp xbee1.cpp vicon.cpp motor.cpp logger.cpp utility.cpp -I ../include -lpthread -lncurses -lboost_system -std=c++11
//initialize process-scoped data-structures

Times times;
Times time_m;
Times times_display;

Positions init_positions = {0.0};
Positions desired_positions = {0.0};


Gains gains= {0.0};
Control_command U_trim = {0};

State imu_error = {0};
Control_command U = {0};
Angles desired_angles = {0};
uint8_t joystick_thrust = 0;
uint8_t flight_mode = 0;

double* motor_commands;

bool MAGN = false;
bool SYSTEM_RUN = true;
bool CONTROLLER_RUN = false;
bool ESTOP = false;
bool XConfig = true;
bool AUTO_HEIGHT = false;
bool DISPLAY_RUN = false;
bool LOG_DATA = false;
bool DEBUG = false;

int i2cHandle, usb_imu_ivn, usb_xbee;
uint16_t display_count=0;
bool SONAR_BUBBLE_SIDES = false;
bool SONAR_BUBBLE_DOWN = false;
bool SONAR_BUBBLE_UP = false;
bool KILL_MOTORS = false;



int VICON_OR_JOY = 0; // 1 = VICON, 0 = JOYSTICK, 2 = both


int new_xbee_data = 0;
float new_sonar_data_x_pos, new_sonar_data_x_neg, new_sonar_data_y_pos, new_sonar_data_y_neg, new_sonar_data_down, new_sonar_data_up;

void gainsCallback(controller::controllerConfig &config, uint32_t level) {
  //dynamic reconfig callback
  gains.kp_phi = config.kp_phi;
  gains.kd_phi = config.kd_phi;

  gains.kp_theta = config.kp_theta;
  gains.kd_theta = config.kd_theta;

  gains.kp_psi = config.kp_psi;
  gains.kd_psi = config.kd_psi;
  
  gains.kp_x = config.kp_x;
  gains.kd_x = config.kd_x;
  gains.ki_x = config.ki_x;

  gains.kp_y = config.kp_y;
  gains.kd_y = config.kd_y;
  gains.ki_y = config.ki_y;
  U_trim.roll_acc = config.U_trim_roll_acc;
  U_trim.pitch_acc = config.U_trim_pitch_acc;
  U_trim.yaw_acc = config.U_trim_yaw_acc;
  ROS_INFO("kp_phi: %f, kd_phi: %f, kp_theta: %f, kd_theta:%f, kp_psi:%f, kd_psi:%f \n",gains.kp_phi,gains.kd_phi,gains.kp_theta,gains.kd_theta,gains.kp_psi,gains.kd_psi);
}




void sonarCallback(const quad_msgs::SonarData::ConstPtr& sonarMsg){
	new_sonar_data_x_pos = sonarMsg->x_pos;
	new_sonar_data_x_neg = sonarMsg->x_neg;
	new_sonar_data_y_pos = sonarMsg->y_pos;
	new_sonar_data_y_neg = sonarMsg->y_neg;
	new_sonar_data_up = sonarMsg->up;
	new_sonar_data_down = sonarMsg->down;
	//ROS_INFO("got x_pos %f", new_sonar_data_x_pos);
	
}

void imuCallback(const quad_msgs::ImuData::ConstPtr& imuMsg){
	if(imuMsg->succ_read < 0) {
		KILL_MOTORS = true; 
		return;
	}
	new_imu_data.theta = imuMsg->theta;
	new_imu_data.phi = imuMsg->phi;
	
	new_imu_data.psi = imuMsg->psi_gyro_integration;
	new_imu_data.theta_dot = imuMsg->theta_dot;
	new_imu_data.phi_dot = imuMsg -> phi_dot;
	new_imu_data.psi_dot = imuMsg -> psi_dot;
	return;
	//new_imu_data.psi_gyro_integration = imuMsg ->psi_gyro_integration;
	//printf("imu theta: %f \n",new_imu_data.theta);
	
}
void xbeeCallback(const quad_msgs::XbeeData::ConstPtr& xbeeMsg){
	desired_angles.phi = xbeeMsg->joy_des_angles[0];
	desired_angles.theta = xbeeMsg->joy_des_angles[1];
	desired_angles.psi = xbeeMsg->joy_des_angles[2];
	joystick_thrust = xbeeMsg->joy_thrust;
	flight_mode = xbeeMsg->flight_mode;
	if(flight_mode < 11) {KILL_MOTORS = true;}
	else {KILL_MOTORS = false;}
	
	return;
}

void *control_stabilizer(void *thread_id)
{

 
  printf("in control stabilizer \n");
  U_trim.thrust = 10;
  ros::NodeHandle nh;
  //ros::Publisher cmd_pub;
  ros::Subscriber sonar_sub;
  ros::Subscriber imu_sub;
  ros::Subscriber xbee_sub;
  //cmd_pub = nh.advertise<quad_msgs::MotorCommands>("controller/cmd_motors",1); 
  sonar_sub = nh.subscribe<quad_msgs::SonarData>("sonar/sonar_data",1,sonarCallback); 
  imu_sub = nh.subscribe<quad_msgs::ImuData>("imu/imu_data",1,imuCallback);
  xbee_sub = nh.subscribe<quad_msgs::XbeeData>("xbee/xbee_cmds",1,xbeeCallback); 
  
  dynamic_reconfigure::Server<controller::controllerConfig> server;
  dynamic_reconfigure::Server<controller::controllerConfig>::CallbackType f;

  f = boost::bind(&gainsCallback, _1, _2);
  server.setCallback(f);

  ros::Time start;
  ros::Time end;
  ros::Duration dur;
  
  //ros::AsyncSpinner spinner(6); // Use 4 threads
  //spinner.start();
  double freq;



  Distances sonar_distances;
  Distances repulsive_forces;
  State_Error vicon_error = {0.0};
  Vicon desired_velocity = {0.0}; 
   

  times.delta.tv_nsec = delta_time; //500000;



  if(DEBUG){
    nh.setParam("m0_cmd",700);
    nh.setParam("m1_cmd",700);
    nh.setParam("m2_cmd",700);
    nh.setParam("m3_cmd",700);
  } 
  

	
while(ros::ok()) 
  {
	start = ros::Time::now();

	if (VICON_OR_JOY == 1)
	{
		printf("in vicon part");

		if(new_xbee_data)
		{
			//calculate error from vicon
			//xbee.error_vicon(vicon_error, desired_velocity, desired_positions);	
		
			//calculate desired attitude (phi theta phi) in desired_angles
			desired_angles_calc(desired_angles, vicon_error, gains);

		}
	}	
	else
	{
		Angles old_desired_angles = desired_angles;

		ros::spinOnce();
		
		/*if(KILL_MOTORS){
			quad_msgs::MotorCommands mcs;
			mcs.m0 = 0;
			mcs.m1 = 0;
			mcs.m2 = 0;
			mcs.m3 = 0;
			cmd_pub.publish(mcs);
			ROS_INFO("KILLING MOTORS: KILL_MOTORS = true\n");
			
		}*/
		
		/*if(new_xbee_data < 0) ; //printf("joystick not ready to read: old data");
		//check flight mode
		    if(ESTOP)
		    {
			    if(flight_mode < 11.0) 
				{
					//printf("FLIGHT MODE: OFF %i \n", flight_mode); 
					CONTROLLER_RUN = false;
				}
			    else if (flight_mode > 15.0 && flight_mode < 17.0) AUTO_HEIGHT = false;
			    else if (flight_mode > 17.0) AUTO_HEIGHT = true;
		    } */
	}

	
	//calculate error from imu (in radians) between desired and measured state
	State imu_error = error_imu(desired_angles);

	//calculate thrust and desired acceleration
	U = thrust(imu_error,vicon_error, U_trim, joystick_thrust, gains);
	
	
	motor_commands = set_forces(U,Ct,d);
	
	/*quad_msgs::MotorCommands mcs;
	//calculate the forces of each motor and change force on motor objects and send via i2c

	if(!DEBUG) {
	  double* motor_commands;
	  motor_commands = set_forces(U,Ct,d);
	  mcs.header.stamp = ros::Time::now();
	  mcs.m0 = motor_commands[0];
	  mcs.m1 = motor_commands[1];
	  mcs.m2 = motor_commands[2];
	  mcs.m3 = motor_commands[3];
	  
	} else {
	  double m0c, m1c, m2c,m3c;
	  nh.getParam("m0_cmd",m0c);
	  nh.getParam("m1_cmd",m1c);
	  nh.getParam("m2_cmd",m2c);
	  nh.getParam("m3_cmd",m3c);

	  mcs.header.stamp = ros::Time::now();

	  mcs.m0 = m0c;
	  mcs.m1 = m1c;
	  mcs.m2 = m2c;
	  mcs.m3 = m3c;

	} */
        
	//cmd_pub.publish(mcs);
	end = ros::Time::now();
	dur = end - start;
	freq = 1/(dur.toSec());
	//ROS_INFO("%f", freq);
	if(freq < 200) ROS_WARN("frequency below 200: %f \n ", freq); //check frequencie
	

 }
    printf("EXIT CONTROL_STABILIZER\n");

}

void desired_angles_calc(Angles& desired_angles, const State_Error& error, const Gains& gains)
{

    desired_angles.psi     = 0;
    desired_angles.phi     =  gains.kp_y*error.y.prop - gains.kd_y*error.y.deriv + gains.ki_y*error.y.integral; //5.y_pos_sensor - 5*y_neg_sensor
    desired_angles.theta   = -gains.kp_x*error.x.prop + gains.kd_x*error.x.deriv - gains.ki_x*error.x.integral; //5.x_pos_sensor - 5*x_neg_sensor

}
/*
State_Error error_vicon(State_Error& error, const Vicon& pos_filt, const Vicon& vel_filt, const Positions& desired_positions, const Times& times){
       
    //proportional errors:  desired_positions - filtered_positions
    error.x.prop = desired_positions.x - pos_filt.x;
    error.y.prop = desired_positions.y - pos_filt.y;
    error.z.prop = desired_positions.z - pos_filt.z;
       
    //derivative errors: desired_velocities - filtered_velocities
    error.x.deriv = 0 - vel_filt.x;
    error.y.deriv = 0 - vel_filt.y;
    error.z.deriv = 0 - vel_filt.z;
       
    //integral errors: integral error + (proportional error * delta_t)
    error.x.integral = error.x.integral + (error.x.prop * tv2float(times.delta));
    error.y.integral = error.y.integral + (error.y.prop * tv2float(times.delta));
    error.z.integral = error.z.integral + (error.z.prop * tv2float(times.delta));

}
*/
void *motor_signal(void *thread_id){
   ros::NodeHandle nh2;
   ros::Publisher cmd_pub = nh2.advertise<quad_msgs::MotorCommands>("controller/cmd_motors",1); 
   //printf("INSIDE MOTOR_SIGNAL\n");
   set_initial_times(time_m);
   quad_msgs::MotorCommands mcs;
   
   while(ros::ok()){
    	
    	if(KILL_MOTORS)
    	{
    			mcs.header.stamp = ros::Time::now();
    			mcs.m0 = 0;
    			mcs.m1 = 0;
    			mcs.m2 = 0;
    			mcs.m3 = 0;
    			ROS_INFO("KILLING MOTORS: KILL_MOTORS = true\n");
    			
    	}  else {
    		mcs.header.stamp = ros::Time::now();
    		mcs.m0 = motor_commands[0];
    		mcs.m1 = motor_commands[1];
    		mcs.m2 = motor_commands[2];
    		mcs.m3 = motor_commands[3];
    	}
	
    cmd_pub.publish(mcs);
	//sets frequency of motor_signal
	usleep(10);
	}

   printf("EXIT MOTOR_SIGNAL\n");

   pthread_exit(NULL);
   
}


//State error_imu(const State& imu_data, const Angles& desired_angles){
State error_imu(const Angles& desired_angles){
    //calculate error in RADIANS
    //  xxx_d is xxx_desired.  imu outputs  degrees, we convert to radians with factor PI/180

    State error;
    error.phi    =  (desired_angles.phi   - new_imu_data.phi)      * PI/180;
    error.theta  =  (desired_angles.theta - new_imu_data.theta)   * PI/180;


    error.psi       =     (-new_imu_data.psi  + desired_angles.psi) * PI/180;
    error.phi_dot   =                           (-new_imu_data.phi_dot) * PI/180;
    error.theta_dot =                         (-new_imu_data.theta_dot) * PI/180;
    error.psi_dot   =                           (-new_imu_data.psi_dot) * PI/180;
    return error;
}
Control_command thrust(const State& imu_error, const State_Error& vicon_error, const Control_command& U_trim, const int joystick_thrust, const Gains& gains){
    //calculate thrust and acceleration
    Control_command U = {0};
    
    if(VICON_OR_JOY == 1){
    	 int calc_thrust = (int) (-(gains.kp_z * vicon_error.z.prop)  -  (gains.kd_z * vicon_error.z.deriv) - (gains.ki_z * vicon_error.z.integral));
    	 U.thrust        =  calc_thrust + U_trim.thrust; }
    else {
    	 U.thrust        = 4 * joystick_thrust  + U_trim.thrust;
    }

    U.roll_acc  =  (gains.kp_phi   * imu_error.phi  )  +  (gains.kd_phi   * imu_error.phi_dot  )  + U_trim.roll_acc;
    U.pitch_acc =  (gains.kp_theta * imu_error.theta)  +  (gains.kd_theta * imu_error.theta_dot)  + U_trim.pitch_acc;
    U.yaw_acc   =  (gains.kp_psi   * imu_error.psi  )  +  (gains.kd_psi   * imu_error.psi_dot  )  + U_trim.yaw_acc;

   if (U.thrust <= 0) U.thrust = 0;
   
    return U;
}

double* set_forces(const Control_command& U, double Ct, double d){
      //calculate forces from thrusts and accelerations

 
  static double mcs[4];
  
  
  if(!XConfig)
    {//this is Plus Configuration
        double force_1 = (U.thrust/4 - (U.yaw_acc /(4*Ct)) + (U.pitch_acc /  (2*d)));
        double force_2 = (U.thrust/4 + (U.yaw_acc /(4*Ct)) - (U.roll_acc  /  (2*d)));
        double force_3 = (U.thrust/4 - (U.yaw_acc /(4*Ct)) - (U.pitch_acc /  (2*d)));
        double force_4 = (U.thrust/4 + (U.yaw_acc /(4*Ct)) + (U.roll_acc  /  (2*d)));
        
        mcs[0] = round(force_1);
        mcs[1] = round(force_2);
        mcs[2] = round(force_3);
        mcs[3] = round(force_4);
        		

    }
      else
    {  
        double force_1 = (U.thrust/4 + (U.pitch_acc/(2*d)));
        double force_2 = (U.thrust/4 - (U.roll_acc/(2*d)))  ;
        double force_3 = (U.thrust/4 - (U.pitch_acc/(2*d))); 
        double force_4 = (U.thrust/4 + (U.roll_acc/(2*d)))  ; 
        double x_param = sqrt(2)/2;   
        double x1 = x_param * (force_1 + force_2)-(U.yaw_acc/(4*Ct));
        double x2 = x_param * (force_2 + force_3)+(U.yaw_acc/(4*Ct));
        double x3 = x_param * (force_3 + force_4)-(U.yaw_acc/(4*Ct));
        double x4 = x_param * (force_4 + force_1)+(U.yaw_acc/(4*Ct));
        
        mcs[0] = round(x1);
        mcs[1] = round(x2);
        mcs[2] = round(x3);
        mcs[3] = round(x4);

    }


  return mcs;

}

Vicon vicon_velocity(Vicon& current, Vicon& old){
    
    Vicon velocity = {0.0};
    
    velocity.x     = (current.x - old.x)/tv2float(times.delta);
    velocity.y     = (current.y - old.y)/tv2float(times.delta);
    velocity.z     = (current.z - old.z)/tv2float(times.delta);
    velocity.theta = (current.theta - old.theta)/tv2float(times.delta);
    velocity.phi   = (current.phi - old.phi)/tv2float(times.delta);
    velocity.psi   = (current.psi - old.psi)/tv2float(times.delta);

    return velocity;    
}

void log_data(const Distances& sonar_distances, const float& dt, const State_Error& vicon_error, const State& imu_data, const State& imu_error, const Angles& desired_angles){
/*
	Data_log d;
	d.dt   = dt;

	if(VICON_OR_JOY > 0)
	{
	    d.vicon_data      = xbee.getLastVicon();
	    d.vicon_vel       = xbee.getLastViconVel();
	    d.vicon_data_filt = xbee.getLastFiltVicon();
	    d.vicon_vel_filt  = xbee.getLastViconVel();
	}

	d.vicon_error     = vicon_error;
	d.imu             = imu_data;
	d.imu_error       = imu_error;
	d.forces.motor_1  = *(motor_1.get_force());
	d.forces.motor_2  = *(motor_2.get_force());
	d.forces.motor_3  = *(motor_3.get_force());
	d.forces.motor_4  = *(motor_4.get_force());
	

	d.desired_angles  = desired_angles;
	Distances sonarDist;

	sonarDist.x_pos = sonar_x_pos.returnLastDistance();
	sonarDist.x_neg = sonar_x_neg.returnLastDistance();
	sonarDist.y_pos = sonar_y_pos.returnLastDistance();
	sonarDist.y_neg = sonar_y_neg.returnLastDistance();
	sonarDist.down = sonar_down.returnLastDistance();
	sonarDist.up = sonar_up.returnLastDistance();
	
	//printf(" x_pos) %i, x_neg) %i, y_pos) %i y_neg) %i \n",sonarDist.x_pos, sonarDist.x_neg, sonarDist.y_pos, sonarDist.y_neg);
	d.sonar_distances = sonarDist;
	

	RepForces scales;
	scales.x_pos = repulsion_factor*UTILITY::dist2ScaleInv(sonar_x_pos.returnLastDistance(), minDist, maxDist);
	scales.x_neg = repulsion_factor*UTILITY::dist2ScaleInv(sonar_x_neg.returnLastDistance(), minDist, maxDist);
	scales.y_pos = repulsion_factor*UTILITY::dist2ScaleInv(sonar_y_pos.returnLastDistance(), minDist, maxDist);
	scales.y_neg = repulsion_factor*UTILITY::dist2ScaleInv(sonar_y_neg.returnLastDistance(), minDist, maxDist);
	scales.down  = repulsion_factor_down*UTILITY::dist2ScaleInv(sonar_down.returnLastDistance(), minDistDown, maxDistDown);
	scales.up    = repulsion_factor_up  *UTILITY::dist2ScaleInv(sonar_up.returnLastDistance(), minDistUp, maxDistUp);
	d.scales = scales;
	

	
    logger.log(d);
    
    */
	
    
    
   
}

void display_info(const Distances& sonar_distances, const int succ_read,  const State& imu_data,  const State& imu_error, const State_Error& vicon_error, const Control_command& U, const Angles& desired_angles,const int  joystick_thrust, const int  flight_mode, const Times& times, const Times& time_m){
	/*
    display_count++;
    if(! ( (display_count % 200) == 0) ) return;
 
    if(ncurse)clear();//function in curses library  
   
    printf("<==========================================>\n");   	
        printf("        System Flags    \n");
	printf("CONTROLLER_RUN = "); printf(CONTROLLER_RUN ? "true\n" : "false\n");
	printf("SYSTEM_RUN = "); printf(SYSTEM_RUN ? "true\n" : "false\n");
	printf("\n\n");

        printf("        IMU DATA (degrees)    \n");
        printf("Last read success? %i \n", imu_data.succ_read);
        printf("phi:   %7.2f         phi dot:   %7.2f \n",imu_data.phi, imu_data.phi_dot);//, imu_data.phi, imu_data.phi_dot);
        printf("theta: %7.2f         theta dot: %7.2f\n",imu_data.theta, imu_data.theta_dot);
        printf("psi:   %7.2f         psi dot:   %7.2f    psi uncal:   %7.2f\n\n",imu_data.psi, imu_data.psi_dot, imu_data.psi_contin);
    

   
	printf("        VICON DATA                                                          FILTERED VICON DATA   \n");
        printf("phi:      %10.2f       x: %10.2f                           phi:   %10.2f       x: %10.2f\n", vicon.phi, vicon.x, vicon_filt.phi, vicon_filt.x);
        printf("theta:    %10.2f       y: %10.2f                           theta: %10.2f       y: %10.2f\n",vicon.theta, vicon.y, vicon_filt.theta, vicon_filt.y);
        printf("psi:      %10.2f       z: %10.2f                           psi:   %10.2f       z: %10.2f\n\n",vicon.psi, vicon.z, vicon_filt.psi, vicon_filt.z);
      
    printf("        VICON VELOCITY                                                      FILTERED VICON VELOCITY  \n");
g_da
printf("phi_dot:  %10.2f       x_dot: %10.2f                  phi_dot:   %10.2f      x_dot: %10.2f\n", vicon_vel.phi, vicon_vel.x,  vicon_vel_filt.phi, vicon_vel_filt.x);
printf("theta_dot:%10.2f       y_dot: %10.2f                  theta_dot: %10.2f      y_dot: %10.2f\n",vicon_vel.theta, vicon_vel.y, vicon_vel_filt.theta, vicon_vel_filt.y);
printf("psi_dot:  %10.2f       z_dot: %10.2f                  psi_dot:   %10.2f      z_dot: %10.2f\n\n",vicon_vel.psi, vicon_vel.z ,vicon_vel_filt.psi, vicon_vel_filt.z);

    printf("        VICON ERRORS (meters)      \n"), joystick_thrust, U_trim.thrust;
        printf("x_prop:   %10.2f      y_prop:  %10.2f       z_prop:  %10.2f\n", vicon_error.x.prop, vicon_error.y.prop, vicon_error.z.prop);
        printf("x_deriv:  %10.2f      y_deriv: %10.2f       z_deriv: %10.2f\n", vicon_error.x.deriv, vicon_error.y.deriv, vicon_error.z.deriv);
        printf("x_integ:  %10.2f      y_integ: %10.2f       z_integ: %10.2f\n\n", vicon_error.x.integral, vicon_error.y.integral, vicon_error.z.integral);

    printf("        DESIRED ANGLES = f(vicon_error, gains)      \n");
        printf("phi:      %10.2f\n", desired_angles.phi);
        printf("theta:    %10.2f\n", desired_angles.theta);
        printf("psi:      %10.2f\n\n", desired_angles.psi);
        
 
      
     printf("        JOYSTICK DATA\n ");
	if(flight_mode < 11) printf("Flight Mode: OFF %i \n", flight_mode);
        printf("Last read success? %i  freq: %f \n", succ_read, 1/xbee.getDt());
        printf("phi: %.2f         theta: %.2f      psi: %.2f \n",  desired_angles.phi, desired_angles.theta, desired_angles.psi);
        printf("flight_mode: %i  joystick_thrust:  %i \n\n",flight_mode, joystick_thrust);


    printf("        THRUST \n");
        printf("U_trim: %i, joystick: %i \n\n", U_trim.thrust, joystick_thrust);   
      

    printf("        IMU ERRORS = f(imu_data, desired_angles) (radians)      \n");
        printf("phi:   %7.2f         phi dot:   %7.2f \n",imu_error.phi, imu_error.phi_dot);//, imu_data.phi, imu_data.phi_dot);
        printf("theta: %7.2f         theta dot: %7.2f\n",imu_error.theta, imu_error.theta_dot);
        printf("psi:   %7.2f         psi dot:   %7.2f\n\n",imu_error.psi, imu_error.psi_dot);
        printf("psi:   %7.2f         psi dot:   %7.2f\n\n",imu_error.psi*180/3.14, imu_error.psi_dot*180/3.14);
        

     printf("        DESIRED ACCELERATION = f(imu_error, gains)      \n");
        printf("roll  (phi)  :      %f\n",   U.roll_acc);
        printf("pitch (theta):      %f\n",   U.pitch_acc);
        printf("yaw   (psi)  :      %f\n\n", U.yaw_acc);    
     //   printf("U.yaw_acc %3.3f  =  (gains.kp_psi %3.3f   * imu_error.psi %3.3f  )  +  (gains.kd_psi %3.3f  * imu_error.psi_dot %3.3f  ) \n", 
       //                 U.yaw_acc, gains.kp_psi, imu_error.psi, gains.kd_psi, imu_error.psi_dot);
     
    printf("          GAINS \n");
        printf("Theta: KP %10.2f KD: %10.2f \n", gains.kp_theta, gains.kd_theta);
        printf("Phi: KP %10.2f KD: %10.2f \n", gains.kp_phi, gains.kd_phi);
        printf("Psi: KP %10.2f KD: %10.2f \n\n", gains.kp_psi, gains.kd_psi);


	printf("        THRUST(0-255): Current mode is");
	printf(VICON_OR_JOY ? " VICON: Thrust = Calc_Thrust + Trim_Thrust\n" : " JOYSTICK: Thrust = joystick_thrust from Joystick\n");    
	printf("U.thrust: %i, joystick_thrust %i, U.trim %i  \n\n", U.thrust, joystick_thrust, U_trim.thrust);




 
    printf("        FORCES (0-255)     \n");
       printf("motor_1: %i  ", *(motor_1.get_force()));
        printf("motor_2: %i  ", *(motor_2.get_force()));
        printf("motor_3: %i  ", *(motor_3.get_force()));
        printf("motor_4: %i \n\n", *(motor_4.get_force()));
        


    printf("        TIME INFO     \n");
        printf("Controller timestep (s)       :     %7.4f\n", tv2float(times.delta));
        printf("Controller loop frequency (Hz):     %5.3f\n", 1/tv2float(times.delta));
        printf("Motor loop frequency (Hz)     :    %5.3f\n", 1/tv2float(time_m.delta));
       // printf("%lld.%.9ld", (long long)times.current.tv_sec, times.current.tv_nsec);
        printf("Time Date                     :    %s\n ", times.date_time);



	printf("        Sonar: Distance (300 mm -5000 mm) and Frequency (Hz)     \n");
	printf("X+)   succ_read: %i, freq: %f, distance: %i, repulsive_scale [0,%i] %f \n", x_pos.succ_read, 1/sonar_x_pos.getDt(), sonar_x_pos.returnLastDistance(), repulsion_factor, repulsion_factor*UTILITY::dist2ScaleInv(sonar_x_pos.returnLastDistance(), minDist, maxDist));  
	printf("X-)   succ_read: %i, freq: %f, distance: %i, repulsive_scale [0,%i] %f \n", x_neg.succ_read, 1/sonar_x_neg.getDt(), sonar_x_neg.returnLastDistance(), repulsion_factor, repulsion_factor*UTILITY::dist2ScaleInv(sonar_x_neg.returnLastDistance(), minDist, maxDist));
	printf("Y+)   succ_read: %i, freq: %f, distance: %i, repulsive_scale [0,%i] %f \n", y_pos.succ_read, 1/sonar_y_pos.getDt(), sonar_y_pos.returnLastDistance(), repulsion_factor, repulsion_factor*UTILITY::dist2ScaleInv(sonar_y_pos.returnLastDistance(), minDist, maxDist));
	printf("Y-)   succ_read: %i, freq: %f, distance: %i, repulsive_scale [0,%i] %f  \n", y_neg.succ_read, 1/sonar_y_neg.getDt(),sonar_y_neg.returnLastDistance(), repulsion_factor, repulsion_factor*UTILITY::dist2ScaleInv(sonar_y_neg.returnLastDistance(), minDist, maxDist));
	printf("Down) succ_read: %i, freq: %f, distance: %i, repulsive_scale [0,%i] %f  \n", down.succ_read, 1/sonar_down.getDt(),sonar_down.returnLastDistance(), repulsion_factor_down,  repulsion_factor_down*UTILITY::dist2ScaleInv(sonar_down.returnLastDistance(), minDistDown, maxDistDown));
	printf("Up)   succ_read: %i, freq: %f, distance: %i, repulsive_scale [0,%i] %f  \n", up.succ_read, 1/sonar_up.getDt(),sonar_up.returnLastDistance(), repulsion_factor_up,  repulsion_factor_up*UTILITY::dist2ScaleInv(sonar_up.returnLastDistance(), minDistUp, maxDistUp));	


	if(ncurse)refresh();//refreshes shell console to output this text

*/

}

//executes input from host computer on motors, controller gains, displays, and controller
void* command_input(void *thread_id){
   /*
    //printf("INSIDE COMMAND_INPUT");
    unsigned char command;
    string input;

    while(SYSTEM_RUN) {
	    printf("    please give input for command_input: ");
        //command = getchar(); 
        //getline(cin, input);
        command = getch();
        printf("input: %i \n", command);
        switch (command) {
            case '1':

            case '4':
                start_motors();
                break;
                
            case '5':
            case 'q':
            case 'Q':
                printf("Motor Stop!\n");
                stop_motors();
                CONTROLLER_RUN = false;//change to System Run!
                endwin();
                break;
                
            case ' ':
            case 'z':
            case 'Z':
            case '\n':
                controller_on_off(CONTROLLER_RUN);
                break;

// control of desired positions
            case 'w':
            case 'W':
	          printf("Increase X desired_positions\n");
              desired_positions.x = desired_positions.x + delta_position;
                break; 
    
            case 's':
            case 'S':
	          printf("Decrease X desired_positions\n");
              desired_positions.x = desired_positions.x - delta_position;
                break; 
            
            case 'd':
            case 'D':
              printf("Increase Y desired_positions\n");
              desired_positions.y = desired_positions.y + delta_position;
              break;

            case 'a':
            case 'A':
              printf("Decrease Y desired_positions\n");
              desired_positions.y = desired_positions.y - delta_position;
                break;

            case 'r':
            case 'R':
              printf("Decrease Z desired_positions\n");
              desired_positions.z = desired_positions.z - delta_position;
                break;

            case 'f':
            case 'F':
              printf("Increase Z desired_positions\n");
              desired_positions.z = desired_positions.z + delta_position;
                 break;

// control of desired positions

            case 'b':
            case 'B':
                display_on_off(DISPLAY_RUN);
               // system("clear");
               //if(ncurse)clear(); //function in curses library
                break;
                
            case 'c':
            case 'C':
                if((U_trim.thrust + delta_thrust) >=  max_thrust) {
                  printf("Maximum Thrust Reached: Cannot Increase Thrust\n");
                  U_trim.thrust = max_thrust;}
                else {U_trim.thrust += delta_thrust; 
                     printf("Increase Thrust: %i\n", U_trim.thrust);}
              break;
                
            case 'v':
            case 'V':
                if((U_trim.thrust-=delta_thrust) <= 0) {
                printf("Thrust is 0. Cannot decrease further\n");
                U_trim.thrust = 0;}
                else {printf("Decrease Thrust: %i\n", U_trim.thrust);}
              break;
               
            case 'i':
            case 'I':
              printf("Reset Desired_positions to initial values\n");
              desired_positions.x = init_positions.x;
              desired_positions.y = init_positions.y;
              desired_positions.z = init_positions.z;
              break;
            
            case 'j':
            case 'J':
                printf("Reset desired_positions to current position (raw vicon)\n");
                Vicon current_position;
                get_vicon_data(usb_xbee, current_position);
                desired_positions.x = current_position.x;
                desired_positions.y = current_position.y;
                desired_positions.z = current_position.z;
                break;
    //START GAINS         
            case 'k':
            case 'K':
                printf("Increase kp_phi and kp_theta\n");
                gains.kp_phi   = gains.kp_phi   + 0.1;
                gains.kp_theta = gains.kp_theta + 0.1;
                break;
            
            case 'm':
            case 'M':
                printf("Decrease kp_phi and kp_theta\n");
                if((gains.kp_phi <= 0) || (gains.kp_phi <= 0)) {printf("kp_phi/theta already 0"); break;}
                gains.kp_phi   = gains.kp_phi   - 0.1;
                gains.kp_theta = gains.kp_theta - 0.1;    
                break;
     
            case 'g':
            case 'G':
                printf("Increase kd_phi and kd_theta\n");
                gains.kd_phi   = gains.kd_phi   + 0.05;
                gains.kd_theta = gains.kd_theta + 0.05;
                break;
                
            case 'h':
            case 'H':
                printf("Decrease kd_phi and kd_theta\n");
                if((gains.kd_phi <= 0) || (gains.kd_phi <= 0)) {printf("kd_phi/theta already 0"); break;}
                gains.kd_phi   = gains.kd_phi   - 0.05;
                gains.kd_theta = gains.kd_theta - 0.05;
                break;
            
            case 'n':
            case 'N':
                printf("Decrease kp_psi\n");
                if(gains.kp_psi <= 0) {printf("kp_psi already 0"); break;}
                gains.kp_psi   = gains.kp_psi   - 0.1;
                break;

            case 'o':
            case 'O':
                printf("Increase kp_psi\n");
                gains.kp_psi   = gains.kp_psi   + 0.1;
                break;
            
            case 'p':
            case 'P':
                printf("Decrease kd_psi\n");
                if(gains.kd_psi <= 0) {printf("kd_psi already 0"); break;} 
                gains.kd_psi   = gains.kd_psi   - 0.05;
                break;

            case 't':
            case 'T':
                printf("Increase kd_psi\n");
                gains.kd_psi   = gains.kd_psi   + 0.05;
                break;
      //END GAINS      
            case 'L':
                printf("Start/Stop Logging\n");
                LOG_DATA = ~LOG_DATA;
                break;
             
            case '`':
                if(ncurse)clear();
                if(ncurse)refresh();
                break;
                
              //used after j: s,w,r,f,v
              
              //  printf("Control Landing: Not Implemented\n");
              //t_landing = t;
              //CTRL_LANDING = true;

        }

    }
    pthread_exit(NULL);
    */
}
void configure_threads(void){
      //pthread_t - is an abstract datatype that is used as a handle to reference the thread
     //threads[0] = control_stabilizer
     //threads[1] = motor_signal
     //threads[2] = command_input

    pthread_t threads[NUM_THREADS];
    //Special Attribute for starting thread
    pthread_attr_t attr;
    //sched_param is a structure that maintains the scheduling parameters
        //sched_param.sched_priority  - an integer value, the higher the value the higher a thread's proiority for scheduling
    struct sched_param param;
    int fifo_max_prio, fifo_min_prio;
    
    // system("clear");
     //printf("INSIDE CONFIGURE_THREADS\n");
     	//if(ncurse)refresh();
     // Set thread attributes: FIFO scheduling, Joinable
     // the sched_param.sched_priorirty is an int that must be in [min,max] for a certain schedule policy, in this case, SCHED_FIFO
     pthread_attr_init(&attr);
     pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
     pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
     fifo_max_prio = sched_get_priority_max(SCHED_FIFO);
     fifo_min_prio = sched_get_priority_min(SCHED_FIFO); 

     	// create threads
     
     printf("=> creating control_stabilizer thread\n");
     //	if(ncurse)refresh();
     // Higher priority for filter
     param.sched_priority = fifo_max_prio;
     pthread_attr_setschedparam(&attr, &param);
     pthread_create(&threads[0], &attr, control_stabilizer, (void *) 0);
     usleep(onesecond);
  
     printf("=> creating motor_signal thread\n");
     	//if(ncurse)refresh();
     // Medium priority for motor_signal
     param.sched_priority = (fifo_max_prio+fifo_min_prio)/2;
     pthread_attr_setschedparam(&attr, &param);
     pthread_create(&threads[1], &attr, motor_signal, (void *) 1);
//	usleep(onesecond);
//	printf("final usleep done");

    /* printf("=> creating command_input thread\n");
	//if(ncurse)refresh();
     // Lower priority for commmand input
     param.sched_priority = (fifo_max_prio+fifo_min_prio)/2;
     pthread_attr_setschedparam(&attr, &param);
     pthread_create(&threads[2], &attr, command_input, (void *) 2); */
    

     // Wait for all threads to complete
       for (int i = 0; i < NUM_THREADS; i++)  {  
	   //calling join will block this main thread until every thread exits
         pthread_join(threads[i], NULL);
        }

     printf("EXITING CONFIGURE_THREADS\n");
     //close(usb_imu_ivn);
    
     pthread_attr_destroy(&attr);
  
}



void init(void)
{
    //ncurses
  // if(ncurse) initscr();

   //finds bias in gyro and checks for out of range imu values. returns 1 if bad imu values.
  // printf("finding gyro bias...\n");  
   //if(ncurse)refresh();
   //if(imu.calibrate() == 1) ;
   //else CONTROLLER_RUN = false;
   //if(ncurse)refresh();
	
   //printf("xbee.check_start_thrust() %i \n", xbee.check_start_thrust());
/*
   if(!VICON_OR_JOY)
   {
	if(xbee.check_start_thrust() > 0) CONTROLLER_RUN = true;
	else				      CONTROLLER_RUN = false;

	printf("CONTROLLER_RUN: %i\n\n", CONTROLLER_RUN);
	//if(ncurse)refresh();
   }
*/
   set_gains(gains);
   set_initial_times(times);
   set_initial_times(times_display);

}



int main(int argc, char** argv)
{
  
  //intialize desired angles, gains, U_trim, & open port ot xbee and imu
  init();
  
  //init ros
  ros::init(argc,argv,"controller");
    
  //ros::AsyncSpinner spinner(4); // Use 4 threads
  //spinner.start();
  //if(ncurse)clear();
  //printf("in main \n"); //if(ncurse)refresh();
	
  //start_motors();
  
  //control_stabilizer();
  usleep(onesecond*2);
	//if(ncurse)clear();

  configure_threads();
  usleep(onesecond*2);
	
  //configure_threads();

  //usleep(onesecond*2);
  //if(ncurse)clear();
  //if(ncurse) endwin();
  return 0;

}

