

//teeth in big gear 178
// teeth in small gear 20
// gear ratio 8.9
// motor steps per revolution 400

int number_of_steps = 200;
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
int blinkDelay = 1000;
unsigned long MoveDelay = 60000;//60000;
int step_delay = 60L * 1000L / number_of_steps / whatspeed;
int step_direction = 0;
bool ledState = false;
unsigned long previousMillis=0;
unsigned long previousMillisMotor=0;
int moveCount = 0;
int countDelay = 0;

// change this t0 adjjust lag/gain in time
int lastmove = 5; //22 for 12v , actual 20


void setup() {


  pinMode(motor_pin_1, OUTPUT);
  pinMode(motor_pin_2, OUTPUT);
  pinMode(motor_pin_3, OUTPUT);
  pinMode(motor_pin_4, OUTPUT);
  pinMode(buttonPin,INPUT);
  pinMode(ledpin, OUTPUT);
  pinMode(enablepin,OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  blinkk();
  if (buttonState ==HIGH){
    enablemotor();
    movemotor(20);
    digitalWrite(ledpin,HIGH);
  }
  else{
    
    unsigned long currentMillisMotor = millis();

    if ((unsigned long)(currentMillisMotor - previousMillisMotor) >=MoveDelay) {
enablemotor();
      if ( moveCount >= 58){
        movemotor(lastmove);//22//23//25
        moveCount = 0;
      }
      else {

        movemotor(15);
        moveCount = moveCount + 1;
      }
      motoroff();
      previousMillisMotor = currentMillisMotor;
    }


    motoroff();

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

  unsigned long currentMillis = millis();
  //motoroff();
  if ((unsigned long)(currentMillis - previousMillis) >= blinkDelay) {

    ledState = !ledState; 
    digitalWrite(ledpin, ledState); 

    previousMillis = currentMillis;
  } 

}

void motoroff(){
  digitalWrite(enablepin,LOW);
  digitalWrite(motor_pin_1, LOW);
  digitalWrite(motor_pin_2, LOW);
  digitalWrite(motor_pin_3, LOW);
  digitalWrite(motor_pin_4, LOW);
}

void movemotor(int m){

  for (int x=0; x< m;x++){ 
    digitalWrite(motor_pin_1, HIGH);
    digitalWrite(motor_pin_2, LOW);
    digitalWrite(motor_pin_3, HIGH);
    digitalWrite(motor_pin_4, LOW);
    delay(step_delay);
    digitalWrite(motor_pin_1, LOW);
    digitalWrite(motor_pin_2, HIGH);
    digitalWrite(motor_pin_3, HIGH);
    digitalWrite(motor_pin_4, LOW);
    delay(step_delay);
    digitalWrite(motor_pin_1, LOW);
    digitalWrite(motor_pin_2, HIGH);
    digitalWrite(motor_pin_3, LOW);
    digitalWrite(motor_pin_4, HIGH);
    delay(step_delay);
    digitalWrite(motor_pin_1, HIGH);
    digitalWrite(motor_pin_2, LOW);
    digitalWrite(motor_pin_3, LOW);
    digitalWrite(motor_pin_4, HIGH);
    delay(step_delay);
  }
}














