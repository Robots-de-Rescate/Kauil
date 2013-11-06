//odometry code

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/ColorRGBA.h>

#include "math.h"
#include <odometry/encoder.h>
#include <std_msgs/Int16.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <encoder/encoder.h>

#define PI 3.14159265

float x_total=0;
float y_total=0;
float theta_total=0;
ros::Time current_time, last_time;

void encoderCallback(const encoder::encoder::ConstPtr&);

int main(int argc, char** argv) {

    ros::init(argc, argv, "odometry_publisher");
    ros::NodeHandle n;
    last_time = ros::Time::now();
    ros::Subscriber sub = n.subscribe("/encoder", 1, encoderCallback);
    ros::spin();
    return 0;
}



void encoderCallback(const encoder::encoder::ConstPtr& encoder) {

    ros::NodeHandle n;
    ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
    tf::TransformBroadcaster odom_broadcaster;

    float pulse_r = (float)encoder->der;
    float pulse_l = (float)encoder->izq;

    float delta_x = 0;
    float delta_y = 0;
    float delta_theta = 0;
    double dt = 0.0; //defined ahead with differential of ros::Time
    float v_x = 0;
    float v_y = 0;
    float v_theta = 0;

    float Ce = 5.092958179; //pulsos x rad
    float nu = 48.75;   //relacion de transmision
    float L = 0.3;  //Distace between motors < m >
    float rc = 0.06;  //pulley diameter < m >
    float sl = 0;
    float sr = 0;    //arc length < m >

    current_time = ros::Time::now();

    ros::Rate r(1);
    while(n.ok()) {

        ros::spinOnce();        // check for incoming messages

        dt = (current_time - last_time).toSec(); // time differential

        sl=(pulse_l/(Ce*nu))*(rc);//left displacement (in m)
        sr=(pulse_r/(Ce*nu))*(rc);//right displacement (in m)

        if(pulse_r!=0 || pulse_l!=0) {
            delta_theta=(sl-sr)/0.3;
            delta_x=((sr+sl)*(sin(delta_theta)))/2;
            delta_y=((sr+sl)*(cos(delta_theta)))/2;

            //global position and orientation
            x_total+=delta_x;
            y_total+=delta_y;
            theta_total+=delta_theta;

            //speeds
            v_x=x_total/dt;
            v_y=y_total/dt;
            v_theta=theta_total/dt;
        }

        //since all odometry is 6DOF we'll need a quaternion created from yaw
        geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(theta_total);


        ////////////////////////////////////////////////////////////////////////////////

        //first, we'll publish the transform over tf
        geometry_msgs::TransformStamped odom_trans;
        odom_trans.header.stamp = current_time;
        odom_trans.header.frame_id = "odom";
        odom_trans.child_frame_id = "base_link";

        odom_trans.transform.translation.x = x_total;
        odom_trans.transform.translation.y = y_total;
        odom_trans.transform.translation.z = 0.0;
        odom_trans.transform.rotation = odom_quat;

        //send the transform
        odom_broadcaster.sendTransform(odom_trans);

        //next, we'll publish the odometry message over ROS
        nav_msgs::Odometry odom;
        odom.header.stamp = current_time;
        odom.header.frame_id = "odom";
        odom.child_frame_id = "base_link";

        //set the position
        odom.pose.pose.position.x = x_total;
        odom.pose.pose.position.y = y_total;
        odom.pose.pose.position.z = 0.0;
        odom.pose.pose.orientation = odom_quat;

        //set the velocity
        odom.twist.twist.linear.x = v_x;
        odom.twist.twist.linear.y = v_y;
        odom.twist.twist.angular.z = v_theta;

        //publish the message
        odom_pub.publish(odom);


        tf::TransformBroadcaster broadcaster;

        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::Quaternion(0, 0, 0), tf::Vector3(0.08, 0.0, 0.1)),
                ros::Time::now(), "/base_link", "/base_laser"));

        last_time = current_time;
        r.sleep();
    }
}
