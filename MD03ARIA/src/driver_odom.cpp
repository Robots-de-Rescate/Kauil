//test program. it should receive the data obtained by the interface: the mode and the acknowledge

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include <sstream>
#include <MD03ARIA/Reg.h>
#include <MD03ARIA/encoder.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include <MD03ARIA/encoder.h>

#define PI 3.14159265

using namespace std;

int open_port(void);				//el son del dolor la cuca
void str2bin(const std::string&, unsigned char);
void teleop_Callback(const MD03ARIA::Reg::ConstPtr&);
void encoderCallback(const MD03ARIA::encoder::ConstPtr&);
//void cmdvelCallback(const geometry_msgs::Twist::ConstPtr&);

struct termios options;

int
main(int argc, char **argv)
{


ros::init(argc, argv, "MD03subscriber");//nombre del nodo
ros::NodeHandle n;

ros::Subscriber sub_mode = n.subscribe("MD03_teleop", 1000, teleop_Callback);//se subscribe al topico llamado MD03_teleop
ros::Subscriber sub = n.subscribe("pulse_array", 1000, encoderCallback);
ros::Subscriber sub_cmdvel = n.subscribe("cmdvel", 1000, encoderCallback);


ros::spin();


return 0;

}

void str2bin(const std::string& in, unsigned char out[])
{

    const char* data = in.data();
    const std::string::size_type size = in.size();
    for(std::string::size_type i = 0; i < size; i+= 2) {
        unsigned int tmp;l,m
        std::sscanf(data+i, "%02X", &tmp);
        out[5] = tmp;
    }
}


