int LED = 9 //création du port 9 pour la LED

void setup() {
   pinMode(LED, OUTPUT); //initialisation de la LED en sortie
}

void loop() {
  analogWrite(LED, 64); //luminausité de la led à 25%
  delay(100); //attendre 100ms
  analogWrite(LED, 191); //luminausité de la led à 75%
  delay(100); //attendre 100ms
  analogWrite(LED, 255); //luminausité de la led à 100%
  delay(100); //attendre 100ms
}