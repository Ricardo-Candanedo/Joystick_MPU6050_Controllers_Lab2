// <MPU6050_tockn.h> library gotten from Arduino site, used for getting the angles 
// for the gyroscope (only X and Y needed), references found for this library here:
// https://www.arduino.cc/reference/en/libraries/mpu6050_tockn/
// https://github.com/tockn/MPU6050_tockn
#include <MPU6050_tockn.h>

// <Wire.h> library used from the example provided by Elegoo for the MPU-6050
#include <Wire.h>
MPU6050 mpu(Wire);

// digital pin output for the buzzer when an apple is eaten, used in joystick program
// as well

const int buzzer_output = 3; 
int noise = 0;

void setup() {
    pinMode(buzzer_output, OUTPUT);
    Serial.begin(9600);
    Wire.begin();
    mpu.begin();
    mpu.calcGyroOffsets(true);
  
}

void loop() {

  mpu.update();
  
// Buzzer for when an apple gets eaten, if the pin reads a 1, then a noise will output
// from the buzzer

if (Serial.available() > 0) {
    noise = Serial.read();

    if (noise == '1'){
      tone(buzzer_output, 2500);
      delay(100);
      noTone(buzzer_output);
    }
}

// Serial prints used for sending "w" "a" "s" "d"

// Used for Replacement for "W" Key
if (mpu.getGyroAngleX() < -50 && mpu.getGyroAngleY() < 20) {
    Serial.println('w');
    delay(100);
  }
  // Used for Replacement for "S" Key
  else if (mpu.getGyroAngleX() > 50) {
      Serial.println('s');
      delay(100);
    }
  // Used for Replacement for "A" Key
  else if (mpu.getGyroAngleY() < -60) {
      Serial.println('a');
      delay(100);
    }
  // Used for Replacement for "D" Key
  else if (mpu.getGyroAngleY() > 60) {
      Serial.println('d');
      delay(100);
    }

}
