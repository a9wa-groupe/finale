#include "Match.h"
#include "Delegation.h"
#include <string.h>
#include <cstring>
#include <fstream>
using namespace std;
Match::Match()
{

}

Match::Match(Delegation d1,Delegation d2) : equipe1(d1),equipe2(d2)
{
    int i;
    for (i = 0; i < 7; i++)
        information[i] = 0;
}
void Match::jouer()
{
 if(information[6]==0)
    {int b1,b2,u;
    cout<<endl;
    cout<<"*Le Match entre "<<equipe1.nom<<" - "<<equipe2.nom<<" commence :"<<endl;
    cout<<"mettez combien de but a marque l'quipe1"<<" "<<equipe1.nom<<" : ";
    cin>>b1;
    information[0]=b1;
    if ( b1 > 0 )
        {equipe1.nb_de_but+=b1;
        equipe1.enregistrer_delegation();
        do{
            equipe1.afficher_noms_des_joueurs();
            cout<<"numero du joueur qui a marquer"<<endl;
            cin>>u;
            equipe1.joueurlist[u-1].ajouter_but(1);
            equipe1.joueurlist[u-1].enregistrer_joueur();
            b1--;
        }while(b1>0);}
    cout<<"mettez combien de but a marque l'quipe2"<<" "<<equipe2.nom<<" : ";
    cin>>b2;
    information[3]=b2;
    if ( b2 > 0 )
        {equipe2.nb_de_but+=b2;
        equipe2.enregistrer_delegation();
        do{
            equipe2.afficher_noms_des_joueurs();
            cout<<"numero du joueur qui a marquer"<<endl;
            cin>>u;
            equipe2.joueurlist[u-1].ajouter_but(1);
            equipe2.joueurlist[u-1].enregistrer_joueur();
            b2--;
        }while(b2>0);}
    if(information[0]>information[3])
        {equipe1.ajouter_points(3);
         equipe1.enregistrer_delegation();
        }
    if ( information[0]<information[3])
        {equipe2.ajouter_points(3);
        equipe2.enregistrer_delegation();}
    if(information[0]==information[3])
    {
        equipe2.ajouter_points(1);
        equipe2.enregistrer_delegation();

        equipe1.ajouter_points(1);
        equipe1.enregistrer_delegation();
    }
    int x,j;
    cout<<"donner le nombre de carton jaune qu'il y a eu dans ce match pour la 1ere equipe  "<<equipe1.nom<<endl;
    cin>>x;
    information[1]=x;
    equipe1.nb_de_carton_jaune+=x;
    equipe1.enregistrer_delegation();
    for (int i=0;i<x;i++)
    {
        equipe1.afficher_noms_des_joueurs();
        cout<<"donner le numero du "<<i+1<<"ieme joueur qui a pris une carton jaune "<<endl;
        cin>>j;
        equipe1.joueurlist[j-1].ajouter_carton_jaune(1);
        equipe1.joueurlist[j-1].enregistrer_joueur();

    }
    cout<<"donner le nombre de carton jaune qu'il y a eu dans ce match pour la 2ieme equipe "<<equipe2.nom<<endl;
    cin>>x;
    information[4]=x;
    equipe2.nb_de_carton_jaune+=x;
    equipe2.enregistrer_delegation();
    for (int i=0;i<x;i++)
    {
        equipe2.afficher_noms_des_joueurs();
        cout<<"donner le numero du "<<i+1<<"ieme joueur qui a pris une carton jaune"<<endl;
        cin>>j;
        equipe2.joueurlist[j-1].ajouter_carton_jaune(1);
        equipe2.joueurlist[j-1].enregistrer_joueur();


    }
    cout<<"donner le nombre de carton rouge qu'il y a eu dans ce match pour la 1 iere equipe "<<equipe1.nom<<endl;
    cin>>x;
    information[2]=x;
    equipe1.nb_de_carton_rouge+=x;
    equipe1.enregistrer_delegation();
    for (int i=0;i<x;i++)
    {
        equipe1.afficher_noms_des_joueurs();
        cout<<"donner le numero du "<<i+1<<"ieme joueur qui a pris une carton rouge"<<endl;
        cin>>j;
        equipe1.joueurlist[j-1].ajouter_carton_rouge(1);
        equipe1.joueurlist[j-1].enregistrer_joueur();
    }
    cout<<"donner le nombre de carton rouge qu'il y a eu dans ce match pour la 2ieme equipe "<<equipe2.nom<<endl;
    cin>>x;
    information[5]=x;
    equipe2.nb_de_carton_rouge+=x;
    equipe2.enregistrer_delegation();
    for (int i=0;i<x;i++)
    {
        equipe2.afficher_noms_des_joueurs();
        cout<<"donner le numero du "<<i+1<<"ieme joueur qui a pris une carton rouge"<<endl;
        cin>>j;
        equipe2.joueurlist[j-1].ajouter_carton_rouge(1);
        equipe2.joueurlist[j-1].enregistrer_joueur();
    }
    cout<<"le nombre de joueurs de l'equipe "<<equipe1.nom<<" : "<<equipe1.joueurlist.size()<<endl;
    cout<<"combien de joueurs ont jouer pour la premiere equipe "<<equipe1.nom<<" dans ce match "<<endl;
    cin>>x;
    int n,y,h=0; // une variable pour la note est une variable pour verifier si la note est entre 0 et 10 et une pour le numero du joueuer

    for (int i=0;i<x;i++)
    {
        cout<<"choisissez un joueur pour lui donner une note pour ce match ( "<<i+1<<"/"<<x<<")"<<endl;
        equipe1.afficher_noms_des_joueurs();
        cin>>n;
        cout<<"Ca note :"<<endl;

        do
        {
            cin>>y;
            if ( (y<10)&&(y>0) )
                {
                equipe1.joueurlist[n-1].ajouter_note(y);
                equipe1.joueurlist[n-1].enregistrer_joueur();
                h=1;
                }
            else
                cout<<"redonner une note raisonnable entre 0 et 10 "<<endl;


        }while(h==0);
    cout<<"le nombre de joueurs de l'equipe "<<equipe2.nom<<" : "<<equipe2.joueurlist.size()<<endl;
    cout<<"combien de joueurs ont jouer pour la deuxieme equipe "<<equipe2.nom<<" dans ce match "<<endl;
    cin>>x;
    h=0;
    for (int i=0;i<x;i++)
    {
        cout<<"choisissez un joueur pour lui donner une note pour ce match ( "<<i+1<<"/"<<x<<")"<<endl;
        equipe2.afficher_noms_des_joueurs();
        cin>>n;
        cout<<"Ca note :"<<endl;

        do
        {
            cin>>y;
            if ( (y<10)&&(y>0) )
                {
                equipe2.joueurlist[n-1].ajouter_note(y);
                equipe2.joueurlist[n-1].enregistrer_joueur();
                h=1;
                }
            else
                cout<<"redonner une note raisonnable entre 0 et 10 "<<endl;


        }while(h==0);
    }
   }
   information[6]+=1;
   cout<<"*Fin du Match*"<<endl;
  }
  else
    cout<<"le match a ete deja jouer "<<endl;
}
void Match::jouer_phase2()
{ if(information[6]==0)
    {int b1,b2,u;
    cout<<endl;
    cout<<"*Le Match entre "<<equipe1.nom<<" - "<<equipe2.nom<<" commence :"<<endl;
    cout<<"mettez combien de but a marque l'quipe1"<<" "<<equipe1.nom<<" : ";
    cin>>b1;
    information[0]=b1;
    if ( b1 > 0 )
        {equipe1.nb_de_but+=b1;
        equipe1.enregistrer_delegation();
        do{
            equipe1.afficher_noms_des_joueurs();
            cout<<"numero du joueur qui a marquer"<<endl;
            cin>>u;
            equipe1.joueurlist[u-1].ajouter_but(1);
            equipe1.joueurlist[u-1].enregistrer_joueur();
            b1--;
        }while(b1>0);}
    cout<<"mettez combien de but a marque l'quipe2"<<" "<<equipe2.nom<<" : ";
    cin>>b2;
    information[3]=b2;
    if ( b2 > 0 )
        {equipe2.nb_de_but+=b2;
        equipe2.enregistrer_delegation();
        do{
            equipe2.afficher_noms_des_joueurs();
            cout<<"numero du joueur qui a marquer"<<endl;
            cin>>u;
            equipe2.joueurlist[u-1].ajouter_but(1);
            equipe2.joueurlist[u-1].enregistrer_joueur();
            b2--;
        }while(b2>0);}

    int x,j;
    cout<<"donner le nombre de carton jaune qu'il y a eu dans ce match pour la 1ere equipe  "<<equipe1.nom<<endl;
    cin>>x;
    information[1]=x;
    equipe1.nb_de_carton_jaune+=x;
    equipe1.enregistrer_delegation();
    for (int i=0;i<x;i++)
    {
        equipe1.afficher_noms_des_joueurs();
        cout<<"donner le numero du "<<i+1<<"ieme joueur qui a pris une carton jaune "<<endl;
        cin>>j;
        equipe1.joueurlist[j-1].ajouter_carton_jaune(1);
        equipe1.joueurlist[j-1].enregistrer_joueur();

    }
    cout<<"donner le nombre de carton jaune qu'il y a eu dans ce match pour la 2ieme equipe "<<equipe2.nom<<endl;
    cin>>x;
    information[4]=x;
    equipe2.nb_de_carton_jaune+=x;
    equipe2.enregistrer_delegation();
    for (int i=0;i<x;i++)
    {
        equipe2.afficher_noms_des_joueurs();
        cout<<"donner le numero du "<<i+1<<"ieme joueur qui a pris une carton jaune"<<endl;
        cin>>j;
        equipe2.joueurlist[j-1].ajouter_carton_jaune(1);
        equipe2.joueurlist[j-1].enregistrer_joueur();


    }
    cout<<"donner le nombre de carton rouge qu'il y a eu dans ce match pour la 1 iere equipe "<<equipe1.nom<<endl;
    cin>>x;
    information[2]=x;
    equipe1.nb_de_carton_rouge+=x;
    equipe1.enregistrer_delegation();
    for (int i=0;i<x;i++)
    {
        equipe1.afficher_noms_des_joueurs();
        cout<<"donner le numero du "<<i+1<<"ieme joueur qui a pris une carton rouge"<<endl;
        cin>>j;
        equipe1.joueurlist[j-1].ajouter_carton_rouge(1);
        equipe1.joueurlist[j-1].enregistrer_joueur();
    }
    cout<<"donner le nombre de carton rouge qu'il y a eu dans ce match pour la 2ieme equipe "<<equipe2.nom<<endl;
    cin>>x;
    information[5]=x;
    equipe2.nb_de_carton_rouge+=x;
    equipe2.enregistrer_delegation();
    for (int i=0;i<x;i++)
    {
        equipe2.afficher_noms_des_joueurs();
        cout<<"donner le numero du "<<i+1<<"ieme joueur qui a pris une carton rouge"<<endl;
        cin>>j;
        equipe2.joueurlist[j-1].ajouter_carton_rouge(1);
        equipe2.joueurlist[j-1].enregistrer_joueur();
    }
    cout<<"le nombre de joueurs de l'equipe "<<equipe1.nom<<" : "<<equipe1.joueurlist.size()<<endl;
    cout<<"combien de joueurs ont jouer pour la premiere equipe "<<equipe1.nom<<" dans ce match "<<endl;
    cin>>x;
    int n,y,h=0; // une variable pour la note est une variable pour verifier si la note est entre 0 et 10 et une pour le numero du joueuer

    for (int i=0;i<x;i++)
    {
        cout<<"choisissez un joueur pour lui donner une note pour ce match ( "<<i+1<<"/"<<x<<")"<<endl;
        equipe1.afficher_noms_des_joueurs();
        cin>>n;
        cout<<"Ca note :"<<endl;

        do
        {
            cin>>y;
            if ( (y<10)&&(y>0) )
                {
                equipe1.joueurlist[n-1].ajouter_note(y);
                equipe1.joueurlist[n-1].enregistrer_joueur();
                h=1;
                }
            else
                cout<<"redonner une note raisonnable entre 0 et 10 "<<endl;


        }while(h==0);
    cout<<"le nombre de joueurs de l'equipe "<<equipe2.nom<<" : "<<equipe2.joueurlist.size()<<endl;
    cout<<"combien de joueurs ont jouer pour la deuxieme equipe "<<equipe2.nom<<" dans ce match "<<endl;
    cin>>x;
    h=0;
    for (int i=0;i<x;i++)
    {
        cout<<"choisissez un joueur pour lui donner une note pour ce match ( "<<i+1<<"/"<<x<<")"<<endl;
        equipe2.afficher_noms_des_joueurs();
        cin>>n;
        cout<<"Ca note :"<<endl;

        do
        {
            cin>>y;
            if ( (y<10)&&(y>0) )
                {
                equipe2.joueurlist[n-1].ajouter_note(y);
                equipe2.joueurlist[n-1].enregistrer_joueur();
                h=1;
                }
            else
                cout<<"redonner une note raisonnable entre 0 et 10 "<<endl;


        }while(h==0);
    }
   }
   information[6]+=1;
   cout<<"*Fin du Match*"<<endl;
  }
  else
    cout<<"le match a ete deja jouer "<<endl;
}
void Match::afficher_information()
{
    cout<<"le score de ce match est "<<" "<<information[0]<<"-"<<information[3]<<endl;
    cout<<"la premiere equipe  "<<equipe1.nom<<" a recu : carton jaune "<<information[1]<<"/ carton rouge  "<<information[2]<<endl;
    cout<<"la deuxieme equipe  "<<equipe2.nom<<" a recu : carton jaune "<<information[4]<<"/ carton rouge  "<<information[5]<<endl;
}
Delegation Match::resultat()
{
    if (information[0]>information[3])
        return equipe1;
    else
        return equipe2;
}
Delegation Match::perdant()
{
     if (information[0]<information[3])
        return equipe1;
    else
        return equipe2;
}

