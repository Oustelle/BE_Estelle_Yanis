#ifndef LED_H_
#define LED_H_

#include <Arduino.h>
#include "Actionneur.h"

class Led: public Actionneur{

private :
	int pin;

public:
	//Constructeur
	Led(int _pin);

	//Destructeur
	virtual ~Led();

	//Initialise la led
	void init();

	//Allume la led
	void on();

	//Eteins la led
	void off();
    
    void afficherCaracteristiques();

};

#endif
