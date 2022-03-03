
//Task1 setup//
#define GreenLED //insert green LED pin
//////////////

//Task2//
#define Button 22 //insert Button 1 pin
int ButtonState=0
/////////

//Task3//
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
#define slotlength 1388
#define totalslot 3599



void setup() {
  // put your setup code here, to run once:
int slot = 0
unsigned long PreviousMicros=0;

//Task1//
pinMode(GreenLED, OUTPUT);
////////

//Task2//
 pinMode(Button, INPUT);
 ////////

 //Task3//
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
if (slot % 30 == 0){
  PreviousMicros = CurrentMicros;
  Task1();
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
} else if (slot % 5 == 1){
  PreviousMicros = CurrentMicros;
  Task2;
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
} else if (slot % 1 == 2){
  PreviousMicros = CurrentMicros;
  Task3;
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
} else if (slot % 24 == 3){
  PreviousMicros = CurrentMicros;
  Task4;
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
} else if (slot % 24 == 4){
  PreviousMicros = CurrentMicros;
  Task5;
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
} else if (slot % 10 == 5){
  PreviousMicros = CurrentMicros;
  Task6;
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
} else if (slot % 3 == 6){
  PreviousMicros = CurrentMicros;
  Task7;
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
} else if (slot % 3 == 7){
  PreviousMicros = CurrentMicros;
  Task8;
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
} else if (slot % 0.2 == 9){
  Task9;
  delayMicroseconds(slotlength-(CurrentMicros-PreviousMicros));
  slot++;
} else if (slot == totalslot){      //Resets step count to 0 after 5 seconds.
  delayMicroseconds(slotlength);
  slot=0;
} else {
  delayMicroseconds(slotlength);    
}
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
  if (average_analogue_in > half of maximum range for 
analogue input){
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
  Serial.println(ButtonState, Frequency, AverageAnaInput);
}
  

