#ifndef ACTIONNEUR_H_
#define ACTIONNEUR_H_

#include <Arduino.h>
#include <iostream>
#include <string>

using namespace std;

class Actionneur{

private :
	int nbActionneur = 0;

public:
	//Constructeur
	Actionneur();

	//Destructeur
	virtual ~Actionneur();

	//Affiche les caracteristiques de l'actionneur
	virtual void afficherCaracteristiques() = 0;

	//Affiche le nombre de capteur créé
	void afficherNbActionneur();

};

#endif
