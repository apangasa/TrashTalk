#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 nrf(9, 8); // CE, CNS

int x;

const byte address[6] = "gator";


void setup() {
    Serial.begin(9600);
    while(!Serial) {}

    nrf.begin();
    nrf.openWritingPipe(address);
    nrf.setPALevel(RF24_PA_MIN); // power amplifier level
    nrf.stopListening();
}

void loop() {
  while (!Serial.available());
  x = Serial.readString().toInt();

  if(x == 1) { // open
    Serial.print("Opening...");
    const char data[] = "1";

    nrf.write(&data, 1);
  } else if (x == 0) { // close
    Serial.print("Closing...");
    const char data[] = "0";

    nrf.write(&data, 1);
  }
  
}
