#ifndef CAPTEUR_H_
#define CAPTEUR_H_

#include <Arduino.h>
#include <iostream>
#include <string>

using namespace std;

class Capteur{

private :
	int nbCapteur = 0;

public:
	//Constructeur
	Capteur();

	//Destructeur
	virtual ~Capteur();

	//Affiche les caracteristiques du capteur
	virtual void afficherCaracteristiques() = 0;

	//Affiche le nombre de capteur créé
	void afficherNbCapteur();

};

#endif
