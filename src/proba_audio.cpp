#include "proba_audio.h"
#include <iostream>
using namespace std;

ProbaAudio::ProbaAudio(const string &denumire, int durata, int claritate):
    Proba(denumire), durata(durata),claritate(claritate){}

void ProbaAudio::descriere() const {
    cout<<"Proba audio: "<<denumire<<" Durata: "<<durata<<" sec, Claritate: "<< claritate<<"/10, Valida: "<<(valida ? "Da" :"Nu");
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

void ProbaAudio::validare() {
    valida = claritate >=5 && durata>10;
}

int ProbaAudio::getDurata() const {
    return durata;
}

int ProbaAudio::getClaritate() const {
    return claritate;
}




