#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/ColorRGBA.h>


int main(int argc, char **argv)
{

 float r=0;
 float l=0;

  ros::init(argc, argv, "encoder_test");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<std_msgs::ColorRGBA>("/encoder", 1);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    std_msgs::ColorRGBA msg;
  
  /*printf ("Enter number of right pulses: ");
  scanf ("%d",r);  
  printf ("Enter your age: ");
  scanf ("%d",l);
  */
  msg.r=500;
  msg.g=500;

    pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}

