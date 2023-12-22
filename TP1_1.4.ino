int LED = 9; //Création du port 9 pour la led
int pot = A0; //création du port A0 pour le potentiomètre
int pot_value = 0; //création de la variable pot_value

void setup() {
  pinMode(LED, OUTPUT); //Initialisation de led en sortie
  pinMode(pot, INPUT); //Initialistaion de pot en entrée
  Serial.begin(9600); //Création du moniteur en fréquence 9600
}

void loop() {
  pot_value = analogRead(pot); //pot_value vaut la valeur lu du potentiomètre
  Serial.println(pot_value); //écrire la valeur lue
}