void teleop_Callback(const MD03ARIA::Reg::ConstPtr& msg)
{

 int B0speed = msg->B0_speed;
 int B0direction = msg->B0_direction;
 int B2speed = msg->B2_speed;
 int B2direction = msg->B2_direction; 
 
 int fd = open_port();
 int r = 0;
 
 string mystring_speedB0;
 stringstream stream_speedB0;
 unsigned char sbuf_speedB0[10];

 string mystring_speedB2;
 stringstream stream_speedB2;
 unsigned char sbuf_speedB2[10];


 string mystring_directionB0;
 stringstream stream_directionB0;
 unsigned char sbuf_directionB0[10];

 string mystring_directionB2;
 stringstream stream_directionB2;
 unsigned char sbuf_directionB2[10];

 
 unsigned char sbuf_modeB0[10];
 
 unsigned char sbuf_modeB2[10];
 
 
 ROS_INFO("The speed of B0: [%i]\n", B0speed); //printf de ROS
 ROS_INFO("The direction f B0: [%i]\n", B0direction);
 ROS_INFO("The speed of B2: [%i]\n", B2speed);
 ROS_INFO("The direction of B2: [%i]\n", B2direction);

 stream_speedB0 << hex << B0speed;
 mystring_speedB0 = stream_speedB0.str(); 
 ROS_INFO("\nThe hexadecimal speed of B0: [%s]\n", mystring_speedB0.c_str()); 

{
    str2bin(mystring_speedB0, sbuf_speedB0);
    std::cout << std::hex;

   sbuf_speedB0[0] = 0x57;
   sbuf_speedB0[1] = 0x01;
   sbuf_speedB0[2] = 0x32;
   sbuf_speedB0[3] = 0xB0;
   sbuf_speedB0[4] = 0x02;
   sbuf_speedB0[6] = 0x03;
   sbuf_speedB0[7] = 0x00;

//sbuf_speedB0[5]=dato de velocidad

    std::copy(sbuf_speedB0, sbuf_speedB0+9, std::ostream_iterator<unsigned int>(std::cout, ", "));
    std::cout << "This was the speed of B0\n";
    
    write(fd, sbuf_speedB0, 8);
    usleep(100);

    r = read(fd, sbuf_speedB0, 1);
    if (r < 0)
    printf("read() failed!!");
}

 stream_directionB0 << hex << B0direction;
 mystring_directionB0 = stream_directionB0.str();
 ROS_INFO("\nThe hexadecimal direction of B0: [%s]\n", mystring_directionB0.c_str());

{
    str2bin(mystring_directionB0, sbuf_directionB0);
    std::cout << std::hex;

   sbuf_directionB0[0] = 0x57;
   sbuf_directionB0[1] = 0x01;
   sbuf_directionB0[2] = 0x32;
   sbuf_directionB0[3] = 0xB0;
   sbuf_directionB0[4] = 0x00;
   sbuf_directionB0[6] = 0x03;
   sbuf_directionB0[7] = 0x00;

    std::copy(sbuf_directionB0, sbuf_directionB0+9, std::ostream_iterator<unsigned int>(std::cout, ", "));
    std::cout << "This was the direction of B0\n";

    write(fd, sbuf_directionB0, 8);
    usleep(100);

    r = read(fd, sbuf_directionB0, 1);
    if (r < 0)
    printf("read() failed!!");
}
 
 stream_speedB2 << hex << B2speed;
 mystring_speedB2 = stream_speedB2.str();
 ROS_INFO("\nThe hexadecimal speed of B2: [%s]\n", mystring_speedB2.c_str());

{
    str2bin(mystring_speedB2, sbuf_speedB2);
    std::cout << std::hex;

   sbuf_speedB2[0] = 0x57;
   sbuf_speedB2[1] = 0x01;
   sbuf_speedB2[2] = 0x32;
   sbuf_speedB2[3] = 0xB2;
   sbuf_speedB2[4] = 0x02;
   sbuf_speedB2[6] = 0x03;
   sbuf_speedB2[7] = 0x00;

    std::copy(sbuf_speedB2, sbuf_speedB2+9, std::ostream_iterator<unsigned int>(std::cout, ", "));
    std::cout << "This was the speed of B2\n";
    
    write(fd, sbuf_speedB2, 8);
    usleep(100);

    r = read(fd, sbuf_speedB2, 1);
    if (r < 0)
    printf("read() failed!!");
}


 stream_directionB2 << hex << B2direction;  
 mystring_directionB2 = stream_directionB2.str();
 ROS_INFO("\nThe hexadecimal direction of B2: [%s]\n", mystring_directionB2.c_str());


{
   str2bin(mystring_directionB2, sbuf_directionB2);
    std::cout << std::hex;

   sbuf_directionB2[0] = 0x57;
   sbuf_directionB2[1] = 0x01;
   sbuf_directionB2[2] = 0x32;
   sbuf_directionB2[3] = 0xB2;
   sbuf_directionB2[4] = 0x00;
   sbuf_directionB2[6] = 0x03;
   sbuf_directionB2[7] = 0x00;

    std::copy(sbuf_directionB2, sbuf_directionB2+8, std::ostream_iterator<unsigned int>(std::cout, ", "));
    std::cout << "This was the direction of B2\n";

    write(fd, sbuf_directionB2, 8);
    usleep(100);

    r = read(fd, sbuf_directionB2, 1);
    if (r < 0)
    printf("read() failed!!");
}
}



int open_port(void)
{
int fd;
// File descriptor for the port
fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY);
if (fd == -1)
{
perror("open_port: Unable to open /dev/ttyACM0 - ");
// Could not open the port.
} else
{
fcntl(fd, F_SETFL, 0);

//Get the current options for the port...
tcgetattr(fd, &options);

//Set the baud rates to 19200...
cfsetispeed(&options, B19200);

//Enable the receiver and set local mode...
options.c_cflag |= (CLOCAL | CREAD);

//Set no parity bit
options.c_cflag &= ~PARENB;

//Set 2 stop bits
options.c_cflag &= ~CSTOPB;

//Set the character size
options.c_cflag &= ~CSIZE;
options.c_cflag |= CS8;

//Set the new options for the port...
tcsetattr(fd, TCSANOW, &options);

fcntl(fd, F_SETFL, FNDELAY);
}
return (fd);
}

