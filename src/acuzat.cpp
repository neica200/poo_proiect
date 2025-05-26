#include "acuzat.h"
#include <iostream>
using namespace std;

Acuzat::Acuzat(const string &nume, int varsta, const string &ocupatie,const string &acuzatie, bool vinovatie, const string &sentinta) :
Persoana(nume, varsta, ocupatie), acuzatie(acuzatie),vinovatie(vinovatie), sentinta(sentinta){}

Acuzat::Acuzat(const Acuzat &acuzat):Persoana(acuzat){
    this->acuzatie = acuzat.acuzatie;
    this -> vinovatie = acuzat.vinovatie;

}


Acuzat &Acuzat::operator=(Acuzat const &aux) {
    this->acuzatie = aux.acuzatie;
    return *this;
}


const string &Acuzat::getAcuzatie() const {
    return acuzatie;
}

bool Acuzat::esteVinovat() const {
    return vinovatie;
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
    cout<<"Este vinovat(0-Nu,1-Da)?";
    is >> acuzat.vinovatie;
    return is;
}


