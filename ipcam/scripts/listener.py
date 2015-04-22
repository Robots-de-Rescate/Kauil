#!/usr/bin/env python
"""
This is the listener of the ipcam, it should be run on the remote kauil station.
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

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
    char = data.data
    sleep_time = 1
    url = "http://192.168.10.222:1201/snapshot.cgi?user=admin&pwd="
    ipCam = ipCamera(url)
    generic_command_url = "http://192.168.10.222:1201/decoder_control.cgi?command={0}&user=admin&pwd="
    stop = generic_command_url.format(1)
    up = generic_command_url.format(0)
    down = generic_command_url.format(2)
    left = generic_command_url.format(4)
    right = generic_command_url.format(6)
    home = generic_command_url.format(25)

    if char=='i':
        print urllib2.urlopen(up)
        time.sleep(sleep_time)
        print urllib2.urlopen(stop)

    elif char=='k':
        print urllib2.urlopen(down)
        time.sleep(sleep_time)
        print urllib2.urlopen(stop)

    elif char=='j':
        print urllib2.urlopen(right)
        time.sleep(sleep_time)
        print urllib2.urlopen(stop)

    elif char=='l':
        print urllib2.urlopen(left)
        time.sleep(sleep_time)
        print urllib2.urlopen(stop)

    elif char=='q':
        print urllib2.urlopen(home)
        time.sleep(sleep_time)
        print urllib2.urlopen(stop)



def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # node are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'talker' node so that multiple talkers can
    # run simultaneously.
    rospy.init_node('ipcam', anonymous=True)

    rospy.Subscriber("ipcam", String, callback)




    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()

