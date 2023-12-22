/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h>

#define PIN_INPUT 1 //défini le port A1 pour la photorésistance
#define PIN_OUTPUT 9 //défini le port 9 pour la led

double Setpoint, Input, Output; //défini les varaibles connectée entre eux

double Kp=0, Ki=10, Kd=0; //Caractéristique des paramètres
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  Input = analogRead(PIN_INPUT); //Input vaut la valeur lue en PIN_INPUT

  myPID.SetMode(AUTOMATIC); //allume le PID
  Setpoint = 100; //point de "sensibilité"
}

void loop()
{
  Input = analogRead(PIN_INPUT); //Input vaut la valeur lue en PIN_INPUT
  myPID.Compute(); //PID en fonctionnement
  analogWrite(PIN_OUTPUT, Output); //écrire la valeur de PIN_OUTPUT en Output
}