#define WaveformCycle 33750 // Length of each waveform cycle, calculated manually myself in matlab, although could be implemented using a for loop to calculate the sum of pulses of a.

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  \\TASK 1\\
 if (currentMicros-PreviousMicrosWaveform<=50){ // Keeps Green LED on for the first 0-50 uS, does not depend on Switch Settings
   digitalWrite(GreenLED,HIGH);
 } else {
   digitalWrite(GreenLED,LOW);
 }
}
