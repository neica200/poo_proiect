#include "martor.h"

#include "acuzat.h"

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
        case ParteSustinuta::Acuzat:
            os << "acuzat";
            break;
        case ParteSustinuta::Reclamant:
            os<<"reclamant";
            break;
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
    int i;
    is>> i;
    if (i==0) {
        m.parte = ParteSustinuta::Acuzat;
    }
    else {
        m.parte = ParteSustinuta::Reclamant;
    }
    return is;
}

