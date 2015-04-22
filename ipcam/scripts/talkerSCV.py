#!/usr/bin/env python
"""
Talker program that tells the listener the action the camera should do and asks the camera the snapshot
"""

import base64
import time
import urllib2
import cv2
from SimpleCV import Camera, Display
import numpy as np
import getch
import rospy
import threading
from std_msgs.msg import String
from kbhit import KBHit
from SimpleCV import Camera, Display, JpegStreamCamera

def getImage(video):
    url = "http://192.168.10.222:1201/videostream.cgi?user=admin&pwd="
    ipCam = JpegStreamCamera(url)
    display = Display()
    if video==False:
        imagen = ipCam.getImage().show()
        while not display.isDone():
            pass

    else:
        while not display.isDone():

            imagen = ipCam.getImage()
            faces = imagen.findHaarFeatures('face')
            if faces is not None:
                faces = faces.sortArea()
                bigFace = faces[-1]
                # Draw a green box around the face
                bigFace.draw()
            #imagen = ipCam.live()
            imagen.save(display)

    imagen.quit()

def talker():
    lista_threads= []
    pub = rospy.Publisher('ipcam', String)
    rospy.init_node('ipcam', anonymous=True)
    #rate = rospy.Rate(10) # 10hz
    kbhit = KBHit()
    print "Press i to move up the camera\n" \
      "Press k to move down the camera\n" \
      "Press j to move right the camera\n" \
      "Press l to move left the camera\n" \
      "Press q to home position the camera\n" \
      "Press s to get another snapshot\n" \
      "Press v to get video\n\n"
    try:
        while not rospy.is_shutdown():
            if kbhit.kbhit():
                print "Press i to move up the camera\n" \
                  "Press k to move down the camera\n" \
                  "Press j to move right the camera\n" \
                  "Press l to move left the camera\n" \
                  "Press q to home position the camera\n" \
                  "Press s to get another snapshot\n" \
                  "Press v to get video\n\n"
                char = kbhit.getch()

                if char == 's':
                    thread=threading.Thread(target=getImage, args=(False,))
                    thread.start()
                    time.sleep(1)
                    lista_threads.append(thread)
                elif char =='v':
                    thread=threading.Thread(target=getImage, args=(True,))
                    thread.start()
                    time.sleep(1)
                    lista_threads.append(thread)

                else:
                    rospy.loginfo(char)
                    pub.publish(char)
                char = ""
            time.sleep(1)

    except KeyboardInterrupt:

        for each in lista_threads:
            while each.isAlive():
                pass


if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
