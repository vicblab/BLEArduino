#include <bluefruit.h>  

class Sensor{
  private:

  
 double medida=-1;
 double temperatura=-1;
 double humedad=-1;

   void cacharroDimeloTodo(){
    //comentar algo
    double algo=1234;
    medida=algo;
    temperatura=algo;
    humedad=algo;
      
      }
  
  public:
Sensor(){}

   void inicializar(){
  //inicia el sensor y demás
   
    }

  double medirCO(){
    cacharroDimeloTodo();
    return medida;
    }
    double medirTemperatura(){
    cacharroDimeloTodo();
    return temperatura;
    }
   double medirHumedad(){
    cacharroDimeloTodo();
    return humedad;
    }
  };
