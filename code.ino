#define IR_SENSOR_LEFT 11
#define IR_SENSOR_RIGHT 12
#define MOTOR_SPEED_A 180 //Adjust to your situation
#define MOTOR_SPEED_B 190 //Adjust to your situation

//Left motor
int enableBMotor=6;
int BMotorPin1=7;
int BMotorPin2=8;

//Right motor
int enableAMotor=5;
int AMotorPin1=9;
int AMotorPin2=10;

void setup(){
  TCCR0B = TCCR0B & B11111000 | B00000010 ;

  pinMode(AMotorPin1, OUTPUT);
  pinMode(AMotorPin2, OUTPUT);

  pinMode(BMotorPin1, OUTPUT);
  pinMode(BMotorPin2, OUTPUT);

  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);

  Serial.begin(9600);
}

void loop(){
  int leftIr = !digitalRead(IR_SENSOR_LEFT);
  int rightIr = !digitalRead(IR_SENSOR_RIGHT);

  if (leftIr == HIGH && rightIr == HIGH){
    Serial.println("MOVE FORWARD");
    runMotor(MOTOR_SPEED_A, MOTOR_SPEED_B);
  }
  else if (leftIr == LOW && rightIr == HIGH){
    Serial.println("TURN LEFT");
    runMotor(MOTOR_SPEED_A, -MOTOR_SPEED_B);
  }
  else if (leftIr == HIGH && rightIr == LOW){
    Serial.println("TURN RIGHT");
    runMotor(-MOTOR_SPEED_A, MOTOR_SPEED_B);
  }
  else{
    runMotor(0,0);
    Serial.println("STOP");
  }

}

void runMotor(int rightA, int leftB){
  if (leftB > 0 && rightA > 0){
    digitalWrite(AMotorPin1, (HIGH));
    digitalWrite(AMotorPin2, (LOW));
    digitalWrite(BMotorPin1, (HIGH));
    digitalWrite(BMotorPin2, (LOW));

    analogWrite(enableAMotor, MOTOR_SPEED_A);
    analogWrite(enableBMotor, MOTOR_SPEED_B);
  }
  else if (leftB < 0 && rightA > 0){
    digitalWrite(AMotorPin1, (HIGH));
    digitalWrite(AMotorPin2, (LOW));
    digitalWrite(BMotorPin1, (LOW));
    digitalWrite(BMotorPin2, (HIGH));

    analogWrite(enableAMotor, MOTOR_SPEED_A);
    analogWrite(enableBMotor, MOTOR_SPEED_B);
  }
  else if (leftB > 0 && rightA < 0){
    digitalWrite(AMotorPin1, (LOW));
    digitalWrite(AMotorPin2, (HIGH));
    digitalWrite(BMotorPin1, (HIGH));
    digitalWrite(BMotorPin2, (LOW));

    analogWrite(enableAMotor, MOTOR_SPEED_A);
    analogWrite(enableBMotor, MOTOR_SPEED_B);
  }
  else if (leftB == 0 and rightA == 0){
    digitalWrite(AMotorPin1, (LOW));
    digitalWrite(AMotorPin2, (LOW));
    digitalWrite(BMotorPin1, (LOW));
    digitalWrite(BMotorPin2, (LOW));

    analogWrite(enableAMotor, 0);
    analogWrite(enableBMotor, 0);

    Serial.println("FUNCtiON STOP");
  }
  
}
