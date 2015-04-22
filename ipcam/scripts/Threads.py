import threading
import time
from SimpleCV import Camera, Display, JpegStreamCamera
 
class ThreadingObject(object):
    """ Threading object class

    The run() method will be started and it will run in the background
    until the application exits.
    """
 
    def __init__(self, interval=1, video=False):
        """ Constructor

        :type interval: int
        :param interval: Check interval, in seconds
        """
        self.interval = interval
        self.url = "http://192.168.10.222:1201/videostream.cgi?user=admin&pwd="
        self.ipCam = JpegStreamCamera(self.url)
        self.display = Display()

        thread = threading.Thread(target=self.run, args=(video,))
        thread.daemon = True                            # Daemonize thread
        thread.start()                                  # Start the execution
 
    def run(self, video):
        """ Method that runs forever """
        while not self.display.isDone():
            if video:
                imagen = self.ipCam.live()
            else:
                imagen = self.ipCam.getImage().show()
            time.sleep(self.interval)
        imagen.quit()