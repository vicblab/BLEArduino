#include <bluefruit.h>  

class EmisoraBLE{
  private:

  

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

  // elBeacon.setUuid( beaconUUID);
    
     Serial.println("Initialise the Bluefruit nRF52 module");
   Bluefruit.begin();

   //
   // Set the advertised device name (keep it short!)
   //
   Serial.println("Setting Device Name to GTI-3A " );

   Bluefruit.setName(nombre);
   Bluefruit.ScanResponse.addName();
   //Bluefruit.Advertising.start();
   //Bluefruit.Advertising.setBeacon(elBeacon);
   anunciarCO(0,0,0);
    }

   void anunciarCO(int temperatura, int humedad, int medida){

 // temperatura=0;
  //humedad=0;
  //medida=0;

  uint16_t elMajor= (uint16_t)100*temperatura+humedad;//((uint16_t)temperatura << 8) | (uint8_t)humedad;
  uint16_t elMinor=(uint16_t)medida;
  //elMajor=(uint16_t)char(elMajor);
   //elMinor=(uint16_t)char(elMinor);
      Serial.print("\n Major: ");
      Serial.print(elMajor);
      Serial.print("\n Minor: ");
      Serial.print(elMinor);
      
  BLEBeacon elBeacon( beaconUUID, elMajor, elMinor, 73 );
      Bluefruit.Advertising.stop(); // ya lo enchufo luego
         Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
   Bluefruit.Advertising.addTxPower();
      elBeacon.setMajorMinor(elMajor, elMinor);
      Bluefruit.Advertising.setBeacon(elBeacon);
        Bluefruit.Advertising.start();
        
        //descomentar para imprimir todos los datos del advertising uno a uno:
      /*for(int i=1; i<62; i++){
        Serial.print(i);
        Serial.print(": ");
          Serial.print(Bluefruit.Advertising.getData()[i-1]);
          Serial.print("\n");
        }*/
    
    };
  
  };
