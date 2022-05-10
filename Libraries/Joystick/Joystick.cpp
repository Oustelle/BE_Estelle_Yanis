#include "Joystick.h"
#include "iostream"

using namespace std;

//Constructeur
Joystick:: Joystick(int _pinX, int _pinY){
	_pinX = pinX;
	_pinY = pinY;
	valeurLuX = 0;
	valeurLuY = 0;
	init();
}

//Destructeur
Joystick::~Joystick(){

}

void Joystick::init()
{
	MajValeur();
}

void Joystick::MajValeur()
{
	int valeurLuX = analogRead(pinX);
	int valeurLuY = analogRead(pinY);
}

int Joystick::avoirEtat()
{
	MajValeur();
	return etat; //Si etat = 1 (haut), etat = 2 (droite), etat = 3 (bas), etat = 4 (gauche)
}

bool Joystick::presse()
{
	return (avoirEtat() == HIGH);
}