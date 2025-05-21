#include "reclamant.h"

Reclamant::Reclamant(const std::string &nume, int varsta, const string &ocupatie, const string &motiv):
    Persoana(nume,varsta,ocupatie), motivReclamatie(motiv)
{}

string Reclamant::getMotivReclamatie() const {
    return motivReclamatie;
}

ostream &operator<<(ostream &os, const Reclamant &reclamant) {
    os << static_cast<const Persoana &>(reclamant)<<" | Motiv: " << reclamant.getMotivReclamatie();
    return os;
}

istream &operator>>(istream &is, Reclamant &reclamant) {
    cout<<"Introdu motivul reclamatiei: ";
    is.ignore();
    getline(is,reclamant.motivReclamatie);
    return is;
}
