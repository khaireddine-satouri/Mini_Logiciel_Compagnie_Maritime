#include "membre.hpp"
#include "trajet.hpp"
#include "passager.hpp"
#include "billet.hpp"
#include "port.hpp"

#include <iostream>


membre::membre(string n, string p, string d,int ID, char t,int max):Personne(n,p,d){
id=ID;
type=t;
tonnage_max=max;
}
membre::~membre() {}
int membre::getid()const{
    return id;
}
void membre::setid(int ID){
    id=ID;
}
char membre::gettype()const{
    return type;
}
void membre::settype(char t){
    type=t;
}
int membre::gettonnage_max()const{
    return tonnage_max;
}
void membre::settonnage_max(int max){
    tonnage_max=max;
}
void membre::ajouter_trajet(trajet *t){
    trajets_effectues.push_back(t);
}

bool comparaisont(trajet *t1, trajet *t2){
    if(t1->getannee_depart()==t2->getannee_depart()){
        if(t1->getmois_depart()==t2->getmois_depart()){
            if(t1->getjour_depart()==t2->getjour_depart()){
                return(t1->getheure_depart()<t2->getheure_depart());
            }
            else return (t1->getjour_depart()<t2->getjour_depart());
        }
        else return (t1->getmois_depart()<t2->getmois_depart());
    }
    else return (t1->getannee_depart()<t2->getannee_depart());  
}

//Liste triée (sur la date et l'heure) des trajets effectués par un membre d'équipage pour un mois donné avec total des heures de navigation ;
 void membre::trajets_par_mois(string mois){
    int nbheures=0;
    trajets_effectues.sort(comparaisont);
list<trajet *>::iterator itt;
for(itt=trajets_effectues.begin(); itt!=trajets_effectues.end(); itt++){
    if((*itt)->getmois_depart() == mois){
        if((*itt)->getjour_depart()==(*itt)->getjour_arrivee()){
            //si la date d'arrivée et la date de dépard est dans le même jour
        nbheures+= (*itt)->getheure_arrivee()-(*itt)->getheure_depart();
        }
        else{
            //sinon
           nbheures+= (24-(*itt)->getheure_depart())+((*itt)->getheure_arrivee())+24*((*itt)->getjour_arrivee()-(*itt)->getjour_depart()-1);
        }
        
    }
}
cout<<"bilan personnelle des trajets effectues pour le mois de "<<mois<<" :"<<endl;
    cout<<"membre d'equipage : "<<this->getnom()<<" "<<this->getprenom()<<endl;
    if(this->type=='c'){
    cout<<"role : capitaine"<<endl;
    }
    else if(this->type=='s'){
    cout<<"role : second"<<endl;
    }
    else if(this->type=='m'){
    cout<<"role : matelot"<<endl;
    }
    else if(this->type==' '){
    cout<<"role : non spécifier "<<endl; 
    }
    else{
    cout<<"role : incorrecte "<<endl;  
    }
    cout<<"identifiant : "<<this->getid()<<endl;
    cout<<"nombres d'heures de navigation : "<<nbheures<<"h"<<endl;
    cout<<"liste des trajets effectues : "<<endl;
    //affichage de la liste triée des trajets effectués pour le membre d'equipage
    for(itt=trajets_effectues.begin(); itt!=trajets_effectues.end(); itt++){
    (*itt)->description_trajet();
    cout<<endl;
    cout<<endl;
    }
}
