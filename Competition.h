#ifndef Competition_H
#define Competition_H
#include <iostream>
#include "Match.h"
#include "Groupe.h"
using namespace std;

class Competition
{    private:
        Groupe phasedegroupe [8];
        Match huitiemedefinale[8];
        Match quartdefinale[4];
        Match demifinale[2];
        Match finale ;
        Delegation participant[32];
        int nb_de_match_de_groupe_jouer,nb_de_match_de_huitieme_final_jouer,nb_de_match_de_quart_final_jouer,nb_de_match_de_demi_final_jouer,nb_de_match_de_final_jouer;
    public:

        Competition();
        Competition(int);
        void download_competition();
        void download_competition_par_defaut();
        void enregistrer_competition();
        void huitiemefinales();
        void quartfinales();
        void demi_finales();
        void finales();
        void resgroupe();
        void reshuitiemedefinale();
        void resquartdefinale();
        void resdemifinale();
        void resfinale();
        void toutlesres ();
        void afficherresgroupe();
        void afficher();
        void afficher_h();
        void afficher_q();
        void afficher_d();
        void afficher_f();
        void mjoueur();
        void modifier_joueur(int);
        void ajouter_joueur(int);
        void ajouter_staff(int);
        void modifier_staff(int);
        void jouer_match(int,int);
        void jouer_match_huitieme(int);
        void jouer_match_quart(int);
        void jouer_match_demi(int);
        void jouer_match_f();
        void afficher_match_poule(int);
        void afficher_info(int);
        void afficher_resMatch_poule();
        int get_nb_Match_poule()
        {return nb_de_match_de_groupe_jouer;}
        int get_nb_Match_huitiemef()
        {return nb_de_match_de_huitieme_final_jouer;}
        int get_nb_Match_quartf()
        {return nb_de_match_de_quart_final_jouer;}
        int get_nb_Match_demif()
        {return nb_de_match_de_demi_final_jouer;}
        int get_nb_Match_f()
        {return nb_de_match_de_final_jouer;}
        void classement_final();
};

#endif// Competition_H
