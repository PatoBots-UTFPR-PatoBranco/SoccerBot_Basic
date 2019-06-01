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

 uint8_t i = 120;

void forwardA(uint8_t value){
//Gira o Motor A no sentido horario
 digitalWrite(motor_left_IN2, LOW);
 analogWrite(motor_left_IN1, value);
}

void forwardB(uint8_t value){
//Gira o Motor B no sentido horario
 digitalWrite(motor_right_IN2, LOW);
 analogWrite(motor_right_IN1, value);
}

void backwardA(uint8_t value){
  //Gira o Motor A no sentido antihorario
  digitalWrite(motor_left_IN2,LOW);
  analogWrite(motor_left_IN1, value);
}

void backwardB(uint8_t value){
 //Gira o Motor B no sentido anti-horario
 digitalWrite(motor_right_IN1, LOW);
 analogWrite(motor_right_IN2, value);
}
 
void forward(uint8_t value){  
 forwardA(value);
 forwardB(value);
}

void backward(uint8_t value){
  backwardA(value);
  backwardB(value);
}
void left(uint8_t value){
 digitalWrite(motor_back_IN1, LOW);
 analogWrite(motor_back_IN2, value);
}

void right(uint8_t value){
 digitalWrite(motor_back_IN2, LOW);
 analogWrite(motor_back_IN1, value);
 
}

void rotate_left(uint8_t value){
 //Gira motor A anti-horario e B horario
 backwardA(value);
 forwardB(value);
}

void rotate_right(uint8_t value){
  //Gira motor B anti-horario e A horario
 digitalWrite(motor_right_IN1, LOW);
 digitalWrite(motor_left_IN2, LOW);
 analogWrite(motor_right_IN2, value);
 analogWrite(motor_left_IN1, value);
 
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
void setup() {
  // put your setup code here, to run once:
  pinMode(motor_left_IN1, OUTPUT);
  pinMode(motor_left_IN2, OUTPUT);
  pinMode(motor_right_IN1, OUTPUT);
  pinMode(motor_right_IN2, OUTPUT);
  pinMode(motor_back_IN1, OUTPUT);
  pinMode(motor_back_IN2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:  
  forward(i);
  delay(1000);
  stop_bot();
  delay(100);
  rotate_right(i);
  delay(1000);
  stop_bot();
  delay(100);
  rotate_left(i);
  delay(1000);
  stop_bot();
  delay(100);
  left(i);
  delay(1000);
  stop_bot();
  delay(100);
  right(i);
  delay(1000);
  stop_bot();
  delay(100);
  forwardA(i);
  delay(1000);
  stop_bot();
  forwardB(i); 
  delay(1000);
  stop_bot();
  delay(100);
  backward(i);
  delay(1000);
  stop_bot();
  delay(100);

}
