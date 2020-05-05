#include "Delegation.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include "Staff.h"
#include <string>
#include "Joueur.h"
using namespace std;

Joueur Delegation::meilleur_joueur()
{  Joueur max;
   max=joueurlist[0];
   for (unsigned int i=1;i<joueurlist.size();i++)
   {
       if(joueurlist[i-1].note_total()<joueurlist[i].note_total())
       {
           max=joueurlist[i-1];
       }
   }
   return max;
}
void Delegation::afficher_info()
{
     cout<<"*Delegation "<<nom<<" :"<<endl;
     cout<<"groupe : "<<grp<<" / niveau : "<<niveau;
     cout<<" / but total marque: "<<nb_de_but<<endl;
     cout<<"nombre carton pris au cours des matchs : "<<"jaune " <<nb_de_carton_jaune<<" /rouge "<<nb_de_carton_rouge<<endl;
     cout<<"voici les joueur de la delegation "<<nom <<":"<<endl;
     for (unsigned int i=0;i<joueurlist.size();i++)
    {
        cout<<i+1<<" "<<endl;
        joueurlist[i].afficher_info();
    }
    cout<<"voici les staff de la delegation "<<nom <<":"<<endl;
     for (unsigned int i=0;i<stafflist.size();i++)
     {
        cout<<i+1<<" "<<endl;
        stafflist[i].afficher();
     }
}
Delegation::Delegation()
{

}
Delegation::Delegation(int tab[],int taille) : points(0),nb_de_but(0),nb_de_carton_rouge(0),nb_de_carton_jaune(0)
{
    cout<<"donner le nom de la Nation :"<<endl;
    cin>>nom;
    int x;
    cout<<"donner le nbre de joueur"<<endl;
    cin>>x;
    for ( int i=0 ; i<x;i++)
    {
        Joueur z=Joueur(nom);
        joueurlist.push_back(z);
    }
    cout<<"donner le nbre de staff"<<endl;
    cin>>x;
    for ( int i=0 ; i<x;i++)
    {
        Staff z=Staff(nom);
        stafflist.push_back(z);
    }
    do
    {
        cout<<"donner le niveau de cette delegation en respectant le nombre maximal de 8 delegations par niveau"<<endl;
        cout<<"le niveau 1 on a :"<<tab[0]<<" nation(s) deja dans ce niveau"<<endl;
        cout<<"le niveau 2 on a :"<<tab[1]<<" nation(s) deja dans ce niveau"<<endl;
        cout<<"le niveau 3 on a :"<<tab[2]<<" nation(s) deja dans ce niveau"<<endl;
        cout<<"le niveau 4 on a :"<<tab[3]<<" nation(s) deja dans ce niveau"<<endl;
        cin>>niveau;
    }while( tab[niveau-1]+1>8);
    tab[niveau-1]+=1;

}
int Delegation::getniveau()
{
    return niveau;
}




void Delegation::ajouter_joueur()
{
    Joueur z=Joueur(nom);
    joueurlist.push_back(z);
    z.enregistrer_joueur();
    this->enregistrer_delegation();
}

void Delegation::ajouter_staff()
{
    Staff s=Staff(nom);
    stafflist.push_back(s);
    s.enregistrer_staff();
    this->enregistrer_delegation();


}

void Delegation::afficher_noms_des_joueurs()
{
    for  (int i=0;i<joueurlist.size();i++)
    {
        cout<<i+1<<" "<<joueurlist[i].nom<<endl;
    }
}

