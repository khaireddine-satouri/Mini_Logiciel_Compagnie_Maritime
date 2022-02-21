#ifndef __TYPE__H_
#define __TYPE__H_
#include <string>
using namespace std;
class type_trajet{
private:
    string type;
public:
    type_trajet(string);
    string gettype()const;
    void settype(string);
};
#endif