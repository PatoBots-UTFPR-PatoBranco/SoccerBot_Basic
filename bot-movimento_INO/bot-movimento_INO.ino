/*  NRF24L01 teste comandos - slave
 *  Joao Tavares
 *  Vitor Oliveira
 *  2019 May 31th
 */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


/****************** NRF Config ***************************/
RF24 radio(9,10);
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

#define bot_stop          0
#define bot_foward        1
#define bot_backward      2
#define bot_clockwise     3
#define bot_anticlockwise 4
#define bot_right         5
#define bot_left          6
/**********************************************************/

void setup(void)
{  
  radio.begin();
  radio.setRetries(15,15);
  radio.openReadingPipe(1,pipes[1]);
  radio.startListening();
  radio.printDetails();
  radio.openWritingPipe(pipes[1]);
  radio.openReadingPipe(1,pipes[0]);
  radio.startListening();
}

void loop(void)
{
  if ( radio.available() )
  {
    uint16_t data = 0;
    radio.read( &data, sizeof(uint16_t) );

    if(data == bot_stop)
    else if(data == bot_foward)
    else if(data == bot_backward)
    else if(data == bot_clockwise)
    else if(data == bot_anticlockwise)
    else if(data == bot_right)
    else if(data == bot_left){}
    else

    delay(10);
  }
}
