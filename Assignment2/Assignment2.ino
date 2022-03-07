//Loop setup//
unsigned long StartMicros = 0;
unsigned long EndMicros = 0;
unsigned long PreviousMicros = 0;
#define slotlength 1386 //underestimate
int slot = 0;

int OneCycle = 0;
unsigned long StartofCycleMicros = 0;
unsigned long EndofCycleMicros = 0;
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
StartofCycleMicros= micros();

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

if (slot % 24 == 0){ // Task 1 to be completed
 //no clashes
  StartMicros=micros();
  Task1();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;  

  
} else if (slot % 144 == 1){ // Task 2 to be completed

  StartMicros=micros();
  Task2();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;

  
} else if (slot % 720 == 2){ // Task 3 to be completed //no clashes
  StartMicros=micros();
  Task3();
  EndMicros=micros();
  delayMicroseconds((2*slotlength)-(EndMicros-StartMicros)); // takes 2 slots
  slot=slot+2;
  
  
} else if (slot % 30 == 4){ // Task 4 to be completed 
 // no clashes
  StartMicros=micros();
  Task4();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;

 
} else if (slot % 30 == 5){ // Task 5 to be completed
 //No clash
  StartMicros=micros();
  Task5();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;
     
  
} else if (slot % 72 == 6){ // Task 6 to be completed

  StartMicros=micros();
  Task6();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;
  
  
  
} else if (slot % 240 == 7){ // Task 7 to be completed
  StartMicros=micros();
  Task7();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;
  
  
} else if (slot % 240 == 8){ // Task 8 to be completed
  StartMicros=micros();
  Task8();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  slot=slot+1;
  
  
} else if (slot % 3600 == 3599){ // Task 9 to be completed
  StartMicros=micros();
  Task9();
  EndMicros=micros();
  delayMicroseconds(slotlength-(EndMicros-StartMicros));
  EndofCycleMicros=micros(); //Refine this to make exactly 5 seconds.
  OneCycle=(EndofCycleMicros-StartofCycleMicros);
  Serial.printf( "1 cycle is %d \n", OneCycle);
  delayMicroseconds(5000000-OneCycle); //Takes each cycle to exactly 5 seconds
  StartofCycleMicros=micros();
  slot=0;

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
Counter=0;
SquarewaveState=digitalRead(squarewavein);
LastSquarewaveState=SquarewaveState;
while (SquarewaveState==LastSquarewaveState){
  SquarewaveState = digitalRead(squarewavein); 
}

if (SquarewaveState != LastSquarewaveState){
    SquarewaveStart=micros();
    LastSquarewaveState=SquarewaveState;
    while (SquarewaveState==LastSquarewaveState){
    SquarewaveState = digitalRead(squarewavein); 
    }
    if (SquarewaveState != LastSquarewaveState){
      SquarewaveEnd = micros(); //
      frequency = 1000000/(2*(SquarewaveEnd-SquarewaveStart));    
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
  Prev1AnaInput = AnalogueRead;
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
  
