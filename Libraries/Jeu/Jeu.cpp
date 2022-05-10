#include "Jeu.h"

//Attribution des pins
#define BOUTON_BLEU 13
#define BOUTON_ROUGE 4
#define BOUTON_ORANGE 14
#define LED_BLEU 12
#define LED_ROUGE 5
#define LED_ORANGE 0
#define BUZZER 15

//Définition d'un tableau de capteurs et d'actionneurs
Capteur *tabCap[3];
Actionneur *tabAct[4];

//Initialisation des capteurs et actionneurs
Bouton B_bleu (BOUTON_BLEU);
Bouton B_rouge (BOUTON_ROUGE);
Bouton B_orange (BOUTON_ORANGE);

Led L_bleu (LED_BLEU);
Led L_rouge (LED_ROUGE);
Led L_orange (LED_ORANGE);

Buzzer Buz (BUZZER);

//Initialisation des variables globales
unsigned long currentTime = millis();

int erreur = 0;
int tabValeur[25] = {0};
int partie = 1;
int newJoueur = 1;

using namespace std;

//*********************Constructeur*****************
Jeu::Jeu(){
	Serial.println("Nouvelle partie");
    nbPartie++;
    
    //Remplissage du tableau de capteurs et d'actionneurs
    tabCap[0] = new Bouton (BOUTON_BLEU);
    tabCap[1] = new Bouton (BOUTON_ROUGE);
    tabCap[2] = new Bouton (BOUTON_ORANGE);
    
    tabAct[0] = new Led (LED_BLEU);
    tabAct[1] = new Led (LED_ROUGE);
    tabAct[2] = new Led (LED_ORANGE);
    tabAct[3] = new Buzzer (BUZZER);
}

//*********************Destructeur*****************
Jeu::~Jeu(){

}

//*********************Initialisation*****************
//Menu principal du jeu
void Jeu::initialisation(){
    Serial.println("Veuillez choisir votre mode de jeu");
    Serial.println("1 -Reproduire une suite créé aléatoire par l'IA");
    Serial.println("2 -Reproduire votre suite en 1 vs 1");
    Serial.println("3 -Jeu de rapidité jusqu'à 3 joueurs");
    Serial.println("4 -Afficher les caractéristiques");
    
    while (Serial.available() == 0);
      while (Serial.available() != 0){
          char m =Serial.read();
          if ((m >= '1') && (m <= '4')){
              mode = ((mode*10)+(m-'0'));
          }
        delay(80);
      }
}

//*********************Jouer*****************
void Jeu::jouer(){

    switch (mode) {
      case 1:
      {
          int i=0;
          int score = 0;
          int newScore = 0;
          int score2 = 0;
          int num = 1;
          
          Joueur joueur1;
          Joueur joueur2;
          
          std::map<String,int> classement;
          std::map<String, int>::iterator itc;
          
          //Initialisation de random en fonction du temps
          randomSeed((unsigned int)time(0));
          
          tabValeur[0]=1;
          
          Serial.println("Mode 1 sélectionné");
          
          while (newJoueur == 1){
              
              if (score2 >= score){
                  joueur1.saisiePseudo();
                  num = 1;
              } else {
                  joueur2.saisiePseudo();
                  num = 2;
              }
              
              while(operator == (joueur1, joueur2)){
                  Serial.println("Attention le nom est identique au joueur1");
                  Serial.println("Veuillez changer de nom");
                  joueur2.saisiePseudo();
              }
              
              while (partie == 1){
                  Serial.println("Attention retenez bien la suite de couleurs");
                  delay(2000);
                  for (i=1; i<25; i++){
                      if (erreur == 0){
                          int valeur = random(1, 4);
                          tabValeur[i]=valeur;

                          if (i>2){
                              musique();
                              Serial.println("A vous de jouer ! Reproduisez la suite que vous venez d'entendre.");
                              test();
                          }
                          newScore++;
                      }
                  }
                  if (erreur == 1){
                      if (newScore > score && num == 1){
                          score = newScore;
                          joueur1.majScore(score);
                          classement[joueur1.getPseudo()]=joueur1.getScore();
                      } else if (newScore > score2 && num == 2){
                          score2 = newScore;
                          joueur2.majScore(score2);
                          classement[joueur2.getPseudo()]=joueur2.getScore();
                      }
                      newScore = 0;
                  }
                  for (i=1; i<25; i++){
                      tabValeur[i]=0;
                  }
                  partie = -1;
                  erreur = 0;
                  rejouer();
              }
              Serial.println("Merci d'avoir joué");
              Serial.println("Voici le classement :");

              sort2(classement);
              
              newJoueur = -1;
              nouveau();
          }
          Serial.println("A bientot");
        }
        break;
      case 2:
        {
            Serial.println("Mode 2 sélectionné");
            
            
        }
        break;
      case 3:
            Serial.println("Mode 3 sélectionné");
            
            
            
            
        break;
      case 4:
        {
            Serial.println("Mode 4 sélectionné");
            //Affiche les caractéristiques des capteurs et actionneurs du système
            for(int i = 0; i<3; i++)
            {
                tabCap[i]->afficherCaracteristiques();
            }
            for(int i = 0; i<4; i++)
            {
                tabAct[i]->afficherCaracteristiques();
            }
        }
        break;
      default:
            throw modeErreur(); //Problème détecté, lève une exception
        break;
    }
}

