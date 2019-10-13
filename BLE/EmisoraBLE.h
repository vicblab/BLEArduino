
// -------------------------------------------
// EmisoraBLE.h
// Clase encargada de emitir la trama de datos mediante Bluetooth Low Energy
// equipo 5
// autor: Víctor Blanco Bataller
// 13/10/2019
// copyright
// -------------------------------------------

// Se incluye la librería de BLE necesaria
#include <bluefruit.h>  

class EmisoraBLE{
  
  private:

  
// inicializamos la uuid y el nombre del beacon
  uint8_t beaconUUID[16] ={
     'E', 'P', 'S', 'G', '-', 'G', 'T', 'I',
     '-', 'P', 'R', 'O', 'Y', '-', '3', 'A'
     };
     char nombre[16]="GTI-3A-Equipo_5";//{
  
 
  public:

// Constructor vacío
  EmisoraBLE(){
    
    }
    
// -------------------------------------------
//  () -> inicializar() -> ()
// Inicializa Bluefruit y añade le el nombre
// -------------------------------------------
   void inicializar(){

    
     Serial.println("Initialise the Bluefruit nRF52 module");
   Bluefruit.begin();

   //
   // Set the advertised device name (keep it short!)
   //
   Serial.println("Setting Device Name to GTI-3A-Equipo_5 " );

   Bluefruit.setName(nombre);
   Bluefruit.ScanResponse.addName();

    }//inicializar()


// -------------------------------------------
//  temperatura: Z, humedad: Z, medida: Z -> anunciarCO() -> ()
// Se encarga de anunciar la trama con los datos de temperatura, humedad y concentración de CO encapsulados en el major y el minor
// -------------------------------------------

  void anunciarCO(int temperatura, int humedad, int medida){


// El convenio será que el major contiene la temperatura y la humedad y el minor la medición de CO en ppb

  uint16_t elMajor= (uint16_t)100*temperatura+humedad;// Esta manera de meter ambos datos en el major me ha dado menos problemas que ((uint16_t)temperatura << 8) | (uint8_t)humedad;
  uint16_t elMinor=(uint16_t)medida;
  
      Serial.print("\n Major: ");
      Serial.print(elMajor);
      Serial.print("\n Minor: ");
      Serial.print(elMinor);
      
  BLEBeacon elBeacon( beaconUUID, elMajor, elMinor, 73 ); //Creamos el Beacon que contendrá la uuid acordada y el major y el minor con la información necesaria
  
  Bluefruit.Advertising.stop(); // primero detenemos la anunciación anterior para evitar la posiblidad de que siga emitiendo una trama antigua
      
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
         
  Bluefruit.Advertising.addTxPower();
   
  elBeacon.setMajorMinor(elMajor, elMinor);//nos aseguramos de que el major y el minor del beacon son los que tocan (no siempre lo son sin esta linea)
      
  Bluefruit.Advertising.setBeacon(elBeacon); //asignamos el beacon a la trama de advertising
      
  Bluefruit.Advertising.start(); //empezamos a emitir la trama
        
        //descomentar para imprimir todos los datos del advertising uno a uno:
      /*for(int i=1; i<63; i++){
        Serial.print(i);
        Serial.print(": ");
          Serial.print(Bluefruit.Advertising.getData()[i-1]);
          Serial.print("\n");
        }*/
    
    }//anunciarCO()
    
  
  };//class EmisoraBLE




  
