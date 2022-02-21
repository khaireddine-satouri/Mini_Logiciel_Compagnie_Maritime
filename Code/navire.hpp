#ifndef __NAVIRE__H_
#define __NAVIRE__H_
#include <string>
#include <vector>
using namespace std;
class trajet;
class navire{
private:
    vector<trajet *>listtrajet;
    string nom;
    int tonnage;
    int capacite;
    int nbrpassagers;//nombre de passagers par navirre pour l'année en cour
public:
    navire(string,int,int);
    string getnom()const;
    int gettonnage()const;
    int getcapacite()const;
    void settonnage(int);
    void setcapacite(int);
    int getnbrpassagers()const;
    void setnbrpassagers(int);
    void ajouttrajer(trajet *);
    void nbr_passagers_par_annee(int);
};
#endif