void Match::enregistrer_matchh()
{
    char nomfich[20];
    string s;
    s= equipe1.getnom() + equipe2.getnom()+"1";
    strcpy(nomfich,s.c_str());
    ofstream sortie(nomfich, ios::trunc) ;
    for ( int i=0;i<7 ;i++)
        sortie << information[i]<<endl;
    sortie.close();

}
void Match::enregistrer_matchq()
{
    char nomfich[20];
    string s;
    s= equipe1.getnom() + equipe2.getnom()+"2";
    strcpy(nomfich,s.c_str());
    ofstream sortie(nomfich, ios::trunc) ;
    for ( int i=0;i<7 ;i++)
        sortie << information[i]<<endl;
    sortie.close();

}
void Match::enregistrer_matchd()
{
    char nomfich[20];
    string s;
    s= equipe1.getnom() + equipe2.getnom()+"3";
    strcpy(nomfich,s.c_str());
    ofstream sortie(nomfich, ios::trunc) ;
    for ( int i=0;i<7 ;i++)
        sortie << information[i]<<endl;
    sortie.close();

}
void Match::enregistrer_matchf()
{
    char nomfich[20];
    string s;
    s= equipe1.getnom() + equipe2.getnom()+"4";
    strcpy(nomfich,s.c_str());
    ofstream sortie(nomfich, ios::trunc) ;
    for ( int i=0;i<7 ;i++)
        sortie << information[i]<<endl;
    sortie.close();

}

