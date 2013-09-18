//obtained from http://ros-users.122217.n3.nabble.com/Pioneer3-td1265101.html#a1288712
//Modified by Laura Galindez Olascoaga (December 2010)


#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <tf/tf.h>
#include <tf/time_cache.h>
#include <nav_msgs/Odometry.h>



void poseCallback(const nav_msgs::Odometry::ConstPtr& odomsg) //recibimos datos de odometria 
{
   //TF odom=> base_link
    
       static tf::TransformBroadcaster odom_broadcaster;
    odom_broadcaster.sendTransform(  //mandamos la transformada de odom a base_link
      tf::StampedTransform(
				tf::Transform(tf::Quaternion(odomsg->pose.pose.orientation.x,
                                     odomsg->pose.pose.orientation.y,
                                     odomsg->pose.pose.orientation.z,
                                     1),//odomsg->pose.pose.orientation.w),
        tf::Vector3(odomsg->pose.pose.position.x, 
                    odomsg->pose.pose.position.y, 
                    odomsg->pose.pose.position.z)),
				odomsg->header.stamp, "/odom", "/base_link")); 
      ROS_DEBUG("odometry frame sent");
}




int main(int argc, char** argv){
	ros::init(argc, argv, "tf_publisher");
	ros::NodeHandle n;

	ros::Rate r(10);

	tf::TransformBroadcaster broadcaster;
  
  //subscribe to pose info
	ros::Subscriber pose_sub = n.subscribe<nav_msgs::Odometry>("/odom", 1, poseCallback); //subscribes to MD03 odometry

	while(n.ok()){
    //base_link => base_scan
		broadcaster.sendTransform(
			tf::StampedTransform(
				tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.08, 0.0, 0.1)),
				ros::Time::now(), "/base_link", "/base_laser"));

    ros::spinOnce();		
    r.sleep();
	}
}				

