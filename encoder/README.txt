Este paquete define el mensaje encoder.msg por medio del cual se comunica la cantidad de pulsos medidos en el arduino durante aproximadamente 100ms, incluye los parámetros izq y der, además de el código fuente para el IDE del arduino en la carpeta src.

Para poder bajar el código al arduino es necesario tener instalado el ide de arduino (sudo apt-get install arduino) y haberlo configurado de la forma que indica el tutorial "Arduino IDE setup" (http://www.ros.org/wiki/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup), además de ejecutar el siguiente comando para crear el header file encoder.h necesario en el IDE:

	rosrun rosserial_client make_library.py ~/sketchbook/libraries encoder

(suponiendo que la carpeta sketchbook del IDE del arduino se encuentra en el directorio home)
