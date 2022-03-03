
#define squarewavein 26 //pin number (3.3v!)
int SquarewaveStart=0;
int SquarewaveEnd=0;
int frequency = 0;
int SquarewaveState = 0;
int LastSquarewaveState = 0;
int Counter = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(squarewavein, INPUT);
Serial.begin(115200);
}
//void Task3(){}
  

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long CurrentMicros=micros();


SquarewaveState = digitalRead(squarewavein); 
LastSquarewaveState = SquarewaveState;
Counter=0;
while (Counter!=2){ 
  SquarewaveState = digitalRead(squarewavein);
if (SquarewaveState != LastSquarewaveState){ //When state changes, start timer
  if (Counter=0){ //Checks if this is start of pulse
  SquarewaveStart = CurrentMicros;
  LastSquarewaveState = SquarewaveState;
  Counter = 1;  //Next time there is a change it will be end of pulse
  } else {
    SquarewaveEnd = CurrentMicros; //
    
      frequency = 1000000/(2*(SquarewaveEnd-SquarewaveStart));
  Serial.printf( "Frequency is %d \n", frequency); 
  Serial.printf( "start is %d \n", SquarewaveStart);
  Serial.printf( "end is %d \n", SquarewaveEnd);
  Counter = 2; //Terminates while loop.
  }
  }
  
}
    

}
