#include <iostream>
#include <vector>
#include "navire.hpp"
#include "trajet.hpp"
using namespace std;

navire::navire(string n,int ton,int cap){
    nom=n;
    tonnage=ton;
    capacite=cap;
    nbrpassagers=0;
}
string navire::getnom()const{
    return nom;
}
int navire::gettonnage()const{
    return tonnage;
}
int navire::getcapacite()const{
    return capacite;
}

void navire::settonnage(int ton){
    tonnage=ton;
}
void navire::setcapacite(int cap){
    capacite=cap;
}
int navire::getnbrpassagers()const{
    return nbrpassagers;
}
void navire::setnbrpassagers(int nbrps){
    nbrpassagers=nbrps;

}
void navire::ajouttrajer(trajet *t){
    listtrajet.push_back(t);
}
void navire::nbr_passagers_par_annee(int annee){
vector<trajet *>::iterator it;
for(it=listtrajet.begin();it!=listtrajet.end();it++){
    if((*it)->getannee_arrivee()==annee){
       // nbrpassagers+=1;
        setnbrpassagers(getnbrpassagers()+1);
    }
}
cout<<"nombres de passagers pour l'année "<<annee<<" pour la navire "<<nom<<" : "<<nbrpassagers<<endl;
}