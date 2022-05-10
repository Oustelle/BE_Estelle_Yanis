#ifndef JOUEUR_H_
#define JOUEUR_H_

#include <Arduino.h>
#include <iostream>
#include <string>

using namespace std;

class Joueur{

private :
	String pseudo;
	int score;
	int nbJoueur = 0;

public:
    //Constructeur initialisant le joueur
    Joueur();

	//Destructeur
	virtual ~Joueur();
	
	//Permet au joueur de rentrer son pseudo
	void saisiePseudo();
    
    //Met à jour le score
    void majScore(int _score);
    
    //Retourne le score
    int getScore();

	//Affiche le pseudo du joueur en cours
	void afficherPseudo();
    
    //Retourne le pseudo du joueur en cours
    String getPseudo();
    
    //Redéfinition opérateur ==
    friend bool operator == (const Joueur & Joueur1, const Joueur & Joueur2);

};

#endif
