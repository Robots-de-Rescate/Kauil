//test program. it should receive the data obtained by the interface: the mode and the acknowledge

#include <stdio.h>//libreria para comunicacion serial
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include <sstream>
#include <MD03ARIA/Reg.h>


using namespace std;

int open_port(void);
int display_mode(void);
void str2bin(const std::string&, unsigned char);
void teleop_Callback(const MD03ARIA::Reg::ConstPtr&);


struct termios options;

int
main(int argc, char **argv)
{


ros::init(argc, argv, "MD03subscriber");//nombre del nodo
ros::NodeHandle n;

ros::Subscriber sub_mode = n.subscribe("MD03_teleop", 1000, teleop_Callback);//se subscribe al topico llamado MD03_teleop


ros::spin();


return 0;

}

void str2bin(const std::string& in, unsigned char out[])
{

    const char* data = in.data();
    const std::string::size_type size = in.size();
    for(std::string::size_type i = 0; i < size; i+= 2) {
        unsigned int tmp;
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
    usleep(750000);

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
    usleep(750000);

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
    usleep(750000);

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
    usleep(750000);

    r = read(fd, sbuf_directionB2, 1);
    if (r < 0)
    printf("read() failed!!");
}
}



int
open_port(void)
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






