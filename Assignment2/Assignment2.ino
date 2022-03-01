#include Task1.h
#include Task2.h
#include Task3.h
#include Task4.h
#include Task5.h
#include Task6.h
#include Task7.h
#include Task8.h
#include Task9.h

#define steplength 1388
#define totalsteps 3599

void setup() {
  // put your setup code here, to run once:
int steps = 0
unsigned long PreviousMicros=0;
}

void loop() {
  // put your main code here, to run repeatedly:
unsigned long CurrentMicros=micros(); //Starts a timer which starts at 0 when the ESP 32 is turned on. We compare other timings to this to detect when certain time has elapsed.
if (steps % 30 == 0){
  PreviousMicros = CurrentMicros;
  Task1;
  delayMicroseconds(steplength-(CurrentMicros-PreviousMicros));
  steps++;
} else if (steps % 5 == 1){
  PreviousMicros = CurrentMicros;
  Task2;
  delayMicroseconds(steplength-(CurrentMicros-PreviousMicros));
  steps++;
} else if (steps % 1 == 2){
  PreviousMicros = CurrentMicros;
  Task3;
  delayMicroseconds(steplength-(CurrentMicros-PreviousMicros));
  steps++;
} else if (steps % 24 == 3){
  PreviousMicros = CurrentMicros;
  Task4;
  delayMicroseconds(steplength-(CurrentMicros-PreviousMicros));
  steps++;
} else if (steps % 24 == 4){
  PreviousMicros = CurrentMicros;
  Task5;
  delayMicroseconds(steplength-(CurrentMicros-PreviousMicros));
  steps++;
} else if (steps % 10 == 5){
  PreviousMicros = CurrentMicros;
  Task6;
  delayMicroseconds(steplength-(CurrentMicros-PreviousMicros));
  steps++;
} else if (steps % 3 == 6){
  PreviousMicros = CurrentMicros;
  Task7;
  delayMicroseconds(steplength-(CurrentMicros-PreviousMicros));
  steps++;
} else if (steps % 3 == 7){
  PreviousMicros = CurrentMicros;
  Task8;
  delayMicroseconds(steplength-(CurrentMicros-PreviousMicros));
  steps++;
} else if (steps % 0.2 == 8){
  Task9;
  delayMicroseconds(steplength-(CurrentMicros-PreviousMicros));
  steps++;
} else if (steps == 3599){      //Resets step count to 0 after 5 seconds.
  delayMicroseconds(steplength);
  steps=0;
} else {
  delayMicroseconds(steplength);    
}
}

}
