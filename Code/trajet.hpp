#ifndef __TRAJET__H_
#define __TRAJET__H_
#include <string>
#include <vector>
#include <list>
using namespace std;
class type_trajet;
class port;
class escale;
class navire;
class mixte;
class fret;
class membre;
class second;
class capitaine;
class matelot;
class billet;
class trajet{
private:
    int num;
    float prix_base;
    type_trajet *t;
    navire *nav;
    fret *frt;
    mixte *mxt;
    port *depart;
    port *arrive;
    membre *m;
    
    vector<escale *>escales;
    vector<membre *>equipage;
    vector<billet *>listbillets;
    int nbr;
    
    int annee_depart;
    string mois_depart;
    int jour_depart;
    int heure_depart;

    int annee_arrivee;
    string mois_arrivee;
    int jour_arrivee;
    int heure_arrivee;

    int nbr_reservations;
public:
    trajet(int,port *,int,string,int,int,port *,int,string,int,int,float);
    ~trajet();
    navire * getnav()const;
    fret * getfrt()const; 
    mixte * getmxt()const;
    int getnum()const;
    float getprix_base()const;
    
    virtual int getannee_depart()const;
    virtual string getmois_depart()const;
    virtual int getjour_depart()const;
    virtual int getheure_depart()const;

    int getannee_arrivee()const;
    string getmois_arrivee()const;
    int getjour_arrivee()const;
    int getheure_arrivee()const;
    
    
    void setprix_base(float);

    void setannee_depart(int);
    void setmois_depart(string);
    void setjour_depart(int);
    void setheure_depart(int);

    void setannee_arrivee(int);
    void setmois_arrivee(string);
    void setjour_arrivee(int);
    void setheure_arrivee(int);

    int getnbr_reservations();
    void setnbr_reservations(int);


    void AjouteEscale(escale *);
    void ajouttype_trajet(type_trajet *);
    void ajoutnavire_marchandise(fret *);
    void ajoutnavire_mixte(mixte *);
    void ajoutequipage(membre *,int);
    void stockerbillet(billet *);//listebillets.push_back(b)
    
    void description_trajet();
    //void archive_billets();
};
#endif