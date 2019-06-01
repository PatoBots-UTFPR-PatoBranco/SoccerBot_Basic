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
  forward_bot(i);
  delay(1000);
  stop_bot();
  delay(100);
  rotate_right_bot(i);
  delay(1000);
  stop_bot();
  delay(100);
  rotate_left_bot(i);
  delay(1000);
  stop_bot();
  delay(100);
  left_bot(i);
  delay(1000);
  stop_bot();
  delay(100);
  right_bot(i);
  delay(1000);
  stop_bot();
  delay(100);
  forwardA_bot(i);
  delay(1000);
  stop_bot();
  forwardB_bot(i); 
  delay(1000);
  stop_bot();
  delay(100);
  backward_bot(i);
  delay(1000);
  stop_bot();
  delay(100);

}