void encoderCallback(const MD03ARIA::encoder::ConstPtr& encoder)
{ 
 ros::NodeHandle n; 
 ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
 tf::TransformBroadcaster odom_broadcaster;

 int pulse_r = encoder->rpulses;
 int direction_r = encoder->rdirection; 
 int pulse_l = encoder->lpulses;
 int direction_l = encoder->ldirection;

  double x = 0.0; 	//displacement < m >
  double y = 0.0; 	//displacement < m >
  double th = 0.0; 	//angulo de todo el movil < rad >
  double V = 0.0; 	//velocidad del movil en el centro < m/s >
  /*double dt = 1; //delta t (determined @ micro)*/  //not necessary dt defined ahead with differential of ros::Time

  double gamma =0.5; //rotacion de la flecha  
  double p = 110;  //pulsos entregados por el encoder (valor que va a variar) -> callback  function
  double Ce = 124; //pusos x revolucion
  double nu = 8;   //relacion de transmision
  double L = 0.3;  //Distace between motors < m >
  double d = 0.1;  //pulley diameter < m >
  double s = 0;    //arc length < m >
  double vx = 0;   //initial x velocity < m/s >
  double vy = 0;   //initial y velocity < m/s >
  double vth = 0;  //initial th velocity < m/s >
  double dis = 0;  //displacement of the robot < m >
  double delta_x = 0;
  double delta_y = 0;
  double delta_th = 0;

  ros::Time current_time, last_time;
  current_time = ros::Time::now();
  last_time = ros::Time::now();

  ros::Rate r(1);  //must be modified ---> now: 10 Hz
  while(n.ok()){

    ros::spinOnce();        // check for incoming messages
    current_time = ros::Time::now();
    
    double dt = (current_time - last_time).toSec(); // time differential
    ROS_INFO("\n The time delta is: [%f]\n", dt); 
    
	//corregir como obtener datos para el if pulse_data(?)
        int izq = pulse_l*direction_l;   	//pulse_data section at end
	int der = pulse_r*direction_r;
	
    if (izq != 0 && der != 0) {	//ensure we are not spinning
       p = (izq+der/2);
       s=(p*2*PI/(Ce*8))*(PI*d); 	//displacement in forward motion < m >
       V=s/dt; 				//linear velocity < m/s >
    } else { 				//recognize to which side is the turn
    //"if" to recognize which encoder is working
       if (izq == 0) {	//encoder_1 "izq" not working->we use data from 2
          p = der;
       }
       if (der == 0) {	//encoder_2 "der" not working->we use data from 1
          p = izq;
       }
    s=(p*2*PI/(Ce*8))*(PI*d); 	//arc length < m >
    th=s/L; 				//angulo de todo el movil
    V=(th*L)/(2*dt); 			//velocidad del movil en el centro
    }

    vx = V*cos(th);
    vy = V*sin(th);
    vth = th/dt;
    
    delta_x = vx*dt;
    delta_y = vy*dt;
    delta_th = vth*dt;

    x += delta_x;
    y += delta_y;
    th += delta_th;

ROS_INFO("Theta is equal to: %f \n", th);

    //since all odometry is 6DOF we'll need a quaternion created from yaw
    geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);

    //first, we'll publish the transform over tf
    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = current_time;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_kauil";

    odom_trans.transform.translation.x = x;
    odom_trans.transform.translation.y = y;
    odom_trans.transform.translation.z = 0.0;
    odom_trans.transform.rotation = odom_quat;

    //send the transform
    odom_broadcaster.sendTransform(odom_trans);

    //next, we'll publish the odometry message over ROS
    nav_msgs::Odometry odom;http://www.nimble-v.com/regForm.php?configNumber=b7448410b720d9529e9c72d4d2ba6180
    odom.header.stamp = current_time;
    odom.header.frame_id = "odom";

    //set the position
    odom.pose.pose.position.x = x;
    odom.pose.pose.position.y = y;
    odom.pose.pose.position.z = 0.0;
    odom.pose.pose.orientation = odom_quat;

    //set the velocity
    odom.child_frame_id = "base_kauil";
    odom.twist.twist.linear.x = vx;
    odom.twist.twist.linear.y = vy;
    odom.twist.twist.angular.z = vth;

    //publish the message
    odom_pub.publish(odom);

    last_time = current_time;
    r.sleep();}}








