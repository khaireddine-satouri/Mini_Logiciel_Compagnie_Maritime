#ifndef __ESCALE__H_
#define __ESCALE__H_
#include <string>
#include <vector>
#include <list>
using namespace std;
class port;
class trajet;
class membre;
class escale{
private:
    port *p;
    string date_arrivee_escale;
    int heure_arrivee_escale;
    int duree_escale;
public:
    escale(port *,string,int,int);
    ~escale();
    string getdate_arrivee_escale()const;
    int getduree_escale()const;
    int getheure_arrivee_escale()const;
    port *getport()const;
    
    void setdate_arrivee_escale(string);
    void setduree_escale(int);
    void setheure_arrivee_escale(int);
    void setport(port *p);

    void description_escale();
};
#endif