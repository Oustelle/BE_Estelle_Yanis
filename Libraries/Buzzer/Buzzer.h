#ifndef BUZZER_H_
#define BUZZER_H_

#include <Arduino.h>
#include "Actionneur.h"

class Buzzer : public Actionneur{

private :
	int pin;
	int frequence;

public:
	//Constructeur
	Buzzer(int _pin);

	//Destructeur
	virtual ~Buzzer();

	//Initialise le buzzer
	void init();

	//Joue la note
	void on(int _frequence);

	//Stop
	void off();
    
    void afficherCaracteristiques();


};

#endif
