//Loop setup//
unsigned long StartMicros = 0;
unsigned long EndMicros = 0;
unsigned long PreviousMicros = 0;
#define slotlength 41667
int slot = 0;
/////////////

//Task1 setup//
#define GreenLED 33//insert green LED pin
//////////////

//Task2//
#define Button 22 //insert Button 1 pin
int ButtonState=0;
/////////

//Task3//
#define squarewavein 26 //Square wave input pin number.
unsigned long SquarewaveStart=0;
unsigned long SquarewaveEnd=0;
unsigned long frequency = 0;
int SquarewaveState = 0;
int LastSquarewaveState = 0;
int Counter = 0;
/////////

//Task4//
#define AnalogueInput 27 //pin number
int AnalogueRead=0;
////////

//Task5//
int Prev1AnaInput = 0;
int Prev2AnaInput = 0;
int Prev3AnaInput = 0;
int Prev4AnaInput = 0;
int AverageAnaInput = 0;
/////////

//Task6//
/////////

//Task7//
 int half_of_maximum_range_for_analogue_input = 0;
 int error_code=0;
/////////

//Task8//
#define RedLED 32//insert green pin number
////////

//Task9//
////////




void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);

//Task1//
pinMode(GreenLED, OUTPUT);
////////

//Task2//
 pinMode(Button, INPUT);
 ////////

 //Task3//
 pinMode(squarewavein, INPUT);
 ////////

 //Task4//
 pinMode(AnalogueInput, INPUT);
 /////////

 //Task5//
 ////////

 //Task6//
 ////////
 
 //Task7//

 ////////

 //Task8//
 pinMode(RedLED, OUTPUT);
 ////////

 //Task9//
 ////////
 

}







