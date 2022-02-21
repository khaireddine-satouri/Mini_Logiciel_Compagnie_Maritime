#include "port.hpp"
#include "trajet.hpp"
#include "membre.hpp"
#include "escale.hpp"
#include <iostream>
#include<string>
using namespace std ;

escale::escale(port* pr,string date_arrivee,int heure_arrivee,int duree){
 p=pr;
 date_arrivee_escale=date_arrivee;
 heure_arrivee_escale=heure_arrivee;
 duree_escale=duree;
}
escale::~escale(){}

port *escale::getport()const{return p;}
string escale::getdate_arrivee_escale()const{return date_arrivee_escale;}
int escale::getduree_escale()const{return duree_escale;}
int escale::getheure_arrivee_escale()const{return heure_arrivee_escale;}

void escale::setport(port *pr){p=pr;}
void escale::setdate_arrivee_escale(string date_escale){date_arrivee_escale=date_escale;}
void escale::setduree_escale(int dur_escale){duree_escale=dur_escale;}
void escale::setheure_arrivee_escale(int heure_escale){heure_arrivee_escale=heure_escale;}

void escale::description_escale(){
cout<<"\t"<<"Lieux : "<<getport()->getlieux()<<endl;
cout<<"\t"<<"Port : "<<getport()->getnom()<<endl;
cout<<"\t"<<"date d'arrivée : "<<getdate_arrivee_escale()<<endl;
cout<<"\t"<<"heure prévue d'arrivée : "<<getheure_arrivee_escale()<<"h"<<endl;
cout<<"\t"<<"durée d'escale : "<<getduree_escale()<<"h"<<endl;
}