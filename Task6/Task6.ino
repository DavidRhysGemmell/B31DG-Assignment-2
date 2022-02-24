void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
for (int i=0; i<=1000; i++){
  __asm__ __volatile__ ("nop");
}
}
