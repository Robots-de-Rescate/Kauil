Robot de Rescate [Kauil](https://github.com/Robots-de-Rescate/wiki_general/wiki/Kauil)
==============

Paquetes hasta el momento:
--------------

- **Odometry** - Calcula y publica la posición absoluta del robot, mensajes de tipo encoder.
- **rosLaunch** - Contiene los archivos .launch necesarios para lanzar los nodos en el robot y la estación remota.
- **MLX90620** - Contiene la interfaz gráfica del sensor térmico de los datos obtenidos por medio de la subscripcion al tópico que publica el microcontrolador.
- **STM32_USB** - Contiene el nodo encargado de la comunicación entre el microcontrolador STM32 y ROS.
- **teleoperation** - Contiene el nodo encargado de la teleoperación del robot.
- **kauil_tf** - Realiza las transformaciones de las coordenadas.  

**Encrontrará una mayor descripción del paquete en el README.md de la carpeta correspondiente al paquete**

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

