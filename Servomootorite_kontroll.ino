

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();                  

#define SERVOMIN  279                                                     
#define SERVOMAX  415                                                     
uint8_t servoNum = 0;                                                     
uint8_t servoCount = 2;                                                   

void setup() {
  Serial.begin(9600);                                                     
  Serial.println("Plow is starting up");                                  
  pwm.begin();                                                            
  pwm.setPWMFreq(60);                                                     
  delay(10);                                                              
}

void loop() {
  Serial.println(servoNum);                                           
  
  for(uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    
    pwm.setPWM(servoNum, 0, pulselen);
  }

  delay(500);
  for(uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(servoNum, 0, pulselen);
  }

  delay(500);

  if (servoNum == servoCount -1) {
    servoNum = 0;
  } else {
    servoNum ++;
  }
}
