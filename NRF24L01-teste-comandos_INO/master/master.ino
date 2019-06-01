/* NRF24L01 teste comandos - master
 * Joao Tavares
 * 2019 May 31th
 * 
 */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9,10);
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

#define bot_stop          0
#define bot_foward        1
#define bot_backward      2
#define bot_clockwise     4
#define bot_anticlockwise 5
#define bot_right         6
#define bot_left          7

uint16_t command;
String str = "0";

void setup()
{
  Serial.begin(57600);
  
  radio.begin();
  radio.setRetries(15,15);
  radio.openReadingPipe(1,pipes[1]);
  radio.startListening();
  radio.printDetails();
  radio.openWritingPipe(pipes[0]);
  radio.openReadingPipe(1,pipes[1]);
  radio.stopListening();
}

void loop()
{
  radio.stopListening();
  
  if(Serial.available())
    str = Serial.readStringUntil('\n');
  
  command = (uint16_t) str.toInt();
  if(command > bot_left)
    command=0;
  radio.write( &command, sizeof(uint16_t) );

  radio.startListening();
}
