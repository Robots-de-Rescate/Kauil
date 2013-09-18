//test program. it should receive the data obtained by the interface: the mode and the acknowledge

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "std_msgs/String.h"
#include <sstream>
#include <MD03ARIA/Num.h>


using namespace std;

void Arduino_Callback(const std_msgs::String::ConstPtr& msg);



int
main(int argc, char **argv)
{

ros::init(argc, argv, "ArduinoSubscriber");//nombre del nodo
ros::NodeHandle n;


ros::Subscriber sub_mode = n.subscribe("chatter", 1, Arduino_Callback);//se subscribe al topico llamado MD03_teleop



ros::Publisher permiso_pub = n.advertise<std_msgs::String>("permiso", 1000);

  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    
   

 std_msgs::String msg;

    std::stringstream ss;
    ss << "Start working" << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    permiso_pub.publish(msg);
    ros::spinOnce();


    ++count;
  }



return 0;

}



void Arduino_Callback(const std_msgs::String::ConstPtr& msg)
{

ROS_INFO("I heard that Arduino said: [%s]", msg->data.c_str());

}



