//Loop setup//
int slot = 0;
unsigned long PreviousMicros=0;
#define slotlength 4167
#define totalslot 1199
/////////////

//Task1 setup//
#define GreenLED //insert green LED pin
//////////////

//Task2//
#define Button 22 //insert Button 1 pin
int ButtonState=0
/////////

//Task3//
#define squarewavein 26 //Square wave input pin number.
int SquarewaveStart=0;
int SquarewaveEnd=0;
int frequency = 0;
int SquarewaveState = 0;
int LastSquarewaveState = 0;
int Counter = 0;
/////////

//Task4//
#define AnalogueInput //pin number
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
/////////

//Task8//
#define RedLED 33//insert green pin number
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
unsigned long CurrentMicros=micros(); //Starts a timer which starts at 0 when the ESP 32 is turned on. We compare other timings to this to detect when certain time has elapsed.

if ((slot/30) % 8 == 0){ // Task 1 to be completed
  if ((slot/24) % 10 == 4){ //Checks if clash in timings with Task5. Ie slot 24. If so, does Task1, waits till end of slot, then Task4, waits again till slot has finished, adds 2 to keep slot count accurate.
    if ((slot+1) % 5 == 1){ //slot 144
    PreviousMicros = CurrentMicros;
    Task1();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    PreviousMicros = CurrentMicros;
    Task2();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    PreviousMicros = CurrentMicros;
    Task5();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    slot=slot+3;
  } else { //Task1 and Task5 clash
    PreviousMicros = CurrentMicros;
    Task1();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    PreviousMicros = CurrentMicros;
    Task5();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    slot=slot+2;
  }
  } else { //no clashes
  PreviousMicros = CurrentMicros;
  Task1();
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;  
  }
  
} else if ((slot/5) % 48 == 1){ // Task 2 to be completed
  if ((slot/24) % 10 == 3){ //Checks for clashes with Task4
    PreviousMicros = CurrentMicros;
    Task2();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    PreviousMicros = CurrentMicros;
    Task4();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    PreviousMicros = CurrentMicros;
    Task5();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    slot = slot+3;
  } else {
  PreviousMicros = CurrentMicros;
  Task2;
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
  }
  
} else if (slot % 240 == 2){ // Task 3 to be completed //no clashes
  PreviousMicros = CurrentMicros;
  Task3;
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
  
} else if ((slot/24) % 10 == 3){ // Task 4 to be completed 
  if ((slot/10) % 24 == 5){ // Checks for clash with 5
    PreviousMicros = CurrentMicros;
    Task4();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    PreviousMicros = CurrentMicros;
    Task5();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    PreviousMicros = CurrentMicros;
    Task6();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    slot = slot+3;
  } else if ((slot/5) % 48 == 1){ // Checks for clash with 2
    PreviousMicros = CurrentMicros;
    Task2();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    PreviousMicros = CurrentMicros;
    Task4();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    PreviousMicros = CurrentMicros;
    Task5();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    slot = slot+3;
  } else { // no clashes
  PreviousMicros = CurrentMicros;
  Task4();
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
  }
  
} else if ((slot/24) % 10 == 4){ // Task 5 to be completed
     if ((slot/30) % 8 == 0){ // Checks for clash with Task1
      if ((slot+1) % 5 == 1){ //slot 144
    PreviousMicros = CurrentMicros;
    Task1();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    PreviousMicros = CurrentMicros;
    Task2();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    PreviousMicros = CurrentMicros;
    Task5();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    slot=slot+3;
      } else { // just clash with Task1
            PreviousMicros = CurrentMicros;
    Task1();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    PreviousMicros = CurrentMicros;
    Task5();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    slot=slot+2;
      }
     } else { //No clash
  PreviousMicros = CurrentMicros;
  Task5();
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
     }
  
} else if ((slot/10) % 24 == 5){ // Task 6 to be completed
  if ((slot/24) % 10 == 3){
    PreviousMicros = CurrentMicros;
    Task4();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    PreviousMicros = CurrentMicros;
    Task5();
    delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
    PreviousMicros = CurrentMicros;
    Task6();
  } else { //No clash
  PreviousMicros = CurrentMicros;
  Task6;
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
  }
  
} else if ((slot/3) % 80 == 6){ // Task 7 to be completed
  PreviousMicros = CurrentMicros;
  Task7;
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
  
} else if ((slot/3) % 80 == 7){ // Task 8 to be completed
  PreviousMicros = CurrentMicros;
  Task8;
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
  
} else if ((slot/0.2) % 1200 == 1199){ // Task 9 to be completed
  Task9;
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot=0;
} else {
  delayMicroseconds(slotlength);    
}
}



void Task1() {
    \\TASK 1\\
digitalWrite(GreenLED,HIGH);
delayMicroseconds(50);
digitalWrite(GreenLED,LOW);
}

void Task2() {
   ButtonState=digitalRead(Button); //Tells when Button is pressed
}

void Task3(){  


SquarewaveState = digitalRead(squarewavein); 
LastSquarewaveState = SquarewaveState;
Counter=0;
while (Counter!=2){ 
  SquarewaveState = digitalRead(squarewavein);
if (SquarewaveState != LastSquarewaveState){ //When state changes, start timer
  if (Counter==0){ //Checks if this is start of pulse
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

void Task7 {
  if (AverageAnaInput >= half_of_maximum_range_for_analogue_input){
    error_code = 1
}else{
    error_code = 0
}
}

void Task8(){
if (error_code==1){
    digitalWrite(GreenLED, HIGH);
   } else {
    digitalWrite(GreenLED, LOW):
   }
}

void Task9(){
  Serial.println(ButtonState, frequency, AverageAnaInput);
}