void Match::enregistrer_match_de_groupe()
{
    char nomfich[20];
    string s;
    s= equipe1.getnom() + equipe2.getnom()+"match de groupe";
    strcpy(nomfich,s.c_str());
    ofstream sortie(nomfich, ios::trunc) ;
    for ( int i=0;i<7 ;i++)
        sortie << information[i]<<endl;
    sortie.close();

}
void Match::download_match_de_groupe()
{
    int i;
    char nomfich[20];
    string s;
    s = equipe1.getnom() + equipe2.getnom()+"match de groupe";
    strcpy(nomfich,s.c_str());
    ifstream entree (nomfich, ios::in);
    for ( int j=0;j<7;j++)
    {
        entree >> i ;
        information[j]=i;
    }
    entree.close();
}
void Match::download_matchh()
{
    int i;
    char nomfich[20];
    string s;
    s = equipe1.getnom() + equipe2.getnom()+"1";
    strcpy(nomfich,s.c_str());
    ifstream entree (nomfich, ios::in);
    for ( int j=0;j<7;j++)
    {
        entree >> i ;
        information[j]=i;
    }
    entree.close();
}
void Match::download_matchq()
{
    int i;
    char nomfich[20];
    string s;
    s = equipe1.getnom() + equipe2.getnom()+"2";
    strcpy(nomfich,s.c_str());
    ifstream entree (nomfich, ios::in);
    for ( int j=0;j<7;j++)
    {
        entree >> i ;
        information[j]=i;
    }
    entree.close();
}
void Match::download_matchd()
{
    int i;
    char nomfich[20];
    string s;
    s = equipe1.getnom() + equipe2.getnom()+"3";
    strcpy(nomfich,s.c_str());
    ifstream entree (nomfich, ios::in);
    for ( int j=0;j<7;j++)
    {
        entree >> i ;
        information[j]=i;
    }
    entree.close();
}
void Match::download_matchf()
{
    int i;
    char nomfich[20];
    string s;
    s = equipe1.getnom() + equipe2.getnom()+"4";
    strcpy(nomfich,s.c_str());
    ifstream entree (nomfich, ios::in);
    for ( int j=0;j<7;j++)
    {
        entree >> i ;
        information[j]=i;
    }
    entree.close();
}
