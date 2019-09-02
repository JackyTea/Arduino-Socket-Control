/*
  Arduino Socket Controller
  Jacky Tea
  01/09/19

  Circuit build ver 1.0.
*/

//pins
int pinRed = 8;
int pinYellow = 9;
int pinGreen = 10;
int pinBlue = 11;

//setup pins
void setup() {
  Serial.begin(9600);
  pinMode(pinRed, OUTPUT);
  pinMode(pinYellow, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
}

//parse commands
void loop() {
  if (Serial.available() > 0) {
    int data = Serial.read();
    if (data == 'r') {
      digitalWrite(pinRed, HIGH);
      delay(1000);
      digitalWrite(pinRed, LOW);
    }
    else if (data == 'y') {
      digitalWrite(pinYellow, HIGH);
      delay(1000);
      digitalWrite(pinYellow, LOW);
    }
    else if (data == 'g') {
      digitalWrite(pinGreen, HIGH);
      delay(1000);
      digitalWrite(pinGreen, LOW);
    }
    else if (data == 'b') {
      digitalWrite(pinBlue, HIGH);
      delay(1000);
      digitalWrite(pinBlue, LOW);
    }
  }
}
