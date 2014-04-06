#!/usr/bin/env python
import rospy
from std_msgs.msg import Int16MultiArray


def callback(data):
#	rospy.loginfo(data.data)
	#for i in range(len(data.data)):
        	#rospy.loginfo("Dato entrante: " + str( data.data[i]))
orospy.loginfo("Recibi dato")		
def listener():
        rospy.init_node('listener', anonymous=True)
        rospy.Subscriber("chatter", Int16MultiArray, callback)
	rospy.loginfo("---")
        rospy.spin()

if __name__ == '__main__':
        rospy.loginfo("main..................................")
	listener()



