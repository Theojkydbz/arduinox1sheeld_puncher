

#define CUSTOM_SETTINGS
#define INCLUDE_ACCELEROMETER_SENSOR_SHIELD
#include <Servo.h>
/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the LED on pin 13. */
int ledPin = 13;


int incli_a;
int incli_l;
Servo servo_rb1_l;
Servo servo_rb1_a;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
  
  servo_rb1_l.attach(5);                //  Servos initialization
  servo_rb1_a.attach(3);
}

void loop()
{ incli_l = map(AccelerometerSensor.getX(),8,-8,0,180);
  incli_a = map(AccelerometerSensor.getY(),10,0,0,90);
  servo_rb1_a.write(incli_a);
  servo_rb1_l.write(incli_l);
}
