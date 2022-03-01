#define Button 22 //insert Button 1 pin
int ButtonState=0



void setup() {
  // put your setup code here, to run once:
 pinMode(Button, INPUT);
}

void Task2 {
   ButtonState=digitalRead(Button); //Tells when Button is pressed
}
void loop() {
  // put your main code here, to run repeatedly:

}
