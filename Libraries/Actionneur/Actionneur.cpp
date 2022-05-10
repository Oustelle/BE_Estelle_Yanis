#include "Actionneur.h"

using namespace std;

//Constructeur
Actionneur :: Actionneur(){
	nbActionneur ++;
}

//Destructeur
Actionneur::~Actionneur(){

}

void Actionneur::afficherNbActionneur()
{
	Serial.println("**************************");
    Serial.println("Nombre d'Actionneurs crees :");
    Serial.println("**************************");
}
