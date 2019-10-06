#include <bluefruit.h>  

class EmisoraBLE{
  private:

  
  BLEBeacon elBeacon;
   uint8_t beaconUUID[16] ={
     'E', 'P', 'S', 'G', '-', 'G', 'T', 'I',
     '-', 'P', 'R', 'O', 'Y', '-', '3', 'A'
     };
     char nombre[16]="GTI-3A-Equipo_5";//{
      //'G','T','I','-','3','A','-','E','q','u','i','p','o','_','0','5'
      //};
  
  
  public:

  EmisoraBLE(){
    
    }

   void inicializar(){

   elBeacon.setUuid( beaconUUID);
    
     Serial.println("Initialise the Bluefruit nRF52 module");
   Bluefruit.begin();

   //
   // Set the advertised device name (keep it short!)
   //
   Serial.println("Setting Device Name to GTI-3A " );

   Bluefruit.setName(nombre);
   Bluefruit.ScanResponse.addName();
    }

   void anunciarX(uint8_t temperatura, uint8_t humedad, uint8_t medida){

  uint16_t elMajor=((uint16_t)temperatura << 8) | humedad;
  uint16_t elMinor=(uint16_t)medida;
  
      
      Bluefruit.Advertising.stop(); // ya lo enchufo luego
      elBeacon.setMajorMinor(elMajor, elMinor);
      Bluefruit.Advertising.setBeacon(elBeacon);
    };
  
  };
