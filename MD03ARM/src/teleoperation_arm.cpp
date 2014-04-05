//test program. it should only publish the data obtained by the interface: the mode and the acknowledge

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


#include <signal.h>
#include <math.h>

#include <stdlib.h>
#include <sys/poll.h>

#include <boost/thread/thread.hpp>
#include <ros/ros.h>


#define KEYCODE_I 0x69
#define KEYCODE_J 0x6a
#define KEYCODE_K 0x6b
#define KEYCODE_L 0x6c
#define KEYCODE_W 0x77
#define KEYCODE_X 0x78
#define KEYCODE_E 0x65
#define KEYCODE_U 0x75
#define KEYCODE_O 0x6F
#define KEYCODE_M 0x6d
#define KEYCODE_R 0x72
#define KEYCODE_V 0x76
#define KEYCODE_T 0x74
#define KEYCODE_B 0x62

#define KEYCODE_COMMA 0x2c
#define KEYCODE_PERIOD 0x2e

#define COMMAND_TIMEOUT_SEC 0.2


int maximum_speed = 255; //decimal value of max speed in 02 register
int dir = 01;// forward direction in 00 register

// should we continuously send commands?
bool always_command = false;

int parameter(void);
void change_mode (void);
int open_port(void);

class MD03teleop
{
  private:
    MD03ARM::Reg cmdvel; //mensaje de tipo Reg (Cuatro Ints64)
    ros::NodeHandle n;
    ros::Publisher pub;

  public:
    MD03teleop()
    {
      pub = n.advertise<MD03ARM::Reg>("MD03_teleop",1); //TBK_Node publishes RosAria/cmd_vel topic and RosAria node subscribes to it
    }
    ~MD03teleop() { }
    void keyboardLoop();
   void stopRobot()
    {
      cmdvel.B0_direction = cmdvel.B0_speed = 0.0;
      pub.publish(cmdvel);
    }
};

MD03teleop* teleop;
int kfd = 0;
struct termios cooked, raw;
struct termios options;
bool done;

int
main(int argc, char **argv)
{
   
  ros::init(argc, argv, "MD03publisher");//name of the node
  MD03teleop teleop;

  boost::thread t = boost::thread(boost::bind(&MD03teleop::keyboardLoop, &teleop));

  ros::spin();

  t.interrupt();
  t.join();
  //teleop.stopRobot();
  tcsetattr(kfd, TCSANOW, &cooked);

return (0);
}


