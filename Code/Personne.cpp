#include <iostream>
#include "Personne.hpp"
using namespace std;

Personne::Personne(string n, string p, string d){
    nom=n;
    prenom=p;
    date_naissance=d;
}
Personne::~Personne(){}
string Personne::getnom()const{
    return nom;
}
string Personne::getprenom()const{
    return prenom;
}
string Personne::getdate_naissance()const{
    return date_naissance;
}