//*********************Musique*****************
void Jeu::musique(){
    int i = 0;
    tabValeur[0]=1;
    
    for(i = 0; i< 25; i++){

        if(tabValeur[i] != 0){
            if(tabValeur[i]==1){
                L_bleu.on();
                L_rouge.off();
                L_orange.off();
                while ((millis() - currentTime) < 1000){
                    Buz.on(500);
                }
                currentTime = millis();
                Buz.off();
                L_bleu.off();
                delay(500);
            } else if(tabValeur[i]==2){
                L_bleu.off();
                L_rouge.on();
                L_orange.off();
                while ((millis() - currentTime) < 1000){
                    Buz.on(900);
                }
                currentTime = millis();
                L_rouge.off();
                Buz.off();
                delay(500);
            } else if(tabValeur[i]==3){
                L_bleu.off();
                L_rouge.off();
                L_orange.on();
                while ((millis() - currentTime) < 1000){
                    Buz.on(1300);
                }
                currentTime = millis();
                Buz.off();
                L_orange.off();
                delay(500);
            }
        }
    }
}

//*********************Test*****************
void Jeu::test(){
    
    int i;
    int tabTest[25]={0};
    
    for(i=1; i<25; i++){

        if(tabValeur[i]!=0 && erreur == 0){
            
            while(tabTest[i]==0){
                yield(); //Pour éviter un reboot de l'esp car on a une boucle bloquante
                if(B_bleu.presse()){
                    tabTest[i]=1;
                }else if(B_rouge.presse()){
                    tabTest[i]=2;
                }else if(B_orange.presse()){
                    tabTest[i]=3;
                }
            }
            
            while(B_orange.presse() || B_rouge.presse() || B_bleu.presse());
            delay(80);
            
            if(tabValeur[i]!=tabTest[i]){
                erreur = 1;
            }
        }
    }
    
    if(i == 24 && erreur ==0){
        Serial.println("Bravo vous avez gagné");
    } else if (erreur == 1){
        Serial.println("Dommage vous y étiez presque !");
    }
}

//*********************Rejouer*****************
void Jeu::rejouer(){
    while (partie == -1){
        char m;
        int i=0;
        Serial.println("Voulez vous rejouer ? o/n");
        while (Serial.available() == 0);
          while (Serial.available() != 0){
              m = Serial.read();
            delay(80);
          }
        if (m=='o'){
            partie = 1;
        } else if (m=='n'){
            partie = 0;
        } else {
            Serial.println("Je n'ai pas compris");
        }
    }
}

//*********************Nouveau*****************
void Jeu::nouveau(){
    while (newJoueur == -1){
        char m;
        int i=0;
        Serial.println("Un nouveau joueur veut-il relever le défi ? o/n");
        while (Serial.available() == 0);
          while (Serial.available() != 0){
              m = Serial.read();
            delay(80);
          }
        if (m=='o'){
            newJoueur = 1;
            partie = 1;
        } else if (m=='n'){
            newJoueur = 0;
        } else {
            Serial.println("Je n'ai pas compris");
        }
    }
}

//*********************CMP*****************
//Fonction de comparaison des scores de la map
bool cmp(pair<String, int>& a, pair<String, int>& b)
{
    return a.second > b.second;
}

//*********************sort2*****************
void Jeu::sort2(std::map<String, int>& M)
{
  
    //Déclare un vecteur de pairs
    vector<pair<String, int> > A;
  
    // Copie de la paire clé-valeur de la map à un vecteur de paires
    for (auto& it : M) {
        A.push_back(it);
    }
  
    //Trier en utilisant la fonction de comparaison
    sort(A.begin(), A.end(), cmp);
  
    //Affiche les valeurs triées
    for (auto& it : A) {
      Serial.print(it.first);
      Serial.print("   ");
      Serial.println(it.second);
    }
}
