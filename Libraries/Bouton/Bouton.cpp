#include "Bouton.h"
#include "iostream"

using namespace std;

//Constructeur
Bouton:: Bouton(int _pin){
	pin = _pin;
	init();
}

//Destructeur
Bouton::~Bouton(){

}

void Bouton::init()
{
	pinMode(pin, INPUT);
    
}

int Bouton::avoirEtat()
{
    etat = digitalRead(pin);
	return etat;
}

bool Bouton::presse()
{
	return (avoirEtat() == LOW);
}

bool Bouton::lache()
{
    return (avoirEtat() == HIGH);
}

void Bouton::afficherCaracteristiques()
{
    Serial.println("*************************");
    Serial.println("Type de capteur : bouton");
    Serial.print("Numero de la PIN : ");
    Serial.println(pin);
    Serial.print("Etat actuel : ");
    Serial.println(avoirEtat());
    Serial.println("*************************");
}
