#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose2D.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

#define CRUISING_SPEED 0.05

using namespace sensor_msgs;

double turnRate;
double minDist;
double speed;

void laserCallback(const boost::shared_ptr<const LaserScan>& scan) {
    double MAX_ANGLE = scan->angle_max; //end angle of the scan
    double MIN_ANGLE = scan->angle_min; //start angle of the scan
    double inc = scan->angle_increment; //angular distance between measurements
    int bins = (int)((MAX_ANGLE - MIN_ANGLE) / inc);
    double minAngle = 0.0;
    double maxAngle = 0.0;
    minDist = scan->range_max; //maximum range value
    double maxDist = 0.0;
    for (int bin = 0; bin < bins; bin++) {

        double range = scan->ranges[bin];//range data

   ROS_INFO("The range I am reading is: %f\n", range);
       
    }
    
    
}


int main(int argc, char** argv){
    ros::init(argc, argv, "ObstacleAvoid");
    ros::NodeHandle n;
    
    ros::Rate loop_rate(0.1);
    ros::Time current_time;
    
    ros::Subscriber laserSub = n.subscribe("/scan", 1, laserCallback);

    while(n.ok()){
        current_time = ros::Time::now();

        //ROS_INFO("speed=%.3lf, turnRate=%.3lf", speed, turnRate); 
        
        
        ros::spinOnce();
        loop_rate.sleep();
    }
    
    return 0;
}


