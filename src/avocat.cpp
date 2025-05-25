#include "avocat.h"

#include "strategie_agresiva.h"
#include "strategie_echilibrata.h"
#include "strategie_emotionanta.h"
using namespace std;


Avocat::Avocat(const string &nume, int varsta,int cazuriCastigate) : Persoana(nume, varsta,"Avocat"), cazuriCastigate(cazuriCastigate),strategie(nullptr) {}


void Avocat::seteazaStrategie(const shared_ptr<Strategie>& s) {
    strategie = s;
}

void Avocat::seteazaScoruri(map<string, int> &actiuni, const Acuzat &acuzat, const ListaElemente<Proba> &probe, const Judecator &judecator, const Proces &proces) {
    if(strategie)
        strategie->seteazaScoruri(actiuni, acuzat, probe, judecator, proces);
}

void Avocat::aplicaActiune(string &actiune) {
    if(strategie)
        strategie->aplicaActiune(actiune);
}

shared_ptr<Strategie> Avocat::getStrategie() const{
    return strategie;
}



void Avocat::castigaProces() {
    cazuriCastigate++;
}

int Avocat::getCazuriCastigate() const {
    return cazuriCastigate;
}

string Avocat::oferaSfat(const Acuzat &acuzat, const ListaElemente<Proba> &probe, const Judecator &judecator, const Proces &proces) {
    if (strategie)
        return strategie->oferaSfat(acuzat, probe, judecator, proces);
    else return "Inca ma gandesc";
}


void Avocat::afiseazaProfil() const {
    Persoana::afiseazaProfil();
    cout<<" Cazuri castigate: "<<cazuriCastigate<<" Clienti: ";

}

void Avocat::seteazaCazuri(int i) {
    cazuriCastigate = i;
}


shared_ptr<Strategie> Avocat::getStrategie() {
    return strategie;
}


istream &operator>>(istream &is, Avocat &avocat) {
    is>> static_cast<Persoana &>(avocat);
    cout<<"Cazuri castigate: ";
    int i;
    cin>> i;
    avocat.seteazaCazuri(i);

    return is;
}





