#include "trajet.hpp"
#include "passager.hpp"
#include "billet.hpp"

#include <vector>
#include <iostream>

using namespace std ;

billet::billet(int n, Passager *p, trajet *t){
num=n;
passager=p;
traj=t;
//listtrajets.push_back(t);
t->stockerbillet(this);
}
billet::~billet(){}
int billet::getnum(){
    return num;
}
Passager * billet::getp()const{
    return passager;
}
trajet * billet::gett()const{
    return traj;
}
float billet::calculprix(){
    if(this->getp()->gettype()=='n'){
        return (this->gett()->getprix_base());
    }
    else if(this->getp()->gettype()=='i'){
        return ((this->gett()->getprix_base())*0.25);
    }
    else if(this->getp()->gettype()=='s'){
        return ((this->gett()->getprix_base())*0.5);
    }
    return 0.0;

}