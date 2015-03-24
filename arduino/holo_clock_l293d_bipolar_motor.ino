int number_of_steps = 288;
int motor_pin_1 = 9;
int motor_pin_2 = 10;
int motor_pin_3 = 11;
int motor_pin_4 = 12;
int ledpin = 13;
int delayTime = 4;
int buttonPin = 4;
int buttonState = 0; 
int enablepin = 8;
int whatspeed = 40;
int last_step_time =0;
int step_number = 0;
int blinkDelay = 939;//945//938;//968;//995;
int step_delay = 60L * 1000L / number_of_steps / whatspeed;
int step_direction = 0;
void setup() {


  pinMode(motor_pin_1, OUTPUT);
  pinMode(motor_pin_2, OUTPUT);
  pinMode(motor_pin_3, OUTPUT);
  pinMode(motor_pin_4, OUTPUT);
  pinMode(buttonPin,INPUT);
  pinMode(ledpin, OUTPUT);
  pinMode(enablepin,OUTPUT);

}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState ==HIGH){
    enablemotor();
    movestep(20);
    digitalWrite(ledpin,HIGH);
  }
  else{
    digitalWrite(ledpin,LOW);

    for (int xx = 0; xx<59;xx ++){

      enablemotor();
      movestep(42);
      //delay(100);
      motoroff();
      blinkk();
    }
    enablemotor();
    movestep(89);//85;
   
    motoroff();
    blinkk();
   //delay(3000);
  }
}



void enablemotor(){
  digitalWrite(enablepin,HIGH);
}


void movestep(int steps_to_move){
  int steps_left = abs(steps_to_move);

  if (steps_to_move > 0) { 
    step_direction = 1;
  }
  if (steps_to_move < 0) { 
    step_direction = 0;
  }


  while(steps_left > 0) {
    // if (millis() - last_step_time >= step_delay ) {
    //last_step_time = millis();
    if ( step_direction == 1 ){
      step_number++;
      delay(step_delay);
      if (step_number == number_of_steps) {
        step_number = 0;
      }
    }
    else {
      if (step_number ==0){
        step_number = number_of_steps;
      }
      step_number--;
    }
    steps_left--;


    stepmotor(step_number % 4);


    //} 
  }
}





void stepmotor(int thisStep){

  switch (thisStep) {
  case 0:    // 1010
    digitalWrite(motor_pin_1, HIGH);
    digitalWrite(motor_pin_2, LOW);
    digitalWrite(motor_pin_3, HIGH);
    digitalWrite(motor_pin_4, LOW);
    break;
  case 1:    // 0110
    digitalWrite(motor_pin_1, LOW);
    digitalWrite(motor_pin_2, HIGH);
    digitalWrite(motor_pin_3, HIGH);
    digitalWrite(motor_pin_4, LOW);
    break;
  case 2:    //0101
    digitalWrite(motor_pin_1, LOW);
    digitalWrite(motor_pin_2, HIGH);
    digitalWrite(motor_pin_3, LOW);
    digitalWrite(motor_pin_4, HIGH);
    break;
  case 3:    //1001
    digitalWrite(motor_pin_1, HIGH);
    digitalWrite(motor_pin_2, LOW);
    digitalWrite(motor_pin_3, LOW);
    digitalWrite(motor_pin_4, HIGH);
    break;
  } 

}

void blinkk(){
  for (int i = 0 ; i<30;i++){
    buttonState = digitalRead(buttonPin);
    if (buttonState ==HIGH){
      break;
    }
    else{
      digitalWrite(ledpin, HIGH);   // set the LED on
      delay(blinkDelay);  // 968           // wait for a second
      digitalWrite(ledpin, LOW);    // set the LED off
      delay(blinkDelay); //968
    } 
  }
}

void motoroff(){
  digitalWrite(enablepin,LOW);
  digitalWrite(motor_pin_1, LOW);
  digitalWrite(motor_pin_2, LOW);
  digitalWrite(motor_pin_3, LOW);
  digitalWrite(motor_pin_4, LOW);
}







