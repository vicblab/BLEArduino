// -------------------------------------------
// BLE.ino
// Programa principal encargado de emitir una trama a través de BLE con los datos de concentración de CO, temperatura y humedad
// equipo 5
// autor: Víctor Blanco Bataller
// 13/10/2019
// copyright
// -------------------------------------------

//Se incluyen los archivos que contienen las clases necesarias

#include "EmisoraBLE.h"
#include "Sensor.h"


// --------------------------------------
// variables globales 
// --------------------------------------
  Sensor miSensor;
  EmisoraBLE miEmisora;



  // -------------------------------------------
//  () -> setup() -> ()
// Código que se ejecuta solo una vez
// -------------------------------------------
  void setup() {
  
  // put your setup code here, to run once:

  miSensor.inicializar();
  
  miEmisora.inicializar();

  }//setup()



  
// -------------------------------------------
//  () -> loop() -> ()
// Código que se ejecuta repetidamente
// -------------------------------------------
  void loop() {
  
  

  miEmisora.anunciarCO(miSensor.medirTemperatura(),miSensor.medirHumedad(),miSensor.medirCO());
  
  miSensor.teEsperas(5000);

  }//loop()


  
