#include "Capteur.h"

using namespace std;

//Constructeur
Capteur :: Capteur(){
	nbCapteur ++;
}

//Destructeur
Capteur::~Capteur(){

}

void Capteur::afficherNbCapteur()
{
	cout << endl;
	cout << "**************************" << endl;
	cout << "Nombre de Capteurs crees : \t" << nbCapteur << endl;
	cout << "**************************" << endl;
	cout << endl;
}