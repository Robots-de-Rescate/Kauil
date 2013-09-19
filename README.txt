Paquetes hasta el momento:
	MD03ARIA - Nodo de la teleoperación y driver de la interfaz I2C.
	Encoder - Definición del mensaje con el que publica Arduino y código que utiliza el microcontrolador.
	Odometry - Calcula y publica la posición absoluta del robot, mensajes (encoder).


Si se va a subir una nueva versión por primera vez, se debe de configurar git para omitir los directorios "bin/" y "build/" de la siguiente manera:
	
	$cd tuCarpetaClonada/.git/info
	$gedit exclude
	Agregar al archivo: bin/
			    build/
	Guardar el archivo.

Puesto que no se esta utilizando utilizando el paquete rosinstall para el manejo del control de versiones (Git), es importante configurar las variables de entorno del archivo .bashrc que se deben establecer en cada sesión de ROS, de la siguiente manera:
	
	$gedit ~/.bashrc
	Agregar al archivo: source /opt/ros/fuerte/setup.bash
			    export ROS_PACKAGE_PATH=~/fuerte_workspace:$ROS_PACKAGE_PATH
 			    export ROS_WORKSPACE=~/fuerte_workspace
	
