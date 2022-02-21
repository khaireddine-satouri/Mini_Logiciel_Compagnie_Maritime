#include "mixte.hpp"
 mixte::mixte(string nom,int tonnage,int capacite,int cappas):navire(nom,tonnage,capacite){
     capacite_passagers=cappas;
 }
 int mixte::getcapacite_passagers()const{
     return capacite_passagers;
 }
 void mixte::setcapacite_passagers(int cap){
     capacite_passagers=cap;
 }
 