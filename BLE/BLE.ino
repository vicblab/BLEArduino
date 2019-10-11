
#include "EmisoraBLE.h"
#include "Sensor.h"

Sensor miSensor;
EmisoraBLE miEmisora;
void setup() {
  
  // put your setup code here, to run once:

  miSensor.inicializar();
  miEmisora.inicializar();

}

void loop() {
  
  // put your main code here, to run repeatedly:

  miEmisora.anunciarCO(miSensor.medirTemperatura(),miSensor.medirHumedad(),miSensor.medirCO());
 miSensor.teEsperas(5000);

}
