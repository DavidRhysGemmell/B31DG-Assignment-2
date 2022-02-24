#define GreenLED 33//insert green pin number
void setup() {
  // put your setup code here, to run once:
pinMode(GreenLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (error_code==1){
    digitalWrite(GreenLED, HIGH);
   } else {
    digitalWrite(GreenLED, LOW):
   }

}
