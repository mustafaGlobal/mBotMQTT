#include "car.hpp"

void Car::begin()
{
  pinMode(LEFTDIRPIN,OUTPUT);
  pinMode(LEFTPWMPIN,OUTPUT);
  pinMode(RIGHTDIRPIN,OUTPUT);
  pinMode(RIGHTPWMPIN,OUTPUT);
}

void Car::motorRight(int speed)
{
  speed = speed > 255 ? 255 : speed;
  speed = speed < -255 ? -255 : speed;
  if(speed>=0)
  {
    digitalWrite(RIGHTDIRPIN, HIGH);
    analogWrite(RIGHTPWMPIN,speed);
  }
  else
  {
    digitalWrite(RIGHTDIRPIN, LOW);
    analogWrite(RIGHTPWMPIN, -speed);
  }
}

void Car::motorLeft(int speed)
{
  speed = speed > 255 ? 255 : speed;
  speed = speed < -255 ? -255 : speed;
  speed = -speed; // Inverted on the PCB
  if(speed>=0)
  {
    digitalWrite(LEFTDIRPIN, HIGH);
    analogWrite(LEFTPWMPIN,speed);
  }
  else
  {
    digitalWrite(LEFTDIRPIN, LOW);
    analogWrite(LEFTPWMPIN, -speed);
  }
}

void Car::run(int left, int right)
{
  motorLeft(left);
  motorRight(right);
}

void Car::forward(int throttle)
{
  motorLeft(throttle);
  motorRight(throttle);
}

void Car::backward(int throttle)
{
  motorLeft(-throttle);
  motorRight(-throttle);
}

void Car::left(int throttle)
{
  motorLeft(-throttle/10);
  motorRight(throttle);
}

void Car::right(int throttle)
{
  motorLeft(throttle/10);
  motorRight(-throttle);
}

void Car::stop()
{
  motorLeft(0);
  motorRight(0);
}
