#include "proba_audio.h"
#include <sstream>
using namespace std;

ProbaAudio::ProbaAudio(const string &denumire, int durata, int claritate):
    Proba(denumire), durata(durata),claritate(claritate){}

string ProbaAudio::descriere() const {
    ostringstream s ;
    s<<"Proba audio: "<<denumire<<" Durata: "<<durata<<" sec, Claritate: "<< claritate<<"/10, Valida: "<<(valida ? "Da" :"Nu");
    return s.str() ;
}

int ProbaAudio::importanta() const {
    int scor = 0;
    if(claritate >= 8) scor += 5;
    else if(claritate >= 5) scor += 3;
    else scor +=1;

    if(durata >=60) scor +=3;
    else if(durata>=30) scor +=2;

    if(valida) scor +=2;;

    return scor;
}


string ProbaAudio::get_denumire() const {
    return denumire;
}



int ProbaAudio::getDurata() const {
    return durata;
}

int ProbaAudio::getClaritate() const {
    return claritate;
}




