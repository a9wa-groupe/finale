#include "Staff.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

Staff::Staff()
{

}

void Staff::afficher()

{
    cout<<"nom : "<<nom;
    cout<<"/prenom : "<<prenom;
    cout<<"/travail : "<<travail;
	cout<<"/nationalite : "<<delegation;
}

void Staff::modifier()
{
    cout<<"pour modifier le nom taper 1"<<endl;
	cout<<"pour modifier le prenom taper 2"<<endl;
	cout<<"pour modifier le travail taper 3"<<endl;
	cout<<"pour tout changer taper 4 "<<endl;
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

			cout<<"quel est le nouveau travail"<<endl;
			cin>>y;
			travail = y;
			break;
		case 4:

			cout<<"quel est le nouveau nom"<<endl;
			cin>>y;
			nom = y;
			cout<<"quel est le nouveau prenom"<<endl;
			cin>>y;
			prenom = y;
			cout<<"quel est le nouveau travail"<<endl;
			cin>>y;
			travail = y;
			break;

		default:
			cout<<"erreur";
	}
}
Staff::Staff(string d): delegation(d)
{
    string y;
	cout<<"quel est le nom du staff"<<endl;
	cin>>y;
	nom = y;

	cout<<"quel est le prenom staff"<<endl;
	cin>>y;
	prenom = y;

	cout<<"quel est le travail"<<endl;
	cin>>y;
	travail = y;
}

void Staff::enregistrer_staff()
{
    char nomfich[20];
    string s;
    s = nom + delegation;
    strcpy(nomfich,s.c_str());
    ofstream sortie(nomfich, ios::out) ;
    sortie << nom <<endl;
    sortie << prenom <<endl;
    sortie <<travail<<endl;
    sortie << delegation <<endl;
    sortie.close();
}

void Staff::download_staff(string nom_staff,string D)
{

    char nomfich[20];
    string s;
    s = nom_staff + D;
    strcpy(nomfich,s.c_str());
    ifstream entree (nomfich, ios::in);
    entree >> nom ;
    entree >> prenom ;
    entree >> travail ;
    entree >> delegation ;
    entree.close();


}
