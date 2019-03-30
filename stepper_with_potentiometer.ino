#include <Stepper.h> // Include the header file
#define STEPS 64

Stepper stepper(STEPS, 8, 10, 9, 11);

int Pv = 0;
int potV = 0;

void setup() {
Serial.begin(9600);
stepper.setSpeed(200);
}
void loop() {

potV = map(analogRead(A0),0,1024,0,360);
if (potV>Pv)
stepper.step(5);
if (potV<Pv)
stepper.step(-5);

Pv = potV;
Serial.println(Pv);
}
