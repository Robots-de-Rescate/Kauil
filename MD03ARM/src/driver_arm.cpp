//test program. it should receive the data obtained by the interface: the mode and the acknowledge

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include <sstream>
#include <MD03ARM/Reg.h>


using namespace std;

int open_port(char * port_path);
int display_mode(void);
void str2bin(const std::string&, unsigned char);
void teleop_Callback(const MD03ARM::Reg::ConstPtr&);


struct termios options;

char * port_path;

int
main(int argc, char **argv)
{


port_path = argv[1];
ros::init(argc, argv, "MD03subscriberarm");//nombre del nodo
ros::NodeHandle n;

ros::Subscriber sub_mode = n.subscribe("MD03_teleop", 1, teleop_Callback);//se subscribe al topico llamado MD03_teleop


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


void teleop_Callback(const MD03ARM::Reg::ConstPtr& msg)
{

 int B4speed = msg->B4_speed;
 int B4direction = msg->B4_direction;
 int B6speed = msg->B6_speed;
 int B6direction = msg->B6_direction;
 
 int fd = open_port(port_path);
 int r = 0;
 
 string mystring_speedB4;
 stringstream stream_speedB4;
 unsigned char sbuf_speedB4[10];

 string mystring_speedB6;
 stringstream stream_speedB6;
 unsigned char sbuf_speedB6[10];


 string mystring_directionB4;
 stringstream stream_directionB4;
 unsigned char sbuf_directionB4[10];

 string mystring_directionB6;
 stringstream stream_directionB6;
 unsigned char sbuf_directionB6[10];

 
 unsigned char sbuf_modeB4[10];
 
 unsigned char sbuf_modeB6[10];
 
 
ROS_INFO("The speed of B4: [%i]\n", B4speed); //printf de ROS
ROS_INFO("The direction f B4: [%i]\n", B4direction);
ROS_INFO("The speed of B6: [%i]\n", B6speed);
ROS_INFO("The direction of B6: [%i]\n", B6direction);

 stream_speedB4 << hex << B4speed;
 mystring_speedB4 = stream_speedB4.str();
ROS_INFO("\nThe hexadecimal speed of B4: [%s]\n", mystring_speedB4.c_str());

{
    str2bin(mystring_speedB4, sbuf_speedB4);
    std::cout << std::hex;

   sbuf_speedB4[0] = 0x57;
   sbuf_speedB4[1] = 0x01;
   sbuf_speedB4[2] = 0x32;
   sbuf_speedB4[3] = 0xB4;
   sbuf_speedB4[4] = 0x02;
   sbuf_speedB4[6] = 0x03;
   sbuf_speedB4[7] = 0x00;

//sbuf_speedB0[5]=dato de velocidad

    std::copy(sbuf_speedB4, sbuf_speedB4+9, std::ostream_iterator<unsigned int>(std::cout, ", "));
    std::cout << "This was the speed of B4\n";
    
    write(fd, sbuf_speedB4, 8);
    //usleep(1000);

    r = read(fd, sbuf_speedB4, 1);
    if (r < 0)
    printf("read() failed!!");
}

 stream_directionB4 << hex << B4direction;
 mystring_directionB4 = stream_directionB4.str();
 ROS_INFO("\nThe hexadecimal direction of B4: [%s]\n", mystring_directionB4.c_str());

{
    str2bin(mystring_directionB4, sbuf_directionB4);
    std::cout << std::hex;

   sbuf_directionB4[0] = 0x57;
   sbuf_directionB4[1] = 0x01;
   sbuf_directionB4[2] = 0x32;
   sbuf_directionB4[3] = 0xB4;
   sbuf_directionB4[4] = 0x00;
   sbuf_directionB4[6] = 0x03;
   sbuf_directionB4[7] = 0x00;

    std::copy(sbuf_directionB4, sbuf_directionB4+9, std::ostream_iterator<unsigned int>(std::cout, ", "));
    std::cout << "This was the direction of B4\n";

    write(fd, sbuf_directionB4, 8);
    //usleep(1000);

    r = read(fd, sbuf_directionB4, 1);
    if (r < 0)
    printf("read() failed!!");
}
 
 stream_speedB6 << hex << B6speed;
 mystring_speedB6 = stream_speedB6.str();
 ROS_INFO("\nThe hexadecimal speed of B6: [%s]\n", mystring_speedB6.c_str());

{
    str2bin(mystring_speedB6, sbuf_speedB6);
    std::cout << std::hex;

   sbuf_speedB6[0] = 0x57;
   sbuf_speedB6[1] = 0x01;
   sbuf_speedB6[2] = 0x32;
   sbuf_speedB6[3] = 0xB6;
   sbuf_speedB6[4] = 0x02;
   sbuf_speedB6[6] = 0x03;
   sbuf_speedB6[7] = 0x00;

    std::copy(sbuf_speedB6, sbuf_speedB6+9, std::ostream_iterator<unsigned int>(std::cout, ", "));
    std::cout << "This was the speed of B6\n";
    
    write(fd, sbuf_speedB6, 8);
    //usleep(1000);

    r = read(fd, sbuf_speedB6, 1);
    if (r < 0)
    printf("read() failed!!");
}


 stream_directionB6 << hex << B6direction;
 mystring_directionB6 = stream_directionB6.str();
 ROS_INFO("\nThe hexadecimal direction of B6: [%s]\n", mystring_directionB6.c_str());


{
   str2bin(mystring_directionB6, sbuf_directionB6);
    std::cout << std::hex;

   sbuf_directionB6[0] = 0x57;
   sbuf_directionB6[1] = 0x01;
   sbuf_directionB6[2] = 0x32;
   sbuf_directionB6[3] = 0xB6;
   sbuf_directionB6[4] = 0x00;
   sbuf_directionB6[6] = 0x03;
   sbuf_directionB6[7] = 0x00;

    std::copy(sbuf_directionB6, sbuf_directionB6+8, std::ostream_iterator<unsigned int>(std::cout, ", "));
    std::cout << "This was the direction of B6\n";

    write(fd, sbuf_directionB6, 8);
    //usleep(1000);

    r = read(fd, sbuf_directionB6, 1);
    if (r < 0)
    printf("read() failed!!");
}
}



int
open_port(char * port_path)
{
int fd;
// File descriptor for the port
fd = open(port_path, O_RDWR | O_NOCTTY);
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
