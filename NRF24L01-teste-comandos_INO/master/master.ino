/* NRF24L01 teste comandos - master
 * Joao Tavares
 * 2019 May 31th
 * Arduino Uno e NRF24L01
 *  CE    -> 7
 *  CSN   -> 8
 *  SCK   -> 13
 *  MOSI  -> 11
 *  MISO  -> 12
 */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

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
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
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
  delay(10);
}
