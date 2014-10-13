Paquete rosLaunch
==============

El paquete [roslaunch](http://wiki.ros.org/roslaunch) es una herramienta que nos sirve para levantar multiples nodos de ROS de manera local o remotamente por SSH. La computadora del robot Kauil contiene un script que se incializa al prender y ejecutará el archivo *.launch*, por lo que no es necario ejecutar el archivo remotamente por SSH. Cada archivo *.launch* corresponde a una computadora diferente. 

Para correr el archivo *.launch* en el robot Kauil:

<pre><code>$roslaunch rosLaunch/robotKauil.launch</code></pre>

Para correr el archivo *.launch* en la estación remota: 

<pre><code>$roslaunch rosLaunch/estacionRemota.launch</code></pre>
