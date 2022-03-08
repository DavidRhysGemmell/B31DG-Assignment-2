//This program is a cyclic executive of 9 different tasks at variable rates per second;
// Task 1: 30Hz. Produces a 50microsecond pulse.
// Task 2: 5Hz. Monitors a digital input (Button).
// Task 3: 1Hz. Measures the frequency of a Square wave signal, 500Hz+ range, 50% duty cycle.
// Task 4: 24Hz. Reads an analogue input.
// Task 5: 24Hz. Takes an average of the last 4 recorded analogue inputs.
// Task 6: 10Hz. Executes __asm__ __volatile__ ("nop") 1000 times.
// Task 7: 3Hz. Produces an error code if the current analogue input is greater than half of the maximum range of the analogue input.
// Task 8: 3Hz. Visulaises the error code with an LED.
// Task 9: 0.2Hz. Prints to the serial port: Button state, Frequency of square wave, average analogue input.


//Loop setup//
unsigned long StartofTaskMicros = 0;
unsigned long EndofTaskMicros = 0;
#define SlotLength 1386 //underestimate in microseconds
int Slot = 0;
int OneCycle = 0; //Records length of one cycle.
unsigned long StartofCycleMicros = 0;
unsigned long EndofCycleMicros = 0;
/////////////

//Task1 setup//
#define GreenLED 27//insert green LED pin
//////////////

//Task2//
#define Button 13 //insert Button pin
int ButtonState=0;
/////////

//Task3//
#define squarewavein 19 //Square wave input pin number.
unsigned long SquarewaveStart=0;
unsigned long SquarewaveEnd=0;
unsigned long Frequency = 0;
int SquarewaveState = 0;
int LastSquarewaveState = 0;
/////////

//Task4//
#define AnalogueInput 32 //pin number
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
 int half_of_maximum_range_for_analogue_input = 2048; //Maximum is 4095.
 int error_code=0;
/////////

//Task8//
#define RedLED 26//insert green pin number
////////

//Task9//
////////




void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  StartofCycleMicros= micros();

  //Task1 Setup//
  pinMode(GreenLED, OUTPUT);
  //////////////

  //Task2 Setup//
   pinMode(Button, INPUT);
  //////////////

  //Task3 Setup//
   pinMode(squarewavein, INPUT);
  //////////////

  //Task4 Setup//
   pinMode(AnalogueInput, INPUT);
  //////////////

  //Task5 Setup//
  //////////////

  //Task6 Setup//
  //////////////
 
  //Task7 Setup//
  //////////////

  //Task8 Setup//
   pinMode(RedLED, OUTPUT);
  //////////////

  //Task9 Setup//
  ////////////// 
}


///////////////////// CYCLIC EXECUTIVE /////////////////////

