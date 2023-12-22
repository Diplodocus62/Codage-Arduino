/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h>

#define PIN_INPUT 1 //défini le port A1 pour la photorésistance
#define PIN_OUTPUT 9 //défini le port 9 pour la led
#define PIN_pot 0 //défini le port A0 pour le potentiomètre

int pot = 0; //Création de variable pot

double Setpoint, Input, Output; //défini les varaibles connectée entre eux

double Kp=0, Ki=10, Kd=0; //Caractéristique des paramètres
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  Input = analogRead(PIN_INPUT); //Input vaut la valeur lue en PIN_INPUT
  pinMode(PIN_pot, INPUT); //Initialistaion de PIN_pot en entrée

  myPID.SetMode(AUTOMATIC); //allume le PID
}

void loop()
{
  pot = analogRead(PIN_pot); //pot vaut la valeur lue en PIN_pot
  pot = pot/4; //pot vaut pot/4
  Setpoint = pot; //point de "sensibilité" en fonction de la valeur du potentiomètre
  Input = analogRead(PIN_INPUT); //Input vaut la valeur lue en PIN_INPUT
  myPID.Compute(); //PID en fonctionnement
  analogWrite(PIN_OUTPUT, Output); //écrire la valeur de PIN_OUTPUT en Output
}