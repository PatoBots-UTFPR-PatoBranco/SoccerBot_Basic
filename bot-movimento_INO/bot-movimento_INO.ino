/*  NRF24L01 teste comandos - slave
 *  Joao Tavares
 *  Vitor Oliveira
 *  2019 May 31th
 */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


/****************** NRF Config ***************************/
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

#define bot_stop          0
#define bot_foward        1
#define bot_backward      2
#define bot_clockwise     3
#define bot_anticlockwise 4
#define bot_right         5
#define bot_left          6
/**********************************************************/

/****************** Motor Config ***************************/
#define motor_left_IN1 4 
#define motor_left_IN2 5
#define motor_right_IN1 6
#define motor_right_IN2 10
#define motor_back_IN1 2
#define motor_back_IN2 3

void forwardA_bot(uint8_t value){
//Gira o Motor A no sentido horario
 digitalWrite(motor_left_IN2, LOW);
 analogWrite(motor_left_IN1, value);
}

void forwardB_bot(uint8_t value){
//Gira o Motor B no sentido horario
 digitalWrite(motor_right_IN2, LOW);
 analogWrite(motor_right_IN1, value);
}

void backwardA_bot(uint8_t value){
  //Gira o Motor A no sentido antihorario
  digitalWrite(motor_left_IN2,LOW);
  analogWrite(motor_left_IN1, value);
}

void backwardB_bot(uint8_t value){
 //Gira o Motor B no sentido anti-horario
 digitalWrite(motor_right_IN1, LOW);
 analogWrite(motor_right_IN2, value);
}
 
void forward_bot(uint8_t value){  
 forwardA_bot(value);
 forwardB_bot(value);
}

void backward_bot(uint8_t value){
  backwardA_bot(value);
  backwardB_bot(value);
}
void left_bot(uint8_t value){
 digitalWrite(motor_back_IN1, LOW);
 analogWrite(motor_back_IN2, value);
}

void right_bot(uint8_t value){
 digitalWrite(motor_back_IN2, LOW);
 analogWrite(motor_back_IN1, value);
 
}

void rotate_left_bot(uint8_t value){
 //Gira motor A anti-horario e B horario
 backwardA_bot(value);
 forwardB_bot(value);
}

void rotate_right_bot(uint8_t value){
 //Gira motor B anti-horario e A horario
 backwardB_bot(value);
 forwardA_bot(value); 
}
void stop_bot(){
 //Freia Motores A, B e C
 digitalWrite(motor_left_IN1, HIGH);
 digitalWrite(motor_left_IN2, HIGH);
 digitalWrite(motor_right_IN1, HIGH);
 digitalWrite(motor_right_IN2, HIGH);
 digitalWrite(motor_back_IN1, HIGH);
 digitalWrite(motor_back_IN2, HIGH);
}
/**********************************************************/

void setup(void)
{
  // radio init
  Serial.begin(57600);

  // motor init
  pinMode(motor_left_IN1, OUTPUT);
  pinMode(motor_left_IN2, OUTPUT);
  pinMode(motor_right_IN1, OUTPUT);
  pinMode(motor_right_IN2, OUTPUT);
  pinMode(motor_back_IN1, OUTPUT);
  pinMode(motor_back_IN2, OUTPUT);

  // radio init
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop(void)
{
  if ( radio.available() )
  {
    uint16_t data = 0;
    radio.read( &data, sizeof(uint16_t) );

    Serial.println(data);
    
    if(data == bot_stop)
      stop_bot();
    else if(data == bot_foward)
      forward_bot(125);
    else if(data == bot_backward)
      backward_bot(125);
    else if(data == bot_clockwise)
      rotate_right_bot(125);
    else if(data == bot_anticlockwise)
      rotate_left_bot(125);
    else if(data == bot_right)
      right_bot(125);
    else if(data == bot_left)
      left_bot(125);
    else stop_bot();

    delay(1000);
  }
}
