#ifndef __BILLET__H_
#define __BILLET__H_
#include <string>
#include <vector>
class Passager;
class trajet;
using namespace std;
class billet{
private:
    Passager *passager;
    trajet *traj;
    //vector<trajet *>listtrajets;
    int num;
public:
    billet(int,Passager *,trajet *);
    ~billet();
    int getnum();
    float calculprix();//if(this.getp().gettype=='..'){ return this.gettrajet().getprix_base -..%} else if ...
    Passager *getp()const;
    trajet *gett()const;
};
#endif