unsigned long PreviousMicros=0;
int TimeTakenToCompute = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long StartMicros=micros();

  for (int i=0; i<=1000; i++){
    __asm__ __volatile__ ("nop");
  }
  unsigned long EndMicros=micros();
  TimeTakenToCompute = EndMicros-StartMicros;
  Serial.printf("Time taken %d \n", TimeTakenToCompute);
  Serial.printf("current %d \n", StartMicros);
  Serial.printf("Previous %d \n", EndMicros);

}

