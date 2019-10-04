#include <bluefruit.h>  

class EmisoraBLE{
  private:

  BLEUart bleuart;
   uint8_t beaconUUID[16]={NULL};/* = {
     'E', 'P', 'S', 'G', '-', 'G', 'T', 'I',
     '-', 'P', 'R', 'O', 'Y', '-', '3', 'A'
     };*/
  
  
  public:

  EmisoraBLE(uint8_t *(beaconUUID_), char nombre[24]){
      // Initialise the Bluefruit module
   //
   Serial.println("Initialise the Bluefruit nRF52 module");
   Bluefruit.begin();

   //
   // Set the advertised device name (keep it short!)
   //
   Serial.println("Setting Device Name to GTI-3A " );

   Bluefruit.setName(nombre);
   Bluefruit.ScanResponse.addName();
    }

    void anunciarX(uint8_t elMajor, uint8_t elMinor){

       BLEBeacon elBeacon( beaconUUID, 12, 34, 73 );
      Bluefruit.Advertising.stop(); // ya lo enchufo luego
      elBeacon.setMajorMinor(elMajor, elMinor);
      Bluefruit.Advertising.setBeacon(elBeacon);
    }
  
  };
