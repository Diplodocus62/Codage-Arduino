int LED = 9 //Création du port 9 pour la LED

void setup() {
   pinMode(LED, OUTPUT); //Initialisation du port 8 (LED) en sortie
}

void loop() {
  digitalWrite(LED, HIGH); //allumer la led
  delay(1000); //attendre 1s
  digitalWrite(LED, LOW); //éteindre la led
  delay(1000); //attendre 1s
}