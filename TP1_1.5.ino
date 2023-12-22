int LED = 9; //Création du port 9 pour la led
int pot = A0; //Création du port A0 pour le potentiomètre
int pot_value = 0; //Création de la variable pot_value

void setup() {
  pinMode(LED, OUTPUT); //Initialisation de LED en sortie
  pinMode(pot, INPUT); //Initialisation de pot en entrée
}

void loop() {
  pot_value = analogRead(pot); //pot_value vaut la valeur lue de pot (port A0)
  pot_value = pot_value/4; //intensite vaut pot_value diviser par 4 (pour attenidre 255 au max)
  analogWrite(LED, pot_value); //mettre la luminosité de la led a la valeur de pot_value
  delay(50); //attendre 50ms
}