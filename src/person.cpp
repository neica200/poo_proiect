#include "person.h"
using namespace std;

Persoana::Persoana() :
    nume("Necunoscut"),varsta(0),ocupatie("Necunoscuta"){}

Persoana::Persoana(const string &nume, int varsta, const string &ocupatie) {
    this->nume = nume;
    this->varsta = varsta;
    this->ocupatie = ocupatie;
}

Persoana::Persoana(const Persoana &pers2) : nume(pers2.nume), varsta(pers2.varsta),ocupatie(pers2.ocupatie){}

Persoana& Persoana::operator=(const Persoana &pers2) {
    if (this != &pers2) {
        nume = pers2.nume;
        varsta = pers2.varsta;
        ocupatie = pers2.ocupatie;
    }
    return *this;
}

Persoana::~Persoana() {}

const string &Persoana::getNume() const {
    return nume;
}

int Persoana::getVarsta() const {
    return varsta;
}

const string &Persoana::getOcupatie() const {
    return ocupatie;
}


ostream& operator<<(ostream &os, const Persoana &persoana) {
    os << "Nume: " << persoana.nume << ", Varsta: " << persoana.varsta << ", Ocupatie: " << persoana.ocupatie;
    return os;
}

istream& operator>>(istream &is, Persoana &persoana) {
    cout<<"Introdu nume: ";
    is>>persoana.nume;
    cout<<"Introdu varsta: ";
    is>>persoana.varsta;
    cout<<"Introdu ocupatie: ";
    is>>persoana.ocupatie;
    return is;
}