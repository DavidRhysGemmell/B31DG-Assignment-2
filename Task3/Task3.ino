#define squarewavein 26 //pin number (3.3v!)
unsigned long SquarewaveStart=0;
unsigned long SquarewaveEnd=0;
unsigned long frequency = 0;
int SquarewaveState = 0;
int LastSquarewaveState = 0;
int Counter = 0;
int End=0;
int End2=0;
int SquarewaveStartState = 0;
int SquarewaveEndState = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(squarewavein, INPUT);
Serial.begin(115200);
Squarewa
veState=digitalRead(squarewavein);
LastSquarewaveState=SquarewaveState;
}
//void Task3(){  }
  

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long Oncepersecond = millis();
  if (Oncepersecond % 1000 == 0){

while (SquarewaveState==LastSquarewaveState){
  SquarewaveState = digitalRead(squarewavein); 
}

if (SquarewaveState != LastSquarewaveState){
  if (Counter == 0){
  SquarewaveStart=micros();
  LastSquarewaveState=SquarewaveState;
  Counter++;
} else {
  SquarewaveEnd = micros(); //
  frequency = 1000000/(2*(SquarewaveEnd-SquarewaveStart));
  Serial.printf( "Frequency is %d \n", frequency); 
  Counter = 0;
  LastSquarewaveState=SquarewaveState;
}
}
}
}
