/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h>
const int photores = A1; // entree photoresistance
const int pot = A0; // entree potentiometre
const int led = 9; // pin de la led
double lightLevel; // variable qui stocke le niveaue de lumiÃ¨re entrant

// parametres de rÃ©gulation
float Kp = 0; // valeur initiale du gain proportionnel 
float Ki = 10; // valeur initiale du gain intÃ©gral 
float Kd = 5;  // valeur initiale du gain diffÃ©rentiel  

double Consigne, Entree, Sortie;  //Variables pour stocker les valeurs
PID myPID(&Entree, &Sortie, &Consigne, Kp, Ki, Kd, DIRECT); 

const int sampleRate = 1; // Variable qui dÃ©termine la vitesse Ã  laquelle le PID tourne

// Parametrage de la communication
const long serialPing = 500; //Cela determine a quelle periode on ping la boucle (en ms)
unsigned long now = 0; //Cette variable sert Ã  compter le temps
unsigned long lastMessage = 0; //Cette variable permet de garder une trace de quand notre boucle a communique avec le port serie pour la derniere fois

void setup(){
  lightLevel = analogRead(photores); //Lire le niveau
  Entree = map(lightLevel, 0, 1024, 0, 255); //Changer les amplitudes
  Consigne = map(analogRead(pot), 0, 1024, 0, 255);  //Lire la consigne
  Serial.begin(9600); //Commencer une communication via le port serie
  myPID.SetMode(AUTOMATIC);  //Demarrer la regulation PID
  myPID.SetSampleTime(sampleRate); //Regle la periode d'echantillonnage
  
  Serial.println("Debut"); // On commence
  lastMessage = millis(); // Marque du temps
}

void loop(){
  Consigne = map(analogRead(pot), 0, 1024, 0, 255); //Lire la consigne
  lightLevel = analogRead(photores); //Obtenir le niveau lumineux
  Entree = map(lightLevel, 0, 900, 0, 255); //En deduire l'entree
  myPID.Compute();  //Faire tourner la boucle PID
  analogWrite(led, Sortie);  //Ecrire la sortie du PID comme entree MLI de la LED
  
  now = millis(); // Marque du temps
  if(now - lastMessage > serialPing) {  // A commenter !!!
    Serial.print("Consigne = ");
    Serial.print(Consigne);
    Serial.print(" Entree = ");
    Serial.print(Entree);
    Serial.print(" Sortie = ");
    Serial.print(Sortie);
    Serial.print("\n");
    if (Serial.available() > 0) { //Nous voulons mettre a jour Kp, Ki et Kd
      for (int x = 0; x < 4; x++) {
        switch (x) {
          case 0:
            Kp = Serial.parseFloat();  
            break;
          case 1:
            Ki = Serial.parseFloat();
            break;
          case 2:
            Kd = Serial.parseFloat();
            break;
          case 3:
            for (int y = Serial.available(); y == 0; y--) {
              Serial.read();  
            }
            break;
        }
      }
      Serial.print(" Kp,Ki,Kd = ");
      Serial.print(Kp);
      Serial.print(",");
      Serial.print(Ki);
      Serial.print(",");
      Serial.println(Kd);  //On affiche les valeurs pour verifier qu'elles ont bien ete mises a jour
      myPID.SetTunings(Kp, Ki, Kd); //On regle les nouveaux parametres du PID et on relance la regulation
    }
    
    lastMessage = now; 
    //Marque du temps. 
  }
  
}