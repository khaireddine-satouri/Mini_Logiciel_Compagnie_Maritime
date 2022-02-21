#include "trajet.hpp"
#include "passager.hpp"
#include "escale.hpp"
#include "billet.hpp"
#include "port.hpp"
#include "membre.hpp"
#include "capitaine.hpp"
#include "second.hpp"
#include "matelot.hpp"
#include "navire.hpp"
#include "mixte.hpp"
#include "fret.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace std ;

trajet::trajet(int n,port *dep,int ansdep,string mdep,int jdep,int hdep,port *arr,int ansarr,string marr,int jarr,int harr,float prix){
num=n;

depart=dep;
annee_depart=ansdep;
mois_depart=mdep;
jour_depart=jdep;
heure_depart=hdep;

arrive=arr;
annee_arrivee=ansarr;
mois_arrivee=marr;
jour_arrivee=jarr;
heure_arrivee=harr;

prix_base=prix;
nbr_reservations=0;
}
trajet::~trajet(){}
//gettres/setters
navire *trajet::getnav()const{return nav;}
fret *trajet::getfrt()const{return frt;}
mixte *trajet::getmxt()const{return mxt;}
int trajet::getnum()const{return num;}
float trajet::getprix_base()const{return prix_base;}


int trajet::getannee_depart()const{return annee_depart;}
string trajet::getmois_depart()const{return mois_depart;}
int trajet::getjour_depart()const{return jour_depart;}
int trajet::getheure_depart()const{return heure_depart;}

int trajet::getannee_arrivee()const{return annee_arrivee;}
string trajet::getmois_arrivee()const{return mois_arrivee;}
int trajet::getjour_arrivee()const{return jour_arrivee;}
int trajet::getheure_arrivee()const{return heure_arrivee;}

void trajet::setprix_base(float prix){prix_base=prix;}

void trajet::setannee_depart(int ansdep){annee_depart=ansdep;}
void trajet::setmois_depart(string mdep){mois_depart=mdep;}
void trajet::setjour_depart(int jdep){jour_depart=jdep;}
void trajet::setheure_depart(int hdep){heure_depart=hdep;}

void trajet::setannee_arrivee(int ansarr){annee_arrivee=ansarr;}
void trajet::setmois_arrivee(string marr){mois_arrivee=marr;}
void trajet::setjour_arrivee(int jarr){jour_arrivee=jarr;}
void trajet::setheure_arrivee(int harr){heure_arrivee=harr;}

int trajet::getnbr_reservations(){return nbr_reservations;}
void trajet::setnbr_reservations(int n_reservations){
nbr_reservations=n_reservations;
}

void trajet::AjouteEscale(escale *s){
    escales.push_back(s);
}

void trajet::ajouttype_trajet(type_trajet *tr){
t=tr;
}

void trajet::ajoutnavire_marchandise(fret *f){
//verification de l'accréditation du capitaine et les seconds avant d'ajouter un navire
vector<membre *>::iterator it;
it=equipage.begin();


//si le membre de l'équipage est un capitaine ou un second on vérifie son accréditation 
//ici on suppose que tous les membres de type capitaines et seconds se mettent d'accord sur la meme accréditation du tonnage maximal
while(it!=equipage.end()){
    if((*it)->gettype()!='m'){
        if((*it)->gettype()=='c' || (*it)->gettype()=='s'){
            if(((*it)->gettonnage_max()) >= (f->getcapacite())){
                frt=f;
                nav=frt;
                break;
            }
            else {
                cout<<"tonnage de navire réfusé !"<<endl;
                break;
            }
        }
    }
    else { //si c'est un matelot en passe au membre suivant de la liste
        it++;
    }
}
}
void trajet::ajoutnavire_mixte(mixte *mx){
//verification de l'accréditation du capitaine et les seconds avant d'ajouter un navire
vector<membre *>::iterator it;
it=equipage.begin();


//ici on suppose que tous les membres de type capitaines et seconds se mettent d'accord sur la meme accréditation du tonnage maximal
//donc si l'itérateur pointe sur un capitaine ou un second il suffit de vérifier son accréditation son vérifier les autres
while(it!=equipage.end()){
    if((*it)->gettype()!='m'){
        if((*it)->gettype()=='c' || (*it)->gettype()=='s'){
            if(((*it)->gettonnage_max()) >= (mx->getcapacite())){
                mxt=mx;
                nav=mxt;
                break;
            }
            else {
                cout<<"tonnage de navire "<<mx->getnom()<<" réfusé !"<<endl;
                break;
            }
        }
    }
    else { //si c'est un matelot en passe au membre suivant de la liste
        it++;
    }
}
}

void trajet::ajoutequipage(membre *mem ,int n){
m=mem;
        equipage.push_back(m);
        m->ajouter_trajet(this);

}


void trajet::stockerbillet(billet *b){
listbillets.push_back(b);
}


void trajet::description_trajet(){
    cout<<"voyage numero : "<<num<<endl;
    cout<<"depard :"<<endl;
    cout<<"\t"<<"Date : "<<annee_depart<<"/"<<mois_depart<<"/"<<jour_depart<<" à "<<heure_depart<<"h"<<endl;
    cout<<"\t"<<"Lieux : "<<depart->getlieux()<<endl;
    cout<<"\t"<<"Port : "<<depart->getnom()<<endl;
    cout<<"arrivee :"<<endl;
    cout<<"\t"<<"Date : "<<annee_arrivee<<"/"<<mois_arrivee<<"/"<<jour_arrivee<<" à "<<heure_arrivee<<"h"<<endl;
    cout<<"\t"<<"Lieux : "<<arrive->getlieux()<<endl;
    cout<<"\t"<<"Port : "<<arrive->getnom()<<endl;
    if(escales.empty()!=true){ //si il y'a des escales pour le trajet 
        vector<escale *>::iterator it;
        cout<<"escales :"<<endl;
        for(it=escales.begin();it!=escales.end();it++){
            (*it)->description_escale();
        }

    }
}




