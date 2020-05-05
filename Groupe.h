#ifndef GROUPE_H
#define GROUPE_H
#include <iostream>
#include <vector>
#include "Match.h"
#include "Delegation.h"
using namespace std;

class Groupe
{ friend class Competition;
  friend class Match;
  friend class Delegation;
    public:
        Groupe();
        Groupe(Delegation,Delegation,Delegation,Delegation,int);
        void classer() ;
        void afficherleclassment();
        void enregistrer_groupe();
        void download_groupe(Delegation,Delegation,Delegation,Delegation);
        void afficher_matchs();
        void afficher_resMatch();

    private:
        Delegation classement[4];
        Match matchs[6];
        int Cla; // le classement du groupe dans les autres groupes
};

#endif// GROUPE_H
