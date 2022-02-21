#include "second.hpp"
#include "membre.hpp"

second::second(string nom, string prenom, string d,int numero, char type,int accreditation):membre(nom,prenom,d,numero,type,accreditation){
tonnage_max=accreditation;
}

void second::settonnage_max(int accreditation ){
     tonnage_max=accreditation;
}