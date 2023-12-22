int photo_res = A1; //Création du port A1 pour photo_res
int lumi = 0; //Création de la variable lumi

void setup() {
  Serial.begin(9600); //Connexion au moniteur 9600
  pinMode(photo_res, INPUT); //Initialisation de photo_res en entrée
}

void loop() {
  lumi = analogRead(photo_res); //lumi vaut la valeur lue de photo_res
  Serial.println(lumi); //écrire sur le moniteur les valeurs de lumi en passant des lignes
  delay(50); //attendre 50ms
}