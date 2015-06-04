<h3>IPCAM</h3>
<br>
<span>
El siguiente es el paquete de la cámara IP de ROS. La finalidad de este proyecto fue la de
 poder tener un control real o casi real de la cámara IP a partir de nodos de ROS. Existen varios
 métodos que se pueden utilizar, pero dado que el proyecto ya tiene una interfaz de comunicación
 se decidió construir encima el módulo de la cámara IP.
</span>
<br>
<span>
El módulo está basado en SimpleCV, un wrapper de python para OpenCV. El mismo, se conectó con ROS, en
particular con la librería rospy.
<br>
IPCAM funciona básicamente con dos programas de python que se deben correr, uno en la instancia
remota: listener.py y el otro en la instancia local: talkerSCV.py. El programa de listener
básicamente escucha los comandos del teclado de talker para poder llevar a cabo instrucciones con
la cámara IP. Es decir, cuando el usuario decide teclear una letra que moverá la cámara, talkerSCV
envía esta char a listener que lo interpreta y traduce a un comando http que la cámara pueda entender.
La otra parte del programa se basa en el video. cuando talkerSCV,py recibe un comando de snapshot
o video, le pide a la cámara a través de SimpleCV que le envie directamente el video. Esta parte
no esta implementada por ROS por motivos de compatibilidad y de latency que puede sufrir la comunicación
puesto que se estaría metiendo un protocolo de comunicación que es ROS sobre otro que es SimpleCV.

</span>