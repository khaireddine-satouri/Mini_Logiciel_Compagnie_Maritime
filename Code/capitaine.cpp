#include "capitaine.hpp"
#include "membre.hpp"

capitaine::capitaine(string nom, string prenom, string d,int numero, char type,int accreditation):membre(nom,prenom,d,numero,type,accreditation){
tonnage_max=accreditation;
}

void capitaine::settonnage_max(int accreditation ){
     tonnage_max=accreditation;
}
