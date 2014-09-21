#!/usr/bin/env python

import serial
from struct import unpack
import rospy
import sys
from STM32_USB import Encoder, Battery, Compass

port_name = sys.argv[1]
serial = serial.Serial(port_namC)

def talker():
	pubEncoder = rospy.Publisher('Encoder', encoder) # Topic with name Encoder and message encoder (int32)
	pubBattery = rospy.Publisher('Battery', battery) # Topic with name Battery and message battery (int32)
	pubCompass = rospy.Publisher('Compass', compass) # Topic with name Compass and message compass (float32)
	rospy.init_node('STM32_USB') # Node with name STM32_USB
	r = rospy.Rate(10) #Hz
	while not rospy.is_shutdown():
		data = serial.read(13)
		structData = unpack('<ciif',data)

		if structData[0] == 'a':
			pubEncoder.publish(structData[1])
		elif structData[0] == 'b':
			pubBattery.publish(structData[1])
		elif structData[0] == 'c':
			pubCompass.publish(structData[2])
		r.sleep()

if __name__ == '__main__':
	try: 
		talker()
	except rospy.ROSInterruptException: pass



