#ifndef __PORT__H_
#define __PORT__H_
#include <string>
using namespace std;
class port{
private:
    string nom;
    string lieux;
public:
    port(string,string);
    string getnom()const;
    string getlieux()const;
};
#endif