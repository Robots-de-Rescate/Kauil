#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose2D.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

#define CRUISING_SPEED 0.05

using namespace sensor_msgs;

void laserCallback(const boost::shared_ptr<const LaserScan>& scan) {
    float ANGLE_MIN = scan->angle_min; //end angle of the scan
    float ANGLE_MAX = scan->angle_max; //start angle of the scan
    float ANGLE_INCREMENT = scan->angle_increment;
    float TIME_INCREMENT = scan->time_increment;
    float SCAN_TIME = scan->scan_time;
    float RANGE_MIN = scan->range_min;
    float RANGE_MAX = scan->range_max;

    int bins = (int) ((ANGLE_MAX-ANGLE_MIN)/ANGLE_INCREMENT);

 
 for (int bin = 0; bin<bins; bin++)
    {
     float RANGES = scan->ranges[bin];
     float INTENSITIES = scan->intensities[bin]; 
     ROS_INFO("\n Range number: %i is %f \n", bin, RANGES);
     ROS_INFO("\n Intensity number: %i is %f \n", bin, INTENSITIES); 
    }


 ROS_INFO("\n angle_min: %f \n", ANGLE_MIN);
 ROS_INFO("\n angle_max: %f \n", ANGLE_MAX);
 ROS_INFO("\n angle_increment: %f \n", ANGLE_INCREMENT);
 ROS_INFO("\n scan_time: %f \n", SCAN_TIME);
 ROS_INFO("\n range_min: %f \n", RANGE_MIN);
 ROS_INFO("\n range_max: %f \n", RANGE_MAX);

}


int main(int argc, char** argv){
    ros::init(argc, argv, "ObstacleAvoid");//inicializa el nodo  y lo nombra ObstacleAvoid
    ros::NodeHandle n; //instancia con la que nos conectamos
    
    ros::Rate loop_rate(5);
    ros::Time current_time;
    
   
    ros::Subscriber laserSub = n.subscribe("/scan", 1, laserCallback);//se subscribe al topico /scan

    while(n.ok()){
        current_time = ros::Time::now();

        //ROS_INFO("speed=%.3lf, turnRate=%.3lf", speed, turnRate); 
  
        
        ros::spinOnce();
        loop_rate.sleep();
    }
    
    return 0;
}


