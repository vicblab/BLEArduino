#include <bluefruit.h>  

class Sensor{
  private:

  
 int medida=-1;
 int temperatura=-1;
 int humedad=-1;

   void cacharroDimeloTodo(){
    //comentar algo
    int algo=123;
    medida=algo;
    temperatura=algo;
    humedad=algo;
      
      }
  
  public:
Sensor(){}

   void inicializar(){
  //inicia el sensor y demás
   
    }

  int medirCO(){
    cacharroDimeloTodo();
    return medida;
    }
    int medirTemperatura(){
    cacharroDimeloTodo();
    return temperatura;
    }
   int medirHumedad(){
    cacharroDimeloTodo();
    return humedad;
    }
  };
