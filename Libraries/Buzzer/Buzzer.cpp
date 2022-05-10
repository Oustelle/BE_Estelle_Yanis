#include "Buzzer.h"

//Constructeur
Buzzer :: Buzzer(int _pin){
	pin = _pin;
	init();
}

//Destructeur
Buzzer::~Buzzer(){

}

void Buzzer::init(){
	pinMode(pin, OUTPUT);
}

void Buzzer::on(int _frequence){
	tone(pin, _frequence);
}

void Buzzer::off(){
	noTone(pin);
}

void Buzzer::afficherCaracteristiques()
{
    Serial.println("*************************");
    Serial.println("Type d'actionneur : buzzer");
    Serial.print("Numero de la PIN : ");
    Serial.println(pin);
    Serial.println("*************************");
}
