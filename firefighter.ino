#include <Servo.h>
#include <Stepper.h>
#define PAS 32 
 

Stepper motor(PAS,8,10,9,11);
Servo servo;

int pos = 90;
bool coboara = 1;

//Senzori
#define FLACARA_stg 22

#define FLACARA_dr 24

#define FLACARA_mijD_a A1
#define FLACARA_mijD 23
#define FLACARA_mijS_a A2
#define FLACARA_mijS 25
#define FLACARA_mij_digital 26

int FLACARA_mij = A0;
boolean fire = false;

int buzzer = 53;
int pompa = 2;

//Motoare
int motor1pin1 = 4; //motor stanga 
int motor1pin2 = 5; //PIN2 HIGH TO GO FORWARD
int motor2pin1 = 6; //motor dreapta
int motor2pin2 = 7;



void setup() {
  Serial.begin(9600);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(FLACARA_stg, INPUT);
  pinMode(FLACARA_dr, INPUT);
  pinMode(FLACARA_mijD, INPUT);
  pinMode(FLACARA_mijS, INPUT);
  
  pinMode(FLACARA_mijD_a, INPUT);
  pinMode(FLACARA_mijS_a, INPUT);
  
  pinMode(FLACARA_mij, INPUT);
  pinMode(FLACARA_mij_digital, INPUT);
  
  pinMode(buzzer, OUTPUT);
  pinMode(pompa,OUTPUT);
  
  servo.attach(3);
  servo.write(pos);
  motor.setSpeed(100);

  digitalWrite(pompa,HIGH);//logica inversa

}

void go_right(){
  digitalWrite(motor1pin1, LOW); 
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}
void go_left(){

  digitalWrite(motor1pin1, LOW); 
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}
void go_forward(){
//     Serial.println("Fata");
    //fata 
  digitalWrite(motor1pin1, LOW); 
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

void go_backwards(){
//     Serial.println("Spate");  
    //spate
  digitalWrite(motor1pin1, HIGH); 
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void Stop(){
//     Serial.println("Stop");
    //stop
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
}

void porneste_servo(){
      if(coboara == 1)
      {
          if(pos > 70)
              pos-=3;
          else coboara = 0; 
      }
      else{
            if(pos < 80)
                pos+=3;
            else coboara = 1;
      }
           delay(20);
           servo.write(pos);   
 }

void put_off_fire()
{

    servo.write(70);
   digitalWrite(pompa, LOW);//pornesc pompa
   delay (2000);

    
    motor.step(-100);//cclockwise
    porneste_servo();

    motor.step(200);
    porneste_servo();
    motor.step(-100); // ducem turela inapoi pe centru
   
    fire = false;
    servo.write(90);
    noTone(buzzer);


    digitalWrite(pompa, HIGH);


}


void loop() {  

      
     delay(5);
     if(analogRead(FLACARA_mij) < 300){
        go_backwards();
        delay(200);
     }
     else if (analogRead(FLACARA_mij) < 500) 
     {  
      Stop();
      fire = true;
      delay(200);
      tone(buzzer,450);
     }
     else if (digitalRead(FLACARA_stg) == 0 || digitalRead(FLACARA_mijS) == 0)
     {
        go_left();
        tone(buzzer,450);
     }
     else if (digitalRead(FLACARA_dr) == 0 || digitalRead(FLACARA_mijD) == 0) 
     {
      go_right();
      tone(buzzer,450);
     }
     else if (analogRead(FLACARA_mij) < 850) 
     {
      go_forward();
      tone(buzzer,450);
     }

     while(fire == true){
      Serial.println("!!!FIRE!!!");
      put_off_fire();
    }
}
