#include "Joueur.h"
#include <Arduino.h>

using namespace std;

//Constructeur
Joueur :: Joueur(){
    nbJoueur ++;
}

//Destructeur
Joueur::~Joueur(){

}

void Joueur::saisiePseudo(){
    String _pseudo;
    char caractere;

    Serial.println("Entrez votre pseudo :");
      while (Serial.available() == 0);
      while (Serial.available() != 0){
        caractere = Serial.read();
        _pseudo = _pseudo + caractere;
        delay(80);
      }
     
    pseudo = _pseudo;
    Serial.print("Bienvenue ");
    Serial.println(pseudo);
}

void Joueur::majScore(int _score){
    score = _score;
    Serial.print("Votre meilleur score : ");
    Serial.println(score);
}

int Joueur::getScore()
{
    return score;
}

void Joueur::afficherPseudo()
{
    Serial.println(pseudo);
}

String Joueur::getPseudo()
{
    return pseudo;
}

bool operator == (const Joueur & Joueur1, const Joueur & Joueur2){
    return (Joueur1.pseudo == Joueur2.pseudo);
}
