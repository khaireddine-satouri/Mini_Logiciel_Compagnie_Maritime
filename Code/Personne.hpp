#ifndef __PERSONNE__H_
#define __PERSONNE__H_
#include <string>

using namespace std;
class Personne{
private:
    string nom;
    string prenom;
    string date_naissance;
public:
    Personne(string,string,string);
    ~Personne();
    string getnom()const;
    string getprenom()const;
    string getdate_naissance()const;

};
#endif