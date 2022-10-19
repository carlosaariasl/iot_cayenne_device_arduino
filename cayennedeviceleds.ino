#include <CayenneMQTTSerial.h>

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
/*
Este ejemplo muestra cómo conectarse a Cayenne mediante una conexión USB serie y enviar/recibir datos de muestra.

Se requiere la biblioteca CayenneMQTT para ejecutar este boceto. Si aún no lo ha hecho, puede instalarlo desde Arduino IDE Library Manager.

Esto requiere el uso de la conexión USB serie, por lo que no puede utilizar el dispositivo serie para
imprimiendo mensajes. Si necesita imprimir, puede usar SoftwareSerial y conectar otro dispositivo
para leer mensajes a través de los pines SoftwareSerial.

Para que esto funcione, debe ejecutar el script de conexión en la máquina a la que está conectado el Arduino.
Los scripts se encuentran en la carpeta extras\scripts en la carpeta de la biblioteca principal. Esto redirige el tráfico.
del Arduino al servidor Cayenne.

Pasos:
1. Configure la información de autenticación de Cayenne para que coincida con la información de autenticación del Tablero.
2. Compile y cargue este boceto.
3. Inicie el script de conexión como se describe a continuación para Windows o Linux/OSX.

Ventanas:
1. Abra la línea de comandos de Windows (cmd.exe)
2. Navegue a la carpeta de scripts escribiendo "cd [ruta]", p. "cd C:\Users\[Su nombre de usuario]\Documentos\Arduino\libraries\CayenneMQTT\extras\scripts"
3. Ejecute el script escribiendo "cayenne-ser.bat -c COM4" (donde COM4 es el puerto serial de Arduino) y presionando Enter

Linux y OSX:
    ./cayenne-ser.sh (es posible que deba ejecutarse con sudo)
    
Puede especificar el puerto, la velocidad en baudios y el punto final del servidor de esta manera:
    ./cayenne-ser.sh -c <puerto serie> -b <tasa de baudios> -s <dirección del servidor> -p <puerto del servidor>

    Por ejemplo :
      ./cayenne-ser.sh -c /dev/ttyACM0 -b 9600 -s mqtt.mydevices.com -p 1883

    Ejecute cayenne-ser.sh -h para obtener más información

    Asegúrese de seleccionar el puerto serie correcto (puede haber varios).

¡ATENCIÓN!
No use Serial para mostrar ninguna salida en este boceto. Interferirá con la serie.
Conexión USB. Al cargar bocetos, el IDE de Arduino puede quejarse con "el programador está
no responde" o "Acceso denegado". Deberá finalizar el script de conexión
antes de cargar nuevos bocetos ya que bloquea el acceso al puerto Serial. También asegúrese de
el Serial Monitor está deshabilitado en el IDE ya que eso puede evitar que Arduino
conectarse a la máquina Windows/Linux/OSX. Si usa Visual Micro para Visual Studio, haga
Asegúrese de que la depuración automática esté deshabilitada. De lo contrario, el monitor serie puede interferir con el
Conexión en serie.
*/

char username[] = "543b26f0-7053-11e9-be3b-372b0d2759ae";
char password[] = "b05a702ec80af6c67dbbe5b16f096536737d752b";
char clientID[] = "875c89d0-4fbf-11ed-baf6-35fab7fd0ac8";

int led1 = 50;
int led2 = 51;
int led3 = 52;
int led4 = 53;

void setup() {
  Cayenne.begin(username, password, clientID);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void loop() {
  Cayenne.loop();
}


CAYENNE_IN(0) {
  digitalWrite(led1, !getValue.asInt());
}

CAYENNE_IN(1) {
  digitalWrite(led2, !getValue.asInt());
}

CAYENNE_IN(2) {
  digitalWrite(led3, !getValue.asInt());
}

CAYENNE_IN(3) {
  digitalWrite(led4, !getValue.asInt());
}
