#include "membre.cpp"
#include "port.cpp"
#include "capitaine.cpp"
#include "matelot.cpp"
#include "trajet.cpp"
#include "billet.cpp"
#include "Passager.cpp"
#include "Personne.cpp"
#include "navire.cpp"
#include "mixte.cpp"
#include "fret.cpp"
#include "normal.cpp"
#include "insulaire_sec.cpp"
#include "insulaire.cpp"
#include "second.cpp"
#include "escale.cpp"
#include<iostream>
#include<string>
using namespace std;
int main(void){
    
    capitaine C1("thomas","Bernard","18/06/1990",11,'c',1000);
    capitaine C2("patric","christophe","18/06/1990",13,'c',6000);
    second S1("théo","Durand","19/04/1969",22,'s',1000);
    matelot M1("alexander","Dubois","20/03/1997",55,'m',1000);
    matelot M2("adams","Dubois","20/03/1997",55,'m',1000);
    matelot M3("dali","charni","20/03/1997",55,'m',1000);

    port P1("carthage","tunis");
    port P2("mars","marseille");
    port P3("vens","venise");
    escale ES1(&P3,"05/12/2021",16,2);
    
    normal N1("khaireddine","satouri","18/05/2000",1200,'n');
    normal N2("Léo","Richard","18/05/2000",1200,'n');
    Insulaire I1("Gabriel","martin","20/06/2000",1201,'i');
    Insulaire_sec IS1("kalai","hedi","20/06/2000",1201,'s');
    
    trajet T1(123,&P1,2021,"decembre",5,12,&P2,2021,"decembre",7,21,50.);
    trajet T2(124,&P3,2021,"decembre",10,10,&P2,2021,"decembre",10,18,50.);
    trajet T3(125,&P3,2022,"janvier",10,10,&P2,2022,"janvier",10,18,50.);
    
    mixte NAV1("hannibal",5000,800,3);
    fret NAV2("ellisa",5000,200);
    fret NAV3("soft",10000,8000);
    
    T1.ajoutequipage(&C1,1);
    T1.ajoutequipage(&S1,10);
    T1.ajoutequipage(&M1,20);
    T1.ajoutequipage(&M3,21);
    T1.ajoutnavire_mixte(&NAV1);
    T1.AjouteEscale(&ES1);

    T2.ajoutequipage(&C1,1);
    T2.ajoutequipage(&S1,10);
    T2.ajoutequipage(&M1,20);
    T2.ajoutequipage(&M2,21);
    T1.ajoutequipage(&M3,22);
    T2.ajoutnavire_marchandise(&NAV2);

    T3.ajoutequipage(&C2,2);
    T3.ajoutnavire_marchandise(&NAV3);//ici la navire va etre refuse par le capitaine 
    
    N1.acheterbillet(&T1,1);
    N2.acheterbillet(&T1,2);
    IS1.acheterbillet(&T1,3);
    I1.acheterbillet(&T1,4);
    N1.acheterbillet(&T1,5);
    
    N1.description_listbillets();
    N2.description_listbillets();
    IS1.description_listbillets();
    I1.description_listbillets();
    C1.trajets_par_mois("decembre");
    M1.trajets_par_mois("decembre");
    NAV1.nbr_passagers_par_annee(2021);
    
}