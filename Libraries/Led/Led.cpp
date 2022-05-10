#include "Led.h"

//Constructeur
Led :: Led(int _pin){
	pin = _pin;
	init();
}

//Destructeur
Led::~Led(){

}

void Led::init(){
	pinMode(pin, OUTPUT);
	off();
}

void Led::on(){
	digitalWrite(pin, HIGH);
}

void Led::off(){
	digitalWrite(pin, LOW);
}

void Led::afficherCaracteristiques()
{
    Serial.println("*************************");
    Serial.println("Type d'actionneur : Led");
    Serial.print("Numero de la PIN : ");
    Serial.println(pin);
    Serial.println("*************************");
}
