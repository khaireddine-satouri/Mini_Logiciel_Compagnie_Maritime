#ifndef __CAPITAINE__H_
#define __CAPITAINE__H_
//#include <string>
#include "membre.hpp"
using namespace std;
class capitaine:public membre{
private:
    int tonnage_max;
public:
    capitaine(string,string,string,int,char,int);
    void settonnage_max(int);
};
#endif