#!/usr/bin/env python

import serial
from struct import unpack, pack
import rospy
import sys
from STM32_USB.msg import Encoder, Battery, Compass, Motors
flag = 0
port_name = sys.argv[1]
serial = serial.Serial(port_name)

#If this ROS node stops sending or receiving data, add a sempahore to prevent using at the same time the serial port for sending and receiving data

def callback(Motors):
	data = pack('<ciif','m',Motors.MotorLeft, Motors.MotorRight,0.0)
	serial.write(data)

def main():
	pubEncoder = rospy.Publisher('Encoder', Encoder) # Topic with name Encoder and message encoder (int32)
	pubBattery = rospy.Publisher('Battery', Battery) # Topic with name Battery and message battery (int32)
	pubCompass = rospy.Publisher('Compass', Compass) # Topic with name Compass and message compass (float32)
	sunbMotors = rospy.Subscriber("MD03_Values", Motors, callback) #Subscriber to the topic of the teleoperation node 
	rospy.init_node('STM32_USB') # Node with name STM32_USB
	while not rospy.is_shutdown():
		data = serial.read(13)
		structData = unpack('<ciif',data)
	
		if structData[0] == 'e':
			pubEncoder.publish(structData[1],structData[2])
		elif structData[0] == 'b':
			pubBattery.publish(structData[1])
		elif structData[0] == 'c':
			pubCompass.publish(structData[3])

if __name__ == '__main__':
	try: 
		main()
	except rospy.ROSInterruptException: pass



