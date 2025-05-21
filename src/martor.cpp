#include "martor.h"

Martor::Martor(const string &nume, int varsta, const string &ocupatie, const string &declaratie, bool credibilitate,ParteSustinuta parte):
    Persoana(nume, varsta, ocupatie),parte(parte),declaratie(declaratie),credibilitate(credibilitate)
{}

string Martor::getDeclaratie() const {
    return declaratie;
}

ParteSustinuta Martor::getParte() const {
    return parte;
}


bool Martor::getCredibilitate() const {
    return credibilitate;
}

ostream& operator<<(ostream& os, const Martor& m) {
    os << static_cast<const Persoana&>(m) << " | Declaratie: " << m.getDeclaratie()<<"sustine: ";
    switch (m.getParte()) {
        case 0:
            os << "acuzat";
        else:
            os<<"reclamant"
    }
    return os;
}

istream& operator>>(istream& is, Martor& m) {
    is >> static_cast<Persoana&>(m);
    cout<< "Introdu declaratia: ";
    is.ignore();
    getline(is,m.declaratie);
    cout<< "Introdu credibilitatea(0,1): ";
    is >> m.credibilitate;
    cout<<"Introdu parte(0 = Acuzat, 1 = Reclamant)";
    is>> m.parte[is];
    return is;
}

