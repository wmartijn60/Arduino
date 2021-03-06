/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
*
*/
int led1 = 2;
int led2 = 3;
int led3 = 4;
// defines pins numbers
const int trigPin = 11;
const int echoPin = 12;
// defines variables
long duration;
int distance;
void setup() {
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
Serial.begin(9600); 
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
if (distance > 40 && distance < 70) {
digitalWrite(led1, HIGH);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
}
else if (distance > 20 && distance < 40) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
}
else if (distance < 20) {
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, HIGH);
}
else {
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);  
}
}
