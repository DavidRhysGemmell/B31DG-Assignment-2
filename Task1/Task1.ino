#define GreenLED //insert green LED pin

void setup() {
  // put your setup code here, to run once:
pinMode(GreenLED, OUTPUT):
}

void loop() {
  // put your main code here, to run repeatedly:
  \\TASK 1\\
digitalWrite(GreenLED,HIGH);
delayMicroseconds(50);
digitalWrite(GreenLED,LOW);
}
