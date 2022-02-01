//#include <SPI.h>
//#include <nRF24L01.h>
//#include <RF24.h>

#include <Stepper.h>
const int STEPS_PER_REVOLUTION = 2048;  // change this to fit the number of steps per revolution
int NUM_REVS = 8;
Stepper myStepper(STEPS_PER_REVOLUTION, 8, 10, 9, 11);

//RF24 nrf(9, 8); // CE, CNS

int x;

const byte address[6] = "gator";


void setup() {
    Serial.begin(9600);
    while(!Serial) {}

    myStepper.setSpeed(10);


//    nrf.begin();
//    nrf.openWritingPipe(address);
//    nrf.setPALevel(RF24_PA_MIN); // power amplifier level
//    nrf.stopListening();
}

void loop() {
  while (!Serial.available());
  x = Serial.readString().toInt();

  if(x == 1) { // open
    Serial.print("Opening...");
    myStepper.step(-1 * NUM_REVS * STEPS_PER_REVOLUTION);
//    const char data[] = "1";
//
//    nrf.write(&data, 1);
  } else if (x == 0) { // close
    Serial.print("Closing...");
    myStepper.step(1 * NUM_REVS * STEPS_PER_REVOLUTION);
//    const char data[] = "0";
//
//    nrf.write(&data, 1);
  }
  
}
