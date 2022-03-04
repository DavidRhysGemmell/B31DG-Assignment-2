#define squarewavein 26 //pin number (3.3v!)
int SquarewaveStart=0;
int SquarewaveEnd=0;
int frequency = 0;
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
}
//void Task3(){  }
  

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long CurrentMicros=micros();
  SquarewaveState = digitalRead(squarewavein); 
LastSquarewaveState = SquarewaveState;

while (End !=1){ 
  SquarewaveState = digitalRead(squarewavein);
if (SquarewaveState != LastSquarewaveState){ //When state changes, start timer
  SquarewaveStart = CurrentMicros;
  SquarewaveStartState = SquarewaveState;
  while (End2 !=1){
    SquarewaveEndState = digitalRead(squarewavein);
    if (SquarewaveEndState != SquarewaveStart){
      SquarewaveEnd = CurrentMicros;
      End2 =1;
      End=1;
    }
  }
}
}
if (SquarewaveEnd==SquarewaveStart){
  Serial.printf( "Error \n");
    Serial.printf( "start is %d \n", SquarewaveStart);
  Serial.printf( "end is %d \n", SquarewaveEnd);
} else {
      frequency = 1000000/(2*(SquarewaveEnd-SquarewaveStart));
  Serial.printf( "Frequency is %d \n", frequency); 
  Serial.printf( "start is %d \n", SquarewaveStart);
  Serial.printf( "end is %d \n", SquarewaveEnd);
}
}
