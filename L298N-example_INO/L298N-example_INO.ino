/* H Bridge L298N example on Arduino 
 * Joao Tavares
 * 2019 May 31th
 * Arduino Mega
 */

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

#define led 13
  
void setup()
{
  //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);

 pinMode(led, OUTPUT);
}
  
void loop()
{
  uint8_t i;
  bool state = HIGH;
  
 //Gira o Motor A no sentido horario
 digitalWrite(IN2, LOW);
 
 for(i=0; i<255; i++)
 {
  analogWrite(IN1, i);
  delay(50);

  state = !state;
  digitalWrite(led, state);
 }
 
 digitalWrite(led, HIGH);
 delay(1000);
 
 //Para o motor A
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
 
 digitalWrite(led, LOW);
 delay(1000);
}
