Paquete rosLaunch
==============

El paquete [roslaunch](http://wiki.ros.org/roslaunch) es una herramienta que nos sirve para levantar multiples nodos de ROS de manera local o remotamente por SSH.

El paquete rosLaunch contiene el archivo *.launch* que tiene como parametros los nodos que se estan utilizando hasta el momento, los cuales son:

* teleoperation_neu - control del robot por medio del teclado.
* driver_neu - información para el modulo I2C (activación de los motores).
* serial_node.py - comunicación con Arduino para la lectura de los encoders.
* odometry_2013 - despliega la ubicación del robot por medio de los encoders.

Para correr el archivo *.launch*: 

	<pre><code>$roslaunch rosLaunch kauilNodes.launch</code></pre>
