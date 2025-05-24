#include "avocat.h"

#include "strategie_agresiva.h"
using namespace std;


Avocat::Avocat(const string &nume, int varsta) : Persoana(nume, varsta,"Avocat"), cazuriCastigate(0),strategie(nullptr) {}

void Avocat::seteazaStrategie(const shared_ptr<Strategie> s) {
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



void Avocat::adaugaClient(const shared_ptr<Acuzat>& acuzat) {
    clienti.adauga(acuzat);
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
    cout<<"Cazuri castigate: "<<cazuriCastigate<<" Clienti: ";
    for (auto& c: clienti) {
        cout<<" - "<<c->getNume();
    }

}




