// Oct 6 2026
// Made by Shubham Baxi
// Please give credit if the following is used

// Sensor and Speed Definition
#define IR_LEFT 12
#define IR_RIGHT 11
#define MOTOR_SPEED_L 182
#define MOTOR_SPEED_R 180
#define TURNING 60
#define TURNING_MAX 200

// Manual Toggle Switch
// To turn with both wheels in opposite directions, write true
// To turn with both wheels in same direction in different speeds, write false
// false is recommended
bool turning = false;

//Right motor variables
int enableRight=6;
int rightPin1=7;
int rightPin2=8;

//Left motor variables
int enableLeft=5;
int leftPin1=9;
int leftPin2=10;

void turnMotor(int speed_l, int speed_r, int dir_l = 1,  int dir_r = 1){
  // speed_l : speed of left motor when moving
  // speed_r : speed of right motor while moving
  // dir_l   : direction of left motor. 1 = Forward ; -1 = Backward
  // dir_r   : direction of right motor. 1 = Forward ; -1 = Backward
  analogWrite(enableLeft, speed_l); // set speed of left motor
  digitalWrite(leftPin1, dir_l == 1); // set pin1 of left motor to direction of dir_l
  digitalWrite(leftPin2, dir_l == -1); // set pin2 of left motor to opposite direction of dir_l

  analogWrite(enableRight, speed_r); // set speed of right motor
  digitalWrite(rightPin1, dir_r == 1); // set pin1 of right motor to direction of dir_r
  digitalWrite(rightPin2, dir_r == -1); // set pin2 of right motor to opposite direction of dir_r
}

// the TCCR0B line disrupts delay function. Make own safe delay function to normalize the disruption
void safeDelay(unsigned long ms) {
  delay(ms * 8); 
}

void setup() {

  TCCR0B = TCCR0B & B11111000 | B00000010 ; // increases PWM value to ~3.9 kHz to make sure motors do not whine and make sure motors run smoothly


  // IR definitions
  pinMode(IR_LEFT,INPUT);
  pinMode(IR_RIGHT,INPUT);

  // Right Motor Definitions
  pinMode(enableRight, OUTPUT);
  pinMode(rightPin1, OUTPUT);
  pinMode(rightPin2, OUTPUT);

  // Left Motor Definitions
  pinMode(enableLeft, OUTPUT);
  pinMode(leftPin1, OUTPUT);
  pinMode(leftPin2, OUTPUT);

  // starts serial communication on 9600 baud
  Serial.begin(9600);

}

void loop() {
  // 1 is returned by IR sensors on black
  // 0 is returned by IR sensors on white

  int left_ir = digitalRead(IR_LEFT); // left_ir contains value of left ir sensor
  int right_ir = digitalRead(IR_RIGHT); // right_ir contains value of right ir sensor

  Serial.println("__________");
  Serial.println(left_ir);
  Serial.println(right_ir);

  if (left_ir == 0 && right_ir == 0){
    //Both IR sensors sense white
    //need to move forward
    turnMotor(MOTOR_SPEED_L, MOTOR_SPEED_R);
    Serial.println("Moving Forward");
  }
  else if (left_ir == 0 && right_ir == 1){ 
    //Left IR on white and Right IR on black
    //overshoot to left, need to turn right
    if (turning == true){
      turnMotor(TURNING_MAX, TURNING, 1,-1);
    }
    else{
      turnMotor(MOTOR_SPEED_L, MOTOR_SPEED_R, 1,-1);
    }
    Serial.println("Right");
  }
  else if (left_ir == 1 && right_ir == 0){
    //Left IR on black and Right IR on white
    //overshoot to right, need to turn left
    if (turning == true){
      turnMotor(TURNING, TURNING_MAX , -1,1);
    }
    else{
      turnMotor(MOTOR_SPEED_L, MOTOR_SPEED_R, -1,1);
    }
    Serial.println("Left");
  }
  else if (left_ir == 1 && right_ir == 1){
    //Both IR sensors sense black
    // need to stop
    turnMotor(0, 0);
    Serial.println("Stopped");
  }
  safeDelay(8); // use delay in looping to prevent jerkiness
}
