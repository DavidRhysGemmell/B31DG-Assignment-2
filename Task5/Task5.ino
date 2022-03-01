//Need to define things without them reseting.


void setup() {
  // put your setup code here, to run once:

}

void Task5(){
  Prev4AnaInput = Prev3AnaInput;
  Prev3AnaInput = Prev2AnaInput;
  Prev2AnaInput = Prev1AnaInput;
  Prev1AnaInput = AnalogueInput;
  AverageAnaInput = (Prev4AnaInput+Prev3AnaInput+Prev2AnaInput+Prev1AnaInput)/4;
}
void loop() {
  // put your main code here, to run repeatedly:

}
