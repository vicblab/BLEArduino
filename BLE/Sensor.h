// -------------------------------------------
// Sensor.h
// Clase encargada de leer tramas del sensor de CO y obtener de ellas los valores de CO, temperatura y humedad
// equipo 5
// autor: Víctor Blanco Bataller
// 13/10/2019
// copyright
// -------------------------------------------
#include <bluefruit.h>  

class Sensor{
  
  private:



 int medida=-1;
 int temperatura=-1;
 int humedad=-1;


// -------------------------------------------
//  () -> cacharroDimeloTodo() -> ()
// Actualiza los datos de medida, temperatura y humedad obteniendo los últimos valores de dichos datos 
// a partir de los datos que consigue de la trama que le devuelve el sensor de CO por Serial
// -------------------------------------------

// Información importante sobre la trama recibida del sensor:
// Recibe los datos
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
  
 //leemos del Serial1 los datos en bruto que nos llegan del sensor hasta que encontramos el caracter "\r", el cual sabemos que se envía al final de la transmisión de los datos
    String misDatosEnBruto=
  Serial1.readStringUntil('\r');
  Serial.println(misDatosEnBruto);

// solo nos interesan el segundo (ppb), el tercer (temp) y el cuarto (hum) elementos de los que vienen en el string de datos en bruto separados por comas
  int Indice0 =misDatosEnBruto.indexOf(',');
//  busca la siguiente coma después de la primera...
  int Indice1 = misDatosEnBruto.indexOf(',', Indice0 + 1);
  int Indice2 = misDatosEnBruto.indexOf(',', Indice1 + 1);
  int Indice3 = misDatosEnBruto.indexOf(',', Indice2 + 1);

// obtenemos los substrings que nos interesan del string de datos en bruto y los guardamos en variables
  String ppb = misDatosEnBruto.substring(Indice0+1, Indice1);
  String temp = misDatosEnBruto.substring(Indice1 + 1, Indice2);
  String hum = misDatosEnBruto.substring(Indice2 + 1, Indice3); 

 // finalmente actualizamos los valores privados de medida, temperatura y humedad
    medida=ppb.toInt();
    temperatura=temp.toInt();
    humedad=hum.toInt();

    // imprimimos lo que nos interesa en pantalla
      Serial.print("\n \n medida ppb: ");
      Serial.print(medida);
      Serial.print("\n");
      Serial.print("temperatura: ");
      Serial.print(temperatura);
      Serial.print("\n humedad: ");
      Serial.print(humedad);
      
      }//cacharroDimeloTodo()

      
  
  public:


  //Constructor vacío
    Sensor(){}
    
// -------------------------------------------
//  () -> inicializar() -> ()
// Inicializa los Serial
// -------------------------------------------
   void inicializar(){
  //inicia el sensor y demás
  Serial.begin(9600); // Serial is the USB serial port
   while ( !Serial ) delay(10);   // for nrf52840 with native usb
Serial1.begin(9600); // Puerto serie hardware para comunicación con el sensor, 8 bit, no parity, 1 stop bit, 3.3V

 
    }// inicializar()



    // -------------------------------------------
//  milis:Z -> teEsperas() -> ()
// Espera un tiempo dado de milisegundos
// -------------------------------------------
  void teEsperas(int milis){
   
  delay(milis);
  }//teEsperas()




// -------------------------------------------
//  () -> medirCO() -> medida:Z
// devuelve la última medida de concentración de CO
// -------------------------------------------
  int medirCO(){
   
    return medida;
    }//medirCO()




    // -------------------------------------------
//  () -> medirTemperatura() -> temperatura:Z
// devuelve la última medida de temperatura
// -------------------------------------------
    int medirTemperatura(){
      
    cacharroDimeloTodo();//llamamos solamente aquí a cacharroDimeloTodo() porque esta función es la que antes se invoca de esta clase en el loop
    
    return temperatura;
    }//medirTemperatura()




    // -------------------------------------------
//  () -> medirHumedad() -> humedad:Z
// devuelve la última medida de humedad
// -------------------------------------------
   int medirHumedad(){
   
    return humedad;
    }//medirHumedad()

    
  }; //class Sensor


  
