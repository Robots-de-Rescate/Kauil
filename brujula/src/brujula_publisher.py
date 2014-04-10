#!/usr/bin/env python

from struct import unpack
import rospy
from std_msgs.msg import Float32
import serial
import sys

port_name = sys.argv[1]
port = serial.Serial(port_name)

def talker():
    pub = rospy.Publisher('brujula', Float32)
    rospy.init_node('brujula', anonymous=True)
    r = rospy.Rate(10)
    while not rospy.is_shutdown():
        port.write("1") #puede ser cualquier caracter
        byteYaw = port.read(4) 
        floatYaw = unpack('<f', byteYaw)
        pub.publish(floatYaw[0])
        r.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException: pass
