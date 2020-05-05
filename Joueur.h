#ifndef JOUEUR_H
#define JOUEUR_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;


class Joueur
{
   friend class Delegation;
   friend class Match;
   friend class Competition;
   friend class Groupe;
    private:
        string nom,prenom,dele;
        int Nb_carton_rouge,Nb_carton_jaune,Nb_but;
        vector<float> Notes; // premiere case pour la note moyenne et les autres pour les notes en details

    public:
        Joueur();
        Joueur(string);
        int note_total();
        void afficher_note_total();
        void afficher_notes();
        void afficher_info();
        int get_carton_rouge();
        int get_carton_jaune();
        int get_but();
        float get_note_total();
        void ajouter_carton_rouge(int);
        void ajouter_carton_jaune(int);
        void ajouter_but(int);
        void ajouter_note(int);
        void modifier();
        void enregistrer_joueur();
        void download_joueur(string,string);



};

#endif // JOUEUR_H

