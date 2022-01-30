#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 nrf(9, 8); // CE, CNS

const byte address[6] = "gator";

Servo servo;
int angle = 10;

void setup() {
  servo.attach(7);
  servo.write(angle);

  nrf.begin();
  nrf.openWritingPipe(address);
  nrf.setPALevel(RF24_PA_MIN); // power amplifier level
  nrf.startListening();
}


void loop() 
{ 
 // scan from 0 to 180 degrees
  for(angle = 10; angle < 180; angle++)  
  {                                  
    servo.write(angle);               
    delay(15);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 10; angle--)    
  {                                
    servo.write(angle);           
    delay(15);       
  } 
}
