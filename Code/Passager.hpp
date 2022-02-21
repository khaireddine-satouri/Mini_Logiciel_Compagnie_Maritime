#ifndef __PASSAGER__H_
#define __PASSAGER__H_
#include <list>
#include <vector>
#include "Personne.hpp"
using namespace std;
class billet;
class trajet;
class escale;
class Passager:public Personne{
private:
    vector<trajet *>listtrajets;
    int numero;
    char type;
    list<billet *>billets;
public:
    Passager(string,string,string,int,char);
    ~Passager();
    void acheterbillet(trajet *,int num);//billets.push_back(new billet(num,this,t)) // t.ajoutnavire.getnbrpassagers()++
    int getnumero()const;
    void setnumero(int);
    char gettype()const;
    void settype(char);
        //on utilise calculprix()pour l'affichage 
    void description_listbillets();

};
#endif