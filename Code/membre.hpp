#ifndef __MEMBRE__H_
#define __MEMBRE__H_
//#include <string>
#include "Personne.hpp"

#include <list>
using namespace std;
class trajet ;
class type_trajet;
class port;
class navire;
class billet;
class escale;
class membre:public Personne{
private:
    int id;
    char type;
    int tonnage_max;
    list<trajet *>trajets_effectues;
public:
     membre(string,string,string,int,char,int);
    ~membre();
    int gettonnage_max()const;
    int getid()const;
    list<membre*>getlistmembres();
    void setid(int);
    char gettype()const;
    void settype(char);
    void settonnage_max(int);
    void ajouter_trajet(trajet *);
    void trajets_par_mois(string);
};
#endif