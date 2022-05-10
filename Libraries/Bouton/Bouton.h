#ifndef BOUTON_H_
#define BOUTON_H_

#include <Arduino.h>
#include "Capteur.h"

class Bouton: public Capteur {

private :
    int pin;
	int etat;

public:
	//Constructeur
	Bouton(int _pin);

	//Destructeur
	virtual ~Bouton();

	//Initialisation
	void init();

	//Retourne l etat du bouton
	int avoirEtat();

	//Le bouton est pressé ?
	bool presse();
    
    //Le bouton est laché ?
    bool lache();
    
    void afficherCaracteristiques();
};

#endif
