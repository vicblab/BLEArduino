#include <bluefruit.h>  
#define RX_PIN 15
#define TX_PIN 17
class Sensor{
  private:

  // Definicion de los pines UART


char sensorData [11]={NULL};
 int medida=-1;
 int temperatura=-1;
 int humedad=-1;
void parsearDatos(){
  
}

//Recibe los datos
// El string de datos está separado por comas
// El formato de output es: SN[XXXXXXXXXXXX], PPB[0:999999], TEMP[-99:99],
// Humedad relativa[0:99], RawSensor[ADCCount], TempDigital,Dia[0:99], hora[0:23],minuto[0:59], segundo[0:59], \r\n
//
   void cacharroDimeloTodo(){
 
    //////////////////////////////////////////////////////////////////////////
// Recibe una cadena del sensor digital en forma de secuencia ASCII.
//////////////////////////////////////////////////////////////////////////

Serial1.print('\r'); // Inicia una lectura del sensor. Ahora hay que espera a que nos envíe algo de vuelta!
Serial.println("\n Lectura del sensor iniciada...esperando...");
  
   //
    String misDatosEnBruto=
Serial1.readStringUntil('\r');
Serial.println(misDatosEnBruto);

int Indice0 =misDatosEnBruto.indexOf(',');
//  Search for the next comma just after the first
int Indice1 = misDatosEnBruto.indexOf(',', Indice0 + 1);
int Indice2 = misDatosEnBruto.indexOf(',', Indice1 + 1);
int Indice3 = misDatosEnBruto.indexOf(',', Indice2 + 1);

 String ppb = misDatosEnBruto.substring(Indice0+1, Indice1);
String temp = misDatosEnBruto.substring(Indice1 + 1, Indice2);
String hum = misDatosEnBruto.substring(Indice2 + 1, Indice3); // To the end of the string

  //int algo=atoi(sensorData);
//r (int j=0; j<11; j++) {
  
 //erial.println(sensorData[j]);}
 //erial.println(algo);
    //comentar algo

    medida=ppb.toInt();
    temperatura=temp.toInt();
    humedad=hum.toInt();
      Serial.print("\n \n medida ppb: ");
      Serial.print(medida);
      Serial.print("\n");
      Serial.print("temperatura: ");
      Serial.print(temperatura);
      Serial.print("\n humedad: ");
      Serial.print(humedad);
      }
  
  public:
Sensor(){}

   void inicializar(){
  //inicia el sensor y demás
  Serial.begin(9600); // Serial is the USB serial port
   while ( !Serial ) delay(10);   // for nrf52840 with native usb
Serial1.begin(9600); // Puerto serie hardware para comunicación con el sensor, 8 bit, no parity, 1 stop bit, 3.3V

 
    }
void teEsperas(int milis){
   //Serial.print(medirCO());
  delay(milis);
}

  int medirCO(){
    //cacharroDimeloTodo();
    return medida;
    }
    int medirTemperatura(){
    cacharroDimeloTodo();
    return temperatura;
    }
   int medirHumedad(){
   // cacharroDimeloTodo();
    return humedad;
    }
  };
