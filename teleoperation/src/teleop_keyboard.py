#!/usr/bin/env python
import sys, tty, termios, rospy
from teleoperation.msg import Motors

def removeLine():
	print '\r',
	print '                                                            ',
	print '\r',

def talker():
	pubMotors = rospy.Publisher('MD03ARIA_Values', Motors)
	rospy.init_node('Teleoperation',anonymous = True)
	#r = rospy.Rate(50)
	vel = [0,0,0,0]
	while not rospy.is_shutdown():
		chr = sys.stdin.read(1)
		removeLine()
		if chr == '\x1b':
			chr2 = sys.stdin.read(2)
			if chr2 == '[A': #Up
				vel[0]= vel[0] + 30
                                vel[1]= vel[1] + 30
				if vel[0] != vel[1] or (vel[0]>-100 and vel[0]<100):
					vel[0]=100
					vel[1]=100
				elif vel[0]>250:
					vel[0] = 250
					vel[1] = 250
					
				pubMotors.publish(vel[0],vel[1])
			
			elif chr2 == '[B': #Down

				vel[0]= vel[0] - 30
                                vel[1]= vel[1] - 30
                                if vel[0] != vel[1] or (vel[0]>-100 and vel[0]<100):
                                        vel[0]= -100
                                        vel[1]= -100
                                elif vel[0]<-250:
                                        vel[0] = -250
                                        vel[1] = -250
                                pubMotors.publish(vel[0],vel[1])
	
			elif chr2 == '[C': #Right
				vel[1]= vel[1] - 30
                                vel[0]= vel[0] + 30

				if  vel[0]<100 or vel[1]>-100:
                                        vel[0] = 100 
                                        vel[1] = -100
                                if vel[1]<-250 or vel [0]>250:
                                        vel[0] = 250
                                        vel[1] = -250
                                
                                pubMotors.publish(vel[0],vel[1])
                              
			elif chr2 == '[D': #Left
                                
				vel[1]= vel[1] + 30
                                vel[0]= vel[0] - 30

                                if vel[1] < 100 or vel[0] > -100:
                                        vel[0] = -100
                                        vel[1] = 100
                                if vel[0] < -250 or vel[1] > 250:
                                        vel[1] = 250
                                        vel[0] = -250
                                pubMotors.publish(vel[0],vel[1])

                              
			if vel[0] >= 100 and vel[1] >= 100:
				print 'Moving Forward at: ' + str(vel[0]*.4) + '% power',
			elif vel[0] <=-100 and vel[1] <= -100:
				print 'Moving Backward at: ' + str(vel[0]*-.4) + '% power',
			elif vel[0]>vel[1]:
				print 'Turning Right at: ' + str(vel[0]*.4) + '% power',
			elif vel[0]<vel[1]:
				print 'Turning Left at: ' + str(vel[1]*.4) + '% power',
		elif chr == 'q':
			pubMotors.publish(0,0)
			termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)#Return tty to original settings, this will let us use the tty as we normally use it
	 	elif chr == 's':
			pubMotors.publish(0,0)

if __name__ == '__main__':
	fd = sys.stdin.fileno() #File descriptor of the interpreter input
	old_settings = termios.tcgetattr(fd) #List with tty attributes of the file descriptor
	tty.setraw(fd) #Mode of the file d
	print '\r_______________________________________________'
	print '\rPress (q) to exit tty raw mode.'
	print '\rPress (s) to stop Kauil.'
	print '\rUse arrow keys to move kauil.\n\rPress the same arrow key to increase velocity.'
	print '\r________________________________________________\n'

	try:
		talker()
	except rospy.ROSInterruptException:pass

