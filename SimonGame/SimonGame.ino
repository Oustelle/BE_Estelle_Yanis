//#include "Joystick.h" //non utilisé, manque de temps
#include "Jeu.h"
#include <stdexcept>

void setup() {
  //Initialise le moniteur série
  Serial.begin(115200);
  Serial.println("Début du programme");
}

void loop() {
  //Bloc de code à tester pour l'erreur
  try {
    //Boucle de jeu
    Jeu jeu;
    jeu.initialisation();
    jeu.jouer();
    Serial.println("Fin du programme. Retour au menu principal");
  }
  //Bloc de code à exécuter si une erreur se produit dans try
  catch (modeErreur& e) {
    Serial.println(e.what()); //what() renvoi la cause d'une exception
  }
  
}
