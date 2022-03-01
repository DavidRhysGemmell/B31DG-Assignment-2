#define AnalogueInput //pin number
int AnalogueRead=0;
void setup() {
  // put your setup code here, to run once:
pinMode(AnalogueInput, INPUT);
}
void Task3(){
  AnalogueRead=analogRead(AnalogueInput);
}
void loop() {
  // put your main code here, to run repeatedly:

}
