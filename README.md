Robot de Rescate [Kauil](http://www.cem.itesm.mx/cms/kauil/)
==============

Paquetes hasta el momento:
--------------
    
- **MD03ARIA** - Nodo de la teleoperación y driver de la interfaz I2C.
- **Encoder** - Definición del mensaje con el que publica Arduino y código que utiliza el microcontrolador.
- **Odometry** - Calcula y publica la posición absoluta del robot, mensajes de tipo encoder.
- **rosLaunch** - Contiene los archivos .launch necesarios para lanzar los nodos en el robot y la estación remota.

Configuraciones:
--------------

+ Puesto que no se esta utilizando el paquete rosinstall para el manejo del control de versiones (Git), es importante configurar las variables de entorno del archivo .bashrc que se deben establecer en cada sesión de ROS, de la siguiente manera:
	
	<pre><code>$gedit ~/.bashrc
	Agregar al archivo: 
      source /opt/ros/fuerte/setup.bash
      export ROS_PACKAGE_PATH=~/fuerte_workspace:$ROS_PACKAGE_PATH
      export ROS_WORKSPACE=~/fuerte_workspace
    Guardar el archivo.</code></pre>

Esta configuración inicial se describe mas a detalle en el repositorio "extras".

