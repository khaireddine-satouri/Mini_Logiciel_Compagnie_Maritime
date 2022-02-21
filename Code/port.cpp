#include <iostream>
#include "port.hpp"
using namespace std;
port::port(string n, string l){
    nom=n;
    lieux=l;
}

string port::getnom()const{
    return nom;
}
string port::getlieux()const{
    return lieux;
}