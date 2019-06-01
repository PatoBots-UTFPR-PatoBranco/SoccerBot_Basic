/* Motores testes
 * Vitor
 * 31/05/2019
 */
 #define motor_left_IN1 4
 #define motor_left_IN2 5
 #define motor_right_IN1 6
 #define motor_right_IN2 7
 #define motor_back_IN1 2
 #define motor_back_IN2 3

 #define led 13

 uint8_t i;
 bool state = HIGH;
 
void forward(){
  
 //Gira o Motor A no sentido horario
 digitalWrite(motor_left_IN2, LOW);
 //Gira o Motor B no sentido horario
 digitalWrite(motor_right_IN2, LOW);
 for(i=0; i<255; i++)
 {
  analogWrite(motor_left_IN1, i);
  analogWrite(motor_right_IN1, i);
  delay(50);  

  state = !state;
  digitalWrite(led, state);
 }
 
 digitalWrite(led, HIGH);
 delay(1000);
 
 //Para o motor A
 digitalWrite(motor_left_IN1, HIGH);
 digitalWrite(motor_left_IN2, HIGH);
 //Para o motor B
 digitalWrite(motor_right_IN1, HIGH);
 digitalWrite(motor_right_IN2, HIGH);
 
 digitalWrite(led, LOW);
 delay(1000);
}

void forwardA(){
//Gira o Motor A no sentido horario
 digitalWrite(motor_left_IN2, LOW);
 
 for(i=0; i<255; i++)
 {
  analogWrite(motor_left_IN1, i);
  delay(50);  

  state = !state;
  digitalWrite(led, state);
 }
 
 digitalWrite(led, HIGH);
 delay(1000);
 
 //Para o motor A
 digitalWrite(motor_left_IN1, HIGH);
 digitalWrite(motor_left_IN2, HIGH);

 digitalWrite(led, LOW);
}

void forwardB(){
//Gira o Motor B no sentido horario
 digitalWrite(motor_right_IN2, LOW);
 for(i=0; i<255; i++)
 {
  analogWrite(motor_right_IN1, i);
  delay(50);
  
  state = !state;
  digitalWrite(led, state);
 }
 
 digitalWrite(led, HIGH);
 delay(1000);

 //Para o motor B
 digitalWrite(motor_right_IN1, HIGH);
 digitalWrite(motor_right_IN2, HIGH);

 digitalWrite(led, LOW); 
  
}

void backward(){
  
 //Gira Motor A e B no sentido Anti-horário
 digitalWrite(motor_left_IN1, LOW);
 digitalWrite(motor_right_IN1, LOW);

 for(i=0; i<255; i++){
  analogWrite(motor_left_IN2, i);
  analogWrite(motor_right_IN2, i);
  delay(50);
  
  state = !state;
  digitalWrite(led, state);  
 }

 digitalWrite(led, HIGH);

 //Freia Motores A e B
 digitalWrite(motor_left_IN1, HIGH);
 digitalWrite(motor_left_IN2, HIGH);
 digitalWrite(motor_right_IN1, HIGH);
 digitalWrite(motor_right_IN2, HIGH);

 digitalWrite(led,LOW);
}
void left(){
  
  digitalWrite(motor_back_IN1, LOW);
  
  for(i=0; i<255; i++){
  analogWrite(motor_back_IN2, i);
  delay(50);
  
  state = !state;
  digitalWrite(led, state);  
 }

 digitalWrite(led, HIGH);

 //Freia Motore C
 digitalWrite(motor_back_IN1, HIGH);
 digitalWrite(motor_back_IN2, HIGH);

 digitalWrite(led,LOW);
}

void right(){
  digitalWrite(motor_back_IN2, LOW);
  
  for(i=0; i<255; i++){
  analogWrite(motor_back_IN1, i);
  delay(50);
  
  state = !state;
  digitalWrite(led, state);  
 }

 digitalWrite(led, HIGH);

 //Freia Motore C
 digitalWrite(motor_back_IN1, HIGH);
 digitalWrite(motor_back_IN2, HIGH);

 digitalWrite(led,LOW);
}

void rotate_left(){
 //Gira motor A anti-horario e B horario
 digitalWrite(motor_right_IN2, LOW);
 digitalWrite(motor_left_IN1, LOW);
 for(i=0; i<255; i++)
 {
  analogWrite(motor_right_IN1, i);
  analogWrite(motor_left_IN2, i);
  delay(50);
  
  state = !state;
  digitalWrite(led, state);
 }
 
 digitalWrite(led, HIGH);
 delay(1000);

 //Freia Motores A e B
 digitalWrite(motor_left_IN1, HIGH);
 digitalWrite(motor_left_IN2, HIGH);
 digitalWrite(motor_right_IN1, HIGH);
 digitalWrite(motor_right_IN2, HIGH);
 digitalWrite(led, LOW); 
}

void rotate_right(){
  //Gira motor B anti-horario e A horario
 digitalWrite(motor_right_IN1, LOW);
 digitalWrite(motor_left_IN2, LOW);
 for(i=0; i<255; i++)
 {
  analogWrite(motor_right_IN2, i);
  analogWrite(motor_left_IN1, i);
  delay(50);
  
  state = !state;
  digitalWrite(led, state);
 }
 
 digitalWrite(led, HIGH);
 delay(1000);

 //Freia Motores A e B
 digitalWrite(motor_left_IN1, HIGH);
 digitalWrite(motor_left_IN2, HIGH);
 digitalWrite(motor_right_IN1, HIGH);
 digitalWrite(motor_right_IN2, HIGH);
 digitalWrite(led, LOW); 
}
void setup() {
  // put your setup code here, to run once:
  pinMode(motor_left_IN1, OUTPUT);
  pinMode(motor_left_IN2, OUTPUT);
  pinMode(motor_right_IN1, OUTPUT);
  pinMode(motor_right_IN2, OUTPUT);
  //pinMode(IN5, OUTPUT);
  //pinMode(IN6, OUTPUT);

  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:  
  forward();
  rotate_right();
  rotate_left();
  left();
  right();
  forwardA();
  forwardB(); 
  backward();

}
