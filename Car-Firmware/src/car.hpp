#ifndef CAR_HPP
#define CAR_HPP

#include <Arduino.h>

#define LEFTPWMPIN 5
#define LEFTDIRPIN 4
#define RIGHTPWMPIN 6
#define RIGHTDIRPIN 7

class Car
{
  private:
    void motorRight(int speed);
    void motorLeft(int speed);

  public:
    Car() = default;

    void begin();
    void stop();

    void forward(int throttle = 255);
    void backward(int throttle = 255);
    void left(int throttle = 255);
    void right(int throttle = 255);

    void run(int left, int right);

};



#endif