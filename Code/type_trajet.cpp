#include <iostream>
#include "type_trajet.hpp"
using namespace std;
type_trajet::type_trajet(string t){
type=t;
}

string type_trajet::gettype()const{
    return type;
}
void type_trajet::settype(string t){
    type=t;
}