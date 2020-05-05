#include "Joueur.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

Joueur::Joueur()
{

}



void Joueur::modifier()
{
    cout<<"pour modifier le nom taper 1"<<endl;
	cout<<"pour modifier le prenom taper 2"<<endl;
	cout<<"pour tout changer taper 3 "<<endl;
	int x;
	cin>>x;

	string y;
	switch(x)
	{
		case 1:
			cout<<"quel est le nouveau nom"<<endl;
			cin>>y;
			nom = y;
			break;
		case 2:

			cout<<"quel est le nouveau prenom"<<endl;
			cin>>y;
			prenom = y;
			break;
		case 3:

			cout<<"quel est le nouveau nom"<<endl;
			cin>>y;
			nom = y;
			cout<<"quel est le nouveau prenom"<<endl;
			cin>>y;
			prenom = y;
			break;

		default:
			cout<<"erreur";
			break;
	}
}
Joueur::Joueur(string d) : Nb_carton_rouge(0),Nb_carton_jaune(0),Nb_but(0),dele(d)
{

    string y,x;
    cout<<"donner le nom du joueur"<<endl;
    cin>> y;
     nom=y;
    cout<<"donner le prenom du joueur"<<endl;
    cin>> x;
     prenom=x;
    Notes.push_back(0);

}
int Joueur::note_total()
{
    return Notes[0];
}
void Joueur::afficher_note_total()
{
    cout<< Notes[0];
}

void Joueur::afficher_notes()
{
    if (Notes.size()>1)
    {
        for (int i=1; i<(int)Notes.size() ; i++)
        {
            cout<<"ca note du"<<i<<"ieme match est "<< Notes[i]<<endl;
        }
    }
    else
        cout<<" ce joueur n'a jouer aucun match"<<endl;
    }

void Joueur::afficher_info()
{
    cout<<"nom : "<<nom;
    cout<<"/prenom : "<<prenom;
    cout<<"/nationalite : "<<dele;
    cout<<"/nombre de buts marque: "<<Nb_but;
    cout<<"/nombre de carton jaunes : "<<Nb_carton_jaune;
    cout<<"/nombre de carton rouges : "<<Nb_carton_rouge;
    cout<<"/ca note moyenne : "<< Notes[0]<<endl;

}

int Joueur::get_carton_rouge()
{
    return Nb_carton_rouge;
}

int Joueur::get_carton_jaune()
{
    return Nb_carton_jaune;
}
int Joueur::get_but()
{
    return Nb_but;
}
void Joueur::ajouter_carton_rouge(int i)
{
    Nb_carton_rouge+=i;
}

void Joueur::ajouter_carton_jaune(int i)
{
    Nb_carton_jaune+=i;
}

void Joueur::ajouter_but(int i)
{
    Nb_but+=i;
}

void Joueur::ajouter_note(int i)
{
    Notes.push_back(i);
    float s = 0.0;
    for ( int i=1;i<(int)Notes.size();i++)
    {
        s+= Notes[i];

    }
    Notes[0] = (float) s / (Notes.size() - 1 );
}


float Joueur::get_note_total()
{
    return Notes[0];
}

void Joueur::enregistrer_joueur()
{
    char nomfich[20];
    string s;
    s = nom + dele;
    strcpy(nomfich,s.c_str());
    ofstream sortie(nomfich, ios::trunc) ;
    sortie << nom <<endl;
    sortie << prenom <<endl;
    sortie <<Nb_carton_rouge<<endl;
    sortie << Nb_carton_jaune <<endl;
    sortie << Nb_but <<endl;
    for ( int i=0;i<Notes.size();i++)
        sortie << Notes[i]<<endl;
    sortie.close();
}

void Joueur::download_joueur(string nom_joueur,string D)
{
    dele=D;
    int i;
    char nomfich[20];
    string s;
    s = nom_joueur + D;
    strcpy(nomfich,s.c_str());
    ifstream entree (nomfich, ios::in);
    entree >> nom ;
    entree >> prenom ;
    entree >> Nb_carton_rouge ;
    entree >> Nb_carton_jaune ;
    entree >> Nb_but ;

    while ( entree >> i)
    {
        Notes.push_back(i);
    }

    entree.close();



}
