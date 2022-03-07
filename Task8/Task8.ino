#define RedLED 33//insert green pin number
void setup() {
  // put your setup code here, to run once:
pinMode(RedLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (error_code==1){
    digitalWrite(RedLED, HIGH);
   } else {
    digitalWrite(RedLED, LOW);
   }

}
