#include "Groupe.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <fstream>
#include <string>
#include "Match.h"
using namespace std;

void Groupe::afficher_resMatch()
{
     for(int i=0;i<6;i++)
       {
        cout<<matchs[i].equipe1.nom+" - "+matchs[i].equipe2.nom<<endl;
        if (matchs[i].information[6]!=0)
               matchs[i].afficher_information();
        else
               cout<<"le match n'est pas encore jouer"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
       }
}
Groupe::Groupe()
{

}
void Groupe::afficher_matchs()
{
    for(int i=0;i<6;i++)
       {cout<<"*"<<i+1<<")"<<matchs[i].equipe1.nom+" - "+matchs[i].equipe2.nom<<endl;}
}



Groupe::Groupe(Delegation d1,Delegation d2,Delegation d3,Delegation d4,int i) : Cla(i)
{
    classement[0]=d1;
    classement[1]=d2;
    classement[2]=d3;
    classement[3]=d4;
    int k=0;
    for ( int i=0;i<4;i++)
        for ( int j=i+1;j<4;j++)
           {
               Match m(classement[i],classement[j]);
               matchs[k]=m;
               k++;


           }



}


void Groupe::classer ()
 {

    Delegation d ;

    for(int i=0;i<4;i++)
    {
        for(int j=i;j<4;j++)
        {
            if(classement[j].points>classement[i].points)
            {
                d=classement[i];
                classement[i]=classement[j];
                classement[j]=d;

                }
        }
        }
}
void Groupe :: afficherleclassment ()
{
    for (int i=0;i<4;i++)
        cout<<i+1<<" equipe : " <<classement[i].getnom()<<" point= "<<classement[i].points<<endl;
 }

void Groupe::enregistrer_groupe()
{
    char nomfich[100];
    string s;
    for ( int i=0;i<4;i++)
        s+=classement[i].getnom();

    strcpy(nomfich,s.c_str());
    ofstream sortie(nomfich, ios::trunc) ;
    for ( int i=0;i<4 ;i++)
        sortie << classement[i].getnom()<<endl;
    sortie.close();
    for ( int i=0;i<6 ;i++)
        matchs[i].enregistrer_match_de_groupe();
}
void Groupe::download_groupe(Delegation d1,Delegation d2,Delegation d3,Delegation d4)
{
    classement[0]=d1;
    classement[1]=d2;
    classement[2]=d3;
    classement[3]=d4;
    Cla = classement[0].grp;
    Match m1(classement[0],classement[1]);
    matchs[0]=m1;
    Match m2(classement[0],classement[2]);
    matchs[1]=m2;
    Match m3(classement[0],classement[3]);
    matchs[2]=m3;
    Match m4(classement[1],classement[2]);
    matchs[3]=m4;
    Match m5(classement[1],classement[3]);
    matchs[4]=m5;
    Match m6(classement[2],classement[3]);
    matchs[5]=m6;
    matchs[0].download_match_de_groupe();
    matchs[1].download_match_de_groupe();
    matchs[2].download_match_de_groupe();
    matchs[3].download_match_de_groupe();
    matchs[4].download_match_de_groupe();
    matchs[5].download_match_de_groupe();


}