void loop() {

  if (Slot % 24 == 0){ // Task 1 to be completed
    StartofTaskMicros=micros();
    Task1();
    EndofTaskMicros=micros();
    delayMicroseconds(SlotLength-(EndofTaskMicros-StartofTaskMicros));
    Slot++;  
  
  } else if (Slot % 144 == 1){ // Task 2 to be completed
    StartofTaskMicros=micros();
    Task2();
    EndofTaskMicros=micros();
    delayMicroseconds(SlotLength-(EndofTaskMicros-StartofTaskMicros));
    Slot++;

  } else if (Slot % 720 == 2){ // Task 3 to be completed
    StartofTaskMicros=micros();
    //Task3(); ///////////////////////REMOVE BEFORE SUBMISSION///////////////////////////////////////
    EndofTaskMicros=micros();
    delayMicroseconds((2*SlotLength)-(EndofTaskMicros-StartofTaskMicros)); // takes 2 Slots to be able to measure a 500hz signal.
    Slot=Slot+2;
    
  } else if (Slot % 30 == 4){ // Task 4 to be completed 
    StartofTaskMicros=micros();
    Task4();
    EndofTaskMicros=micros();
    delayMicroseconds(SlotLength-(EndofTaskMicros-StartofTaskMicros));
    Slot++;

  } else if (Slot % 30 == 5){ // Task 5 to be completed
    StartofTaskMicros=micros();
    Task5();
    EndofTaskMicros=micros();
    delayMicroseconds(SlotLength-(EndofTaskMicros-StartofTaskMicros));
    Slot++;
     
  
  } else if (Slot % 72 == 6){ // Task 6 to be completed
    StartofTaskMicros=micros();
    Task6();
    EndofTaskMicros=micros();
    delayMicroseconds(SlotLength-(EndofTaskMicros-StartofTaskMicros));
    Slot++;
  
  } else if (Slot % 240 == 7){ // Task 7 to be completed
    StartofTaskMicros=micros();
    Task7();
    EndofTaskMicros=micros();
    delayMicroseconds(SlotLength-(EndofTaskMicros-StartofTaskMicros));
    Slot++;
  
  
  } else if (Slot % 240 == 8){ // Task 8 to be completed
    StartofTaskMicros=micros();
    Task8();
    EndofTaskMicros=micros();
    delayMicroseconds(SlotLength-(EndofTaskMicros-StartofTaskMicros));
    Slot++;
   
  } else if (Slot % 3600 == 3599){ // Task 9 to be completed
    StartofTaskMicros=micros();
    Task9();
    EndofTaskMicros=micros();
    delayMicroseconds(SlotLength-(EndofTaskMicros-StartofTaskMicros));
    EndofCycleMicros=micros(); //Refine this to make exactly 5 seconds.
    OneCycle=(EndofCycleMicros-StartofCycleMicros);
    delayMicroseconds(5000000-OneCycle); //Takes each cycle to exactly 5 seconds
    StartofCycleMicros=micros();
    Slot=0; //Cycle ended, start from 0 again.

  } else { //No task
    delayMicroseconds(SlotLength);   
    Slot++;
  }
}

///////////////////////////////////////////////////////////////////////


//// TASK1 FUNCTION ////
void Task1() {
  digitalWrite(GreenLED, HIGH);
  delayMicroseconds(50);
  digitalWrite(GreenLED, LOW);
}
////////////////////////

//// TASK2 FUNCTION ////
void Task2() {
   ButtonState=digitalRead(Button); //Tells when Button is pressed
}
////////////////////////

//// TASK3 FUNCTION ////
void Task3(){  
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
    if (SquarewaveState != LastSquarewaveState){ //MAY NOT NEED, TEST TOMORROW.
      SquarewaveEnd = micros(); //
      Frequency = 1000000/(2*(SquarewaveEnd-SquarewaveStart));      
    }   
  }
}
////////////////////////

//// TASK4 FUNCTION ////
void Task4(){
  AnalogueRead=analogRead(AnalogueInput);
}
////////////////////////

//// TASK5 FUNCTION ////
void Task5(){
  Prev4AnaInput = Prev3AnaInput;
  Prev3AnaInput = Prev2AnaInput;
  Prev2AnaInput = Prev1AnaInput;
  Prev1AnaInput = AnalogueRead;
  AverageAnaInput = (Prev4AnaInput+Prev3AnaInput+Prev2AnaInput+Prev1AnaInput)/4;
}
////////////////////////

//// TASK6 FUNCTION ////
void Task6() {
  for (int i=0; i<=1000; i++){
    __asm__ __volatile__ ("nop");
  }
}
////////////////////////

//// TASK7 FUNCTION ////
void Task7() {
  if (AverageAnaInput > half_of_maximum_range_for_analogue_input){
    error_code = 1;
  } else {
    error_code = 0;
  }
}
////////////////////////

//// TASK8 FUNCTION ////
void Task8(){
  if (error_code==1){
    digitalWrite(RedLED, HIGH);
  } else {
    digitalWrite(RedLED, LOW);
  }
}
////////////////////////

//// TASK9 FUNCTION ////
void Task9(){
  Serial.printf( "Button State is %d, ", ButtonState);
  Serial.printf( "Frequency is %d, ", Frequency);
  Serial.printf( "Average Analogue input is %d. \n", AverageAnaInput);
}
////////////////////////
