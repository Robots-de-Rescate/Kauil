#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int8.h"
#include "MD03ARIA/encoder.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{

  ros::init(argc, argv, "fake_encoder");


  ros::NodeHandle n;

 
  ros::Publisher chatter_pub = n.advertise<MD03ARIA::encoder>("pulse_array", 1000);
  

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  int count = 0;

  while (ros::ok())
  {
   
    MD03ARIA::encoder info;

    cout << "\n Enter the number of right pulses: \n";
    int p_r;
    cin >> p_r;
   
    cout << "\n Enter right direction (1 forward -1 back): \n";
    int d_r;
    cin >> d_r;

    cout << "Enter the number of left pulses: \n";
    int p_l;
    cin >> p_l;
   
    cout << "\n Enter left direction (1 forward -1 back): \n";
    int d_l;
    cin >> d_l; 

 cout << "\n Right pulses: \n" << p_r;
 cout << "\n Right direction: \n" << d_r;
 cout << "\n Left pulses: \n" << p_l;
 cout << "\n Left direction: \n" << d_l;

	/*int array [100];

	for (int i=0; i<100; i++)
	array [i]=p;
*/

	info.rpulses = p_r;
        info.rdirection = d_r;
	info.lpulses = p_l;
        info.ldirection = d_l;	

chatter_pub.publish(info);
    

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}



