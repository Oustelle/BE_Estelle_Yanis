#ifndef JEU_H_
#define JEU_H_

#include <Arduino.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <vector>
#include "Joueur.h"
#include "Bouton.h"
#include "Led.h"
#include "Buzzer.h"

using namespace std;

class Jeu{

private :
	int nbPartie = 0;
    int mode = 0;

public:
	//Constructeur initialisant le jeu
	Jeu();

	//Destructeur
	virtual ~Jeu();
	
    //Initialise le jeu
    void initialisation();
    
	//Mode de jeu
    void jouer();
    
    //Jouer musique
    void musique();
    
    //Reproduire musique
    void test();
    
    //Rejouer
    void rejouer();
    
    //Nouveau joueur
    void nouveau();
    
    //Trier la map classement
    void sort2(std::map<String, int>& M);
};

//Définition de notre propre exception
class modeErreur : public exception{
    public:
        const char * what() const throw()
        {
            return "Aucun mode sélectionné !\n";
        }
};

#endif
