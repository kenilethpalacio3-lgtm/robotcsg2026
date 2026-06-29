#include <Servo.h>
const int AIN1 = 1; 
const int AIN2 = 2; 
const int PWMA = 11;
const int PWMB = 10;
const int BIN2 = 9; 
const int BIN1 = 8;


const int AIN3 = 12; 
const int AIN4 = A1; 
const int PWMA2 = 0;
const int PWMB2 = A5;
const int BIN3 = 3;
const int BIN4 = 4;  

const int trigPin = 6;
const int echoPin = 5;

int palinquitapin = 7; 

float distancia = 0;

int backupTime = 300; 
int turnTime = 1250; 

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(palinquitapin, INPUT_PULLUP);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(AIN3, OUTPUT);
  pinMode(AIN4, OUTPUT);
  pinMode(PWMA2, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(BIN3, OUTPUT);
  pinMode(BIN4, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(PWMB2, OUTPUT);
  Serial.begin(9600); 
  Serial.print("be gone"); 
}

void loop()
{
  distancia = getdistancia();

  Serial.print("distancia: ");
  Serial.print(distancia);
  Serial.println(" in");
if (digitalRead(palinquitapin) == LOW )
{
      if (distancia < 8) 
      {
      Serial.print(" ");
      Serial.print("BE GONE!");

      rightMotor(0);
      leftMotor(0);
      delay(0);

      rightMotor(-255);
      leftMotor(-255);
      delay(backupTime);

      rightMotor(-250);
      leftMotor(250);
      delay(turnTime);
      } else 
        { 
        Serial.print(" ");
        Serial.print("Moving...");
        rightMotor(255);
        leftMotor(255);
        }
        delay(20);

} else 
    { 
    rightMotor(0);
    leftMotor(0);
    }
    delay(50);
}

void rightMotor(int velocidadmotor) 
{
  if (velocidadmotor > 0) 
  {
    digitalWrite(AIN1, HIGH); 
    digitalWrite(AIN2, LOW);   
    digitalWrite(AIN3, HIGH); 
    digitalWrite(AIN4, LOW);  
  }
  else if (velocidadmotor < 0) 
  {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(AIN3, LOW);
    digitalWrite(AIN4, HIGH);
  }
  else
  {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    digitalWrite(AIN3, LOW);
    digitalWrite(AIN4, LOW);
  }
  analogWrite(PWMA, abs(velocidadmotor));
  analogWrite(PWMA2, abs(velocidadmotor));
}

void leftMotor(int velocidadmotor)
{
  if (velocidadmotor > 0)
  {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    digitalWrite(BIN3, HIGH);
    digitalWrite(BIN4, LOW);
  }
  else if (velocidadmotor < 0)
  {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    digitalWrite(BIN3, LOW);
    digitalWrite(BIN4, HIGH);
  }
  else
  {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
    digitalWrite(BIN3, LOW);
    digitalWrite(BIN4, LOW);
  }
  analogWrite(PWMB, abs(velocidadmotor));
  analogWrite(PWMB2, abs(velocidadmotor));
}

float getdistancia()
{
  float echoTime;
  float calculateddistancia;

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);

  calculateddistancia = echoTime / 148.0;

  return calculateddistancia;
}
//@ney_2210zVT🍎