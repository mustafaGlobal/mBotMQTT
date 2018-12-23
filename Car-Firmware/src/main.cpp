#include <Arduino.h>
#include "car.hpp"

Car car;

void setup() 
{
  Serial.begin(115200);
  car.begin();
}


void loop() 
{
  int komanda = Serial.parseInt();
  if(komanda == 1)
  {
    car.forward();
    delay(50); 
  }
  else if(komanda == 2)
  {
    car.backward();
    delay(50);
  }
  else if(komanda == 3)
  {
    car.right();
    delay(50);
  }
  else if (komanda == 4)
  {
    car.left();
    delay(50);
  }
  else
  {
    car.stop();
  }

} 