void
MD03teleop::keyboardLoop()
{

  char c;
  int max_speed = maximum_speed;
  int max_turn = dir;
  bool dirty=false;

  int B0_speed=0;
  int B0_turn=0;
  int B2_speed=0;
  int B2_turn=0;
  int B4_speed=0;
  int B4_turn=0;
  int B6_speed=0;
  int B6_turn=0;

  tcgetattr(kfd, &cooked);
  memcpy(&raw, &cooked, sizeof(struct termios));
  raw.c_lflag &=~ (ICANON | ECHO);
  raw.c_cc[VEOL] = 1;
  raw.c_cc[VEOF] = 2;
  tcsetattr(kfd, TCSANOW, &raw);

  puts("Reading from keyboard");
  puts("-------------------------------------------------------------------------------");
  puts("w/x : increase/decrease max linear speed by 10%");
  puts("e: set to maximum speed");
  puts("--------------------------------------------------------------------------------");
  puts("Moving around:");
  puts(" r=shoulder forward v=elbow forward t=shoulder backwards");
  puts(" b=elbow comma=go forward ");
  puts("  u=turn left              i=go forward          o=turn right");
  puts("                           k=go backwards                    ");
  puts(" m=turn left and go backwards ,=go backwards .=turn right and go backwards");
  puts(" anything else : stop");
  puts("--------------------------------------------------------------------------------");


  struct pollfd ufd;
  ufd.fd = kfd;
  ufd.events = POLLIN;
  for(;;)
  {
    boost::this_thread::interruption_point();
    
    // get the next event from the keyboard
    int num;
    if((num = poll(&ufd, 1, 250)) < 0)
    {
      perror("poll():");
      return;
    }
    else if(num > 0)
    {
      if(read(kfd, &c, 1) < 0)
      {
        perror("read():");
        return;
      }
    }
    else
      continue;

    switch(c)
    {
      case KEYCODE_I:
        B0_turn = 1;
        B0_speed = 1;
        B2_turn = 1;
        B2_speed = 1;
        dirty = true;
        break;
      case KEYCODE_O:
        B0_turn = 1;
        B0_speed = 1;
        B2_turn = 0;
        B2_speed = 0;
        dirty = true;
        break;
      case KEYCODE_U:
        B0_turn = 0;
        B0_speed = 0;
        B2_turn = 1;
        B2_speed = 1;
        dirty = true;
        break;
      case KEYCODE_K:
        B0_turn = 2;
        B0_speed = 1;
        B2_turn = 2;
        B2_speed = 1;
        dirty = true;
        break;
      case KEYCODE_R:
        B4_turn = 1;
        B4_speed = 1;
        B6_turn = 0;
        B6_speed = 0;
        dirty = true;
        break;
      case KEYCODE_V:
        B4_turn = 0;
        B4_speed = 0;
        B6_turn = 1;
        B6_speed = 1;
        dirty = true;
        break;
      case KEYCODE_T:
        B4_turn = 2;
        B4_speed = 1;
        B6_turn = 0;
        B6_speed = 0;
        dirty = true;
        break;
      case KEYCODE_B:
        B4_turn = 0;
        B4_speed = 0;
        B6_turn = 2;
        B6_speed = 1;
        dirty = true;
        break;
      case KEYCODE_COMMA:
        B4_turn = 1;
        B4_speed = 1;
        B6_turn = 1;
        B6_speed = 1;
        dirty = true;
        break;
      case KEYCODE_W:
         if (max_speed>=255)
          {
          max_speed=255;
          printf ("\nThe speed is already at its maximum\n");
          }
         else
          {
          max_speed += max_speed / 10.0;
          printf("\nWhen pressing w the value of max_speed is: %i", max_speed);
          }
        if(always_command)
          dirty = true;
        break;
      case KEYCODE_X:
        if (max_speed==0)
         {
          max_speed=0;
          printf("\nSpeed can't go lower\n");
         }
        else
        max_speed -= max_speed / 10.0;
        if(always_command)
          dirty = true;
        break;
case KEYCODE_E:
        B0_speed = 255;
        B2_speed = 255;
        B4_speed = 255;
        B6_speed = 255;
        if(always_command)
          dirty = true;
        break;
     
    default:
      B0_speed = 0;
      B0_turn = 0;
      B2_speed = 0;
      B2_turn = 0;
      B4_speed = 0;
      B4_turn = 0;
      B6_speed = 0;
      B6_turn = 0;
      dirty = true;printf ("the value of variable max_speed= %i\n\n", max_speed);
    }

if (dirty == true)
    {
      cmdvel.B0_speed = B0_speed * max_speed;
      cmdvel.B0_direction = B0_turn * max_turn;
      cmdvel.B2_speed = B2_speed * max_speed;
      cmdvel.B2_direction = B2_turn * max_turn;
      cmdvel.B4_speed = B4_speed * max_speed;
      cmdvel.B4_direction = B4_turn * max_turn;
      cmdvel.B6_speed = B6_speed * max_speed;
      cmdvel.B6_direction = B6_turn * max_turn;

printf ("the cmdvel of B0 speed is equal to= %i \n", cmdvel.B0_speed);
printf ("the cmdvel of B0 direction is equal to= %i \n", cmdvel.B0_direction);
printf ("the cmdvel of B2 speed is equal to= %i \n", cmdvel.B2_speed);
printf ("the cmdvel of B2 direction is equal to= %i \n", cmdvel.B2_direction);
printf ("the cmdvel of B4 speed is equal to= %i \n", cmdvel.B4_speed);
printf ("the cmdvel of B4 direction is equal to= %i \n", cmdvel.B4_direction);
printf ("the cmdvel of B6 speed is equal to= %i \n", cmdvel.B6_speed);
printf ("the cmdvel of B6 direction is equal to= %i \n", cmdvel.B6_direction);

pub.publish(cmdvel);

    }

 }
}


void change_mode (void)
{
int fd = open_port();
unsigned char sbuf[64];
int x = 0;
int output = 0;
int r = 0;

sbuf[0] = 0x5a;
sbuf[1] = 0x02;
sbuf[2] = 0x60;
sbuf[3] = 0x00;

write(fd, sbuf, 4);
usleep(750000);

close (fd);
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


