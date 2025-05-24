#include "acuzat.h"
#include <iostream>
using namespace std;

Acuzat::Acuzat(const string &nume, int varsta, const string &ocupatie,const string &acuzatie, bool vinovatie, const string &sentinta) :
Persoana(nume, varsta, ocupatie), acuzatie(acuzatie),vinovatie(vinovatie), sentinta(sentinta){}

const string &Acuzat::getAcuzatie() const {
    return acuzatie;
}

bool Acuzat::esteVinovat() const {
    return vinovatie;
}

void Acuzat::primesteSfat(const string &sfat) {
    cout<<"Acuzatul "<< getNume()<<" primeste sfatul: "<<sfat<<endl;
}

const string &Acuzat::getSentinta() const {
    return sentinta;
}

void Acuzat::seteazaSentinta(const string &sent) {
    sentinta = sent;
}

void Acuzat::afiseazaProfil() const {
    Persoana::afiseazaProfil();
    cout<<", Acuzatie: "<< getAcuzatie()<<
        ", Vinovatie: "<< (esteVinovat() ? "Vinovat" : "Nevinovat")<<", Sentinta: "<<getSentinta();
}


ostream &operator<<(ostream &os, const Acuzat &acuzat) {
    os<< static_cast<const Persoana &>(acuzat).getNume()<<", Acuzatie: "<< acuzat.getAcuzatie()<<
        ", Vinovatie: "<< (acuzat.esteVinovat() ? "Vinovat" : "Nevinovat")<<", Sentinta: "<<acuzat.getSentinta();
    return os;

}

istream &operator>>(istream &is, Acuzat &acuzat) {
    is>> static_cast<Persoana &>(acuzat);
    cout<<"Acuzatie: ";
    is.ignore();
    getline(is, acuzat.acuzatie);
    cout<<"Este vinovat?";
    is >> acuzat.vinovatie;
    return is;
}


