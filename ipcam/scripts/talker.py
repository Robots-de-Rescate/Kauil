#!/usr/bin/env python
"""
Talker program that tells the listener the action the camera should do and asks the camera the snapshot
"""

import base64
import time
import urllib2
import cv2
import numpy as np
import getch
import rospy
from std_msgs.msg import String

class ipCamera(object):

    def __init__(self, url, user=None, password=None):
        self.url = url
        auth_encoded = base64.encodestring('%s:%s' % (user, password))[:-1]

        self.req = urllib2.Request(self.url)
        self.req.add_header('Authorization', 'Basic %s' % auth_encoded)

    def get_frame(self):
        response = urllib2.urlopen(self.req)
        img_array = np.asarray(bytearray(response.read()), dtype=np.uint8)
        frame = cv2.imdecode(img_array, 1)
        return frame


class Camera(object):

    def __init__(self, camera=0):
        self.cam = cv2.VideoCapture(camera)
        if not self.cam:
            raise Exception("Camera not accessible")

        self.shape = self.get_frame().shape

    def get_frame(self):
        _, frame = self.cam.read()
        return frame

def talker():
    pub = rospy.Publisher('ipcam', String)
    rospy.init_node('ipcam', anonymous=True)
    #rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        print "Press i to move up the camera\n" \
          "Press k to move down the camera\n" \
          "Press j to move right the camera\n" \
          "Press l to move left the camera\n" \
          "Press q to home position the camera\n" \
          "Press s to get another snapshot\n" \
          "Press v to get video\n\n"
        char = getch.getche()

        if char == 's':
            url = "http://192.168.10.222:1201/snapshot.cgi?user=admin&pwd="
            ipCam = ipCamera(url)

            frame = ipCam.get_frame()
            cv2.imshow('Frame Captured', frame)

            k = cv2.waitKey(0)
            if k == ord('q'):         # wait for ESC key to exit
                cv2.destroyAllWindows()
            elif k == ord('s'): # wait for 's' key to save and exit
                cv2.imwrite('frameCaptured.png',frame)
                cv2.destroyAllWindows()


        elif char =='v':
            url = "http://192.168.10.222:1201/snapshot.cgi?user=admin&pwd="
            ipCam = ipCamera(url)
            k = None
            while k != ord('q'):
                time.sleep(1)
                cv2.destroyAllWindows()
                frame = ipCam.get_frame()
                print "capturing"
                cv2.imshow('Video Captured', frame)
                cv2.waitKey(0)

            cv2.destroyAllWindows()


        else:
            rospy.loginfo(char)
            pub.publish(char)

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