void loop() {
  // put your main code here, to run repeatedly:
unsigned long StartMicros=micros(); //Starts a timer which starts at 0 when the ESP 32 is turned on. We compare other timings to this to detect when certain time has elapsed.

if ((slot/30) % 8 == 0){ // Task 1 to be completed
  if ((slot/24) % 10 == 4){ //Checks if clash in timings with Task5. Ie slot 24. If so, does Task1, waits till end of slot, then Task4, waits again till slot has finished, adds 2 to keep slot count accurate.
    if ((slot+1) % 5 == 1){ //slot 144
    StartMicros=micros();
    Task1();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    StartMicros=micros();
    Task2();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    StartMicros=micros();
    Task5();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    slot=slot+3;
    Serial.printf( "Task 1,2,5 %d \n", slot);
  } else { //Task1 and Task5 clash
    StartMicros=micros();
    Task1();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    StartMicros=micros();
    Task5();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    slot=slot+2;
    Serial.printf( "Task 1,5 %d \n", slot);
  }
  } else { //no clashes
  StartMicros=micros();
  Task1();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;  
  }
  
} else if ((slot/5) % 48 == 1){ // Task 2 to be completed
  if ((slot/24) % 10 == 3){ //Checks for clashes with Task4
    StartMicros=micros();
    Task2();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    StartMicros=micros();
    Task4();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    StartMicros=micros();
    Task5();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    slot = slot+3;
    Serial.printf( "Task 2,4,5 %d \n", slot);
  } else {
  StartMicros=micros();
  Task2();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;
  }
  
} else if (slot % 240 == 2){ // Task 3 to be completed //no clashes
  StartMicros=micros();
  Task3();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;
  Serial.printf( "Task 3, slot %d \n", slot);
  
} else if ((slot/24) % 10 == 3){ // Task 4 to be completed 
  if ((slot/10) % 24 == 5){ // Checks for clash with 5
    StartMicros=micros();
    Task4();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    StartMicros=micros();
    Task5();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    StartMicros=micros();
    Task6();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    slot = slot+3;
    Serial.printf( "Task 4,5,6 %d \n", slot);
  } else if ((slot/5) % 48 == 1){ // Checks for clash with 2
    StartMicros=micros();
    Task2();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    StartMicros=micros();
    Task4();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    StartMicros=micros();
    Task5();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    slot = slot+3;
    Serial.printf( "Task 2,4,5 %d \n", slot);
  } else { // no clashes
  StartMicros=micros();
  Task4();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;
  }
  
} else if ((slot/24) % 10 == 4){ // Task 5 to be completed
     if ((slot/30) % 8 == 0){ // Checks for clash with Task1
      if ((slot+1) % 5 == 1){ //slot 144
    StartMicros=micros();
    Task1();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    StartMicros=micros();
    Task2();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    StartMicros=micros();
    Task5();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    slot=slot+3;
    Serial.printf( "Task 1,2,5 %d \n", slot);
      } else { // just clash with Task1
            StartMicros=micros();
    Task1();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    StartMicros=micros();
    Task5();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    slot=slot+2;
    Serial.printf( "Task 1,5 %d \n", slot);
      }
     } else { //No clash
  StartMicros=micros();
  Task5();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;
     }
  
} else if ((slot/10) % 24 == 5){ // Task 6 to be completed
  if ((slot/24) % 10 == 3){
    StartMicros=micros();
    Task4();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    StartMicros=micros();
    Task5();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    StartMicros=micros();
    Task6();
    EndMicros=micros();
    delayMicroseconds(slotlength-(EndMicros-StartMicros));
    slot=slot+3;
  } else { //No clash
  StartMicros=micros();
  Task6();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;
  Serial.printf( "Task 6 %d \n", slot);
  }
  
} else if ((slot/3) % 80 == 6){ // Task 7 to be completed
  StartMicros=micros();
  Task7();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;
  Serial.printf( "Task 7 %d \n", slot);
  
} else if ((slot/3) % 80 == 7){ // Task 8 to be completed
  StartMicros=micros();
  Task8();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;
  Serial.printf( "Task 8 %d \n", slot);
  
} else if (slot % 1200 == 1199){ // Task 9 to be completed
  StartMicros=micros();
  Task9();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=0;
  Serial.printf( "Task 9 %d \n", slot);
} else {
  delayMicroseconds(slotlength);   
  slot=slot+1;
}
}



void Task1() {
digitalWrite(GreenLED, HIGH);
delayMicroseconds(50);
digitalWrite(GreenLED, LOW);
}

void Task2() {
   ButtonState=digitalRead(Button); //Tells when Button is pressed
}

void Task3(){  
SquarewaveState=digitalRead(squarewavein);
LastSquarewaveState=SquarewaveState;
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
  Serial.printf( "start is %d \n", SquarewaveStart);
  Serial.printf( "end is %d \n", SquarewaveEnd);
  Counter = 0;
  LastSquarewaveState=SquarewaveState;
}
}
}

void Task4(){
  AnalogueRead=analogRead(AnalogueInput);
}

void Task5(){
  Prev4AnaInput = Prev3AnaInput;
  Prev3AnaInput = Prev2AnaInput;
  Prev2AnaInput = Prev1AnaInput;
  Prev1AnaInput = AnalogueInput;
  AverageAnaInput = (Prev4AnaInput+Prev3AnaInput+Prev2AnaInput+Prev1AnaInput)/4;
}

void Task6() {
for (int i=0; i<=1000; i++){
  __asm__ __volatile__ ("nop");
}
}

void Task7() {
  if (AverageAnaInput >= half_of_maximum_range_for_analogue_input){
    error_code = 1;
} else {
    error_code = 0;
}
}

void Task8(){
if (error_code==1){
    digitalWrite(RedLED, HIGH);
   } else {
    digitalWrite(RedLED, LOW);
   }
}

void Task9(){
Serial.printf( "Button State is %d \n", ButtonState);
Serial.printf( "Frequency is %d \n", frequency);
Serial.printf( "Average Analogue input is %d \n", AverageAnaInput);
}
