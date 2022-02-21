#ifndef __MIXTE__H_
#define __MIXTE__H_
#include "navire.hpp"
using namespace std;
class mixte:public navire{
private:
    int capacite_passagers;
public:
    mixte(string,int,int,int);
    int getcapacite_passagers()const;
    void setcapacite_passagers(int);
};
#endif