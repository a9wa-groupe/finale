#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include <string>

using namespace std;
class Staff
{
    friend class Delegation;
    friend class Match;
    public:
        Staff ();
        Staff(string);
        void afficher();
        void modifier();
        void enregistrer_staff();
        void download_staff(string,string);
    private:
        string nom,prenom,travail,delegation;

};

#endif// STAFF_H
