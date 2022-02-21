#include "Passager.hpp"
#include "billet.hpp"
#include "trajet.hpp"
#include "navire.hpp"
#include "escale.hpp"
#include "mixte.hpp"
//#include "escale.hpp"
#include <iostream>
#include <vector>
Passager::Passager(string n, string p, string d,int num, char t):Personne(n,p,d){
numero=num;
type=t;
}
Passager::~Passager(){}
int Passager::getnumero()const{
    return numero;
}
void Passager::setnumero(int num){
    numero=num;
}
char Passager::gettype()const{
    return type;
}
void Passager::settype(char t){
    type=t;
}
void Passager::acheterbillet(trajet *tr,int num){
    tr->setnbr_reservations(tr->getnbr_reservations()+1);
    //on vérifie qu'il y a encore des billets disponible pour le voyage 
    if((tr->getnbr_reservations()) > ((tr->getmxt())->getcapacite_passagers())){
        cout<<"malheureusement! pas de places diponibles pour le voyage numéro "<<tr->getnum()<<",la billet numero "<<num<<" ne peut pas etre reserver"<<endl;
    }
    else{
    listtrajets.push_back(tr);
    billets.push_back(new billet(num,this,tr));
    (tr->getnav())->ajouttrajer(tr);
    }
}
bool comparaison(billet *b1, billet *b2){
    if(b1->gett()->getannee_depart()==b2->gett()->getannee_depart()){
        if(b1->gett()->getmois_depart()==b2->gett()->getmois_depart()){
            if(b1->gett()->getjour_depart()==b2->gett()->getjour_depart()){
                return(b1->gett()->getheure_depart()<b2->gett()->getheure_depart());
            }
            else return (b1->gett()->getjour_depart()<b2->gett()->getjour_depart());
        }
        else return (b1->gett()->getmois_depart()<b2->gett()->getmois_depart());
    }
    else return (b1->gett()->getannee_depart()<b2->gett()->getannee_depart());  
}

//list triée (sur la date et l'heure) des trajets de billets acheter par un client 
void Passager::description_listbillets(){
billets.sort(comparaison);
list<billet *>::iterator it1;
if(billets.empty()==true){ //si le client n'a acheté aucune billet
    cout<<"pas encore de billets acheter pour le client "<<this->getnom()<<" "<<this->getprenom()<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    }
else{
    //affichage de la liste triée des billets d'un client 
cout<<"description detaille des billets acheter pour le client "<<this->getnom()<<" "<<this->getprenom()<<" :"<<endl;
for(it1=billets.begin();it1 !=billets.end();it1++){
cout<<"-------------------------------------------------"<<endl;
cout<<"numero de billet : "<<(*it1)->getnum()<<endl;
cout<<"prix : "<<(*it1)->calculprix()<<" euros"<<endl;
(*it1)->gett()->description_trajet(); 
cout<<"-------------------------------------------------"<<endl;
}
}
}
