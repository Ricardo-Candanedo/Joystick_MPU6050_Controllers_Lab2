// Portion was taken from the example code given from Elegoo 
// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

// digital pin output for the buzzer when an apple is eaten
const int buzzer_output = 3; 
int noise = 0;

void setup() {
  pinMode(SW_pin, INPUT);
  pinMode(buzzer_output, OUTPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
// Serial prints used for sending "w" "a" "s" "d"

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

// This section is for the y-axis of the joystick: "w" and "s"
  if (analogRead(Y_pin) > 1000) {
      Serial.println('s');
      delay(200);
    }
  else if (analogRead(Y_pin) < 100){
      Serial.println('w');
      delay(200);
    }

// This section is for the y-axis of the joystick: "d" and "a"
  if (analogRead(X_pin) > 1000) {
      Serial.println('a');
      delay(200);
    }
  else if (analogRead(X_pin) < 100){
      Serial.println('d');
      delay(200);
    }
}
