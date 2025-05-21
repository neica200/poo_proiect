#include "judecator.h"
#include <iostream>
using namespace std;

Judecator::Judecator(const string &nume, int varsta, int aniExp, Specializare spec) :
    Persoana(nume,varsta,"Judecator"), aniExperienta(aniExp),specializare(spec){}

Judecator::Judecator(const Judecator &ju) :
    Persoana(ju),aniExperienta(ju.aniExperienta),specializare(ju.specializare){}

Judecator& Judecator::operator=(const Judecator &ju) {
    if(this !=&ju) {
        Persoana:operator=(ju);
        aniExperienta = ju.aniExperienta;
        specializare = ju.specializare;
    }
    return *this;
}

Judecator::~Judecator() {}

void Judecator::afiseazaProfil() const {
    Persoana::afiseazaProfil();
    cout<<" Ani experienta: "<< aniExperienta<<" Specializare: ";
    switch(specializare) {
        case Specializare::Civil: cout<<"Civil"; break;
        case Specializare::Penal: cout<<"Penal"; break;
    }
}

int Judecator::getExperienta() const {
    return aniExperienta;
}


std::ostream& operator<<(std::ostream &os, const Judecator &ju) {
    os<<static_cast<const Persoana&>(ju);
    os << " Ani Experienta: "<< ju.aniExperienta<<" Specializare: ";
    switch(ju.specializare) {
        case Specializare::Civil: cout<<"Civil"; break;
        case Specializare::Penal: cout<<"Penal"; break;
    }
    return os;
}

std::istream& operator>>(std::istream &is, Judecator &ju) {
    is >> static_cast<Persoana&>(ju);
    cout<<"Introdu Ani Experienta: ";
    is >> ju.aniExperienta;

    cout<<"Introdu Specializare:(0-Civil, 1-Penal, introdu numarul) ";
    int specializareInt;
    is >> specializareInt;
    if(specializareInt <0 || specializareInt > 1) {
        specializareInt = 0;
    }
    ju.specializare = static_cast<Specializare>(specializareInt);
    return is;

}