void Delegation::afficher_noms_des_staff()
{
    for (int i=0;i<stafflist.size();i++)
    {
        cout<<i+1<<" "<<stafflist[i].nom<<endl;
    }
}
void Delegation::modifier_joueur()
{
    Delegation::afficher_noms_des_joueurs();
    cout<<"donner le numero du joueur a modifier"<<endl;
    int x;
    cin>>x;
    joueurlist[x-1].Joueur::modifier();
    joueurlist[x-1].Joueur::enregistrer_joueur();
    this->enregistrer_delegation();


}
void Delegation::modifier_staff()
{
    Delegation::afficher_noms_des_staff();
    cout<<"donner le numero du staff a modifier"<<endl;
    int x;
    cin>>x;
    stafflist[x-1].Staff::modifier();
    stafflist[x-1].enregistrer_staff();
     this->enregistrer_delegation();

}
void Delegation::supprimer_joueur()
{
    Delegation::afficher_noms_des_joueurs();
    cout<<"donner le numero du joueur a supprimer"<<endl;
    int x;
    cin>>x;
    joueurlist.erase(joueurlist.begin() + (x-1));
     this->enregistrer_delegation();


}

void Delegation::supprimer_staff()
{
    Delegation::afficher_noms_des_staff();
    cout<<"donner le numero du staff a supprimer"<<endl;
    int x;
    cin>>x;
    stafflist.erase(stafflist.begin() + (x-1));
     this->enregistrer_delegation();


}


string Delegation::getnom()
{
    return nom;
}

void Delegation::enregistrer_delegation()
{
    char nomfich[50];
    strcpy(nomfich,nom.c_str());
    ofstream sortie(nomfich, ios::trunc);
    sortie << nom << endl;
    sortie << points << endl;
    sortie << nb_de_but << endl;
    sortie << nb_de_carton_jaune << endl;
    sortie << nb_de_carton_rouge << endl;
    sortie << niveau<<endl;
    sortie << grp<<endl;
    sortie << stafflist.size() << endl;
    sortie << joueurlist.size() << endl;
    for (int i=0;i<stafflist.size();i++)
        {
        sortie << stafflist[i].nom <<endl;
        stafflist[i].enregistrer_staff();
        }

    for (int i=0;i<joueurlist.size();i++)
        {
        sortie << joueurlist[i].nom <<endl;
        joueurlist[i].enregistrer_joueur();
        }

}



void Delegation::download_delegation(string d)
{
     int nb_staff;
    int nb_joueur;
    Joueur j;
    Staff s;
    nom=d;
    string variable;
    char nomfich[50];
    strcpy(nomfich,d.c_str());
    ifstream entree (nomfich, ios::in);
    entree >> nom ;

    entree >> points ;

    entree >> nb_de_but ;

    entree >> nb_de_carton_jaune ;

    entree >> nb_de_carton_rouge ;

    entree >> niveau;

    entree >> grp ;

    entree >> nb_staff;
    entree >> nb_joueur;
    for (int i=0;i<nb_staff;i++)
        {
        entree >> variable ;
        s.download_staff(variable,d);

        stafflist.push_back(s);

        }

    for (int i=0;i<nb_joueur;i++)
        {
        entree >> variable ;
        j.download_joueur(variable,d);

        joueurlist.push_back(j);

        }

}

void Delegation::download_delegation_par_defaut(string d)
{
    int nb_staff;
    int nb_joueur;
    Joueur j;
    Staff s;

    nom=d+"par defaut";
    string variable;
    char nomfich[50];
    strcpy(nomfich,d.c_str());
    ifstream entree (nomfich, ios::in);
    entree >> nom ;
    entree >> points ;
    entree >> nb_de_but ;
    entree >> nb_de_carton_jaune ;
    entree >> nb_de_carton_rouge ;
    entree >> niveau;
    entree >> grp;
    entree >> nb_staff;
    entree >> nb_joueur;
    for (int i=0;i<nb_staff;i++)
        {
        entree >> variable ;
        s.download_staff(variable,nom);

        stafflist.push_back(s);

        }

    for (int i=0;i<nb_joueur;i++)
        {
        entree >> variable ;
        j.download_joueur(variable,nom);

        joueurlist.push_back(j);

        }

}

int Delegation::get_groupe()
{
    return grp;
}
