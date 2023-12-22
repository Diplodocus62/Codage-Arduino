int LED = 9; //Créatio du port 9 pour la led
int pot = A0; //Création du port A0 pour le potentiomètre
int pot_value = 0; //création de la variable pot_value
int intensite = 0; //Création de la variable intensite
int photo_res = A1; //Création du port A1 pour photo_res
int lumi = 0; //Création de la variable lumi

void setup() {
  pinMode(LED, OUTPUT); //Initialisation de led en sortie
  pinMode(pot, INPUT); //Initialisation du potentiomètre en entrée
  Serial.begin(9600); //Connexion au moniteur 9600
  pinMode(photo_res, INPUT); //Initialisation de photo_res en entrée
}

void loop() {
  pot_value = analogRead(pot); //pot_value vaus la valeur lue de pot
  lumi = analogRead(photo_res); //lumi vaut la valeur lue de photo_res
  Serial.println(lumi); //écrire sur le moniteur les valeurs de lumi en passant des lignes
  intensite = pot_value/4; //intesite vaut la valeur de pot_value diviser par 4
  analogWrite(LED, intensite); //mettre la luminosité de la led a la valeur de intensite
  delay(50); //attendre 50ms
}