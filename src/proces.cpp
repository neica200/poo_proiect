#include "proces.h"
using namespace std;

int Proces::scor = 0;

Proces::Proces(TipProces t , const Acuzat&  a/*, const Avocat& av*/, const std::shared_ptr<Judecator>& j,
               const ListaElemente<Proba>& p)
    : tip(t),acuzat(a)/*, avocat(av)*/, judecator(j), probe(p){}


void Proces::setTipProces(TipProces t) {
    tip = t;
}

void Proces::setAcuzat(Acuzat const &a) {
    acuzat = a;
}

void Proces::setJudecator(shared_ptr<Judecator> j) {
    judecator = std::move(j);
}

void Proces::setProbe(ListaElemente<Proba> p) {
    probe = std::move(p);
}

/*void Proces::setAvocat(const Avocat& av) {
    avocat = av;
}*/

TipProces Proces::getTip() const {
    return tip;
}

Acuzat& Proces::getAcuzat() {
    return acuzat;
}

/*Avocat& Proces::getAvocat() {
    return avocat;
}*/

const Judecator& Proces::getJudecator() const {
    return *judecator;
}

const ListaElemente<Proba> Proces::getProbe() const {
    return probe;
}

int Proces::getScor() const {
    return scor;
}

void Proces::setScor(int s) {
    scor+=s;
}

void Proces::resetProces() {
    scor = 0;
}



void Proces::afiseazaRezultatFinal() const{
    if(scor<10) {
        cout<<"Ai fost gasit vinovat";

    } else {
        cout<<"Ai fost gasit nevinovat";
    }

}


