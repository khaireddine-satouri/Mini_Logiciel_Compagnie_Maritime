#ifndef __SECOND__H_
#define __SECOND__H_
//#include <string>
#include "membre.hpp"
using namespace std;
class second:public membre{
private:
    int tonnage_max;
public:
    second(string,string,string,int,char,int);
    void settonnage_max(int);
};
#endif