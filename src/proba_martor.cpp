#include "proba_martor.h"
#include "martor.h"
#include <sstream>
using namespace std;

ProbaMartor::ProbaMartor(const string &denumire, bool credibilitate, int relevanta,const shared_ptr<Martor>& martor) :
    Proba(denumire),credibilitate(credibilitate),relevantaDeclaratie(relevanta),martor(martor){}

string ProbaMartor::descriere() const {
    ostringstream s;
    s<<"Proba martor: "<<denumire<< ", Credibilitate: "<<(credibilitate ? "Da" : "Nu")<<", Relevanta declaratie: "<<relevantaDeclaratie<<"/10, Valida: "<<(valida ? "Da" : "Nu");
    return s.str();
}

int ProbaMartor::importanta() const {
    int scor =0;
    if (credibilitate) scor+=5;

    if (relevantaDeclaratie > 7) scor+=4;
    else if(relevantaDeclaratie >4) scor+=2;
    else scor+=1;

    if(valida) scor+=1;
    return scor;
}

void ProbaMartor::validare() {
    valida = credibilitate && relevantaDeclaratie > 4;
}








