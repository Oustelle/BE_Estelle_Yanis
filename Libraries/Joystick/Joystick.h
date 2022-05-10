#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#include <Arduino.h>
#include <Capteur.h>

class Joystick: public Capteur {

private :
	int pinX;
	int pinY;
	int valeurLuX;
	int valeurLuY;
	int etat;

public:
	//Constructeur
	Joystick(int _pinX, int _pinY);

	//Destructeur
	virtual ~Joystick();

	//Initialisation
	void init();

	//Mise à joue de la valeur du joystick
	void MajValeur();

	//Retourne l etat du joystick
	int avoirEtat();

	//Le bouton est pressé ?
	bool presse();
};

#endif
