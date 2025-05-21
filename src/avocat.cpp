#include "avocat.h"
using namespace std;


Avocat::Avocat(const string &nume, int varsta) : Persoana(nume, varsta,"Avocat"), cazuriCastigate(0) {}

void Avocat::adaugaClient(const shared_ptr<Acuzat>& acuzat) {
    clienti.adauga(acuzat);
}

void Avocat::castigaProces() {
    cazuriCastigate++;
}

int Avocat::getCazuriCastigate() const {
    return cazuriCastigate;
}

void Avocat::oferaSfat() {
    cout<< getNume()<<" ofera sfat juridic clientului.\n";
    ///implementare de adaugat dupa tactica

}

void Avocat::afiseazaProfil() const {
    Persoana::afiseazaProfil();
    cout<<"Cazuri castigate: "<<cazuriCastigate<<" Clienti: ";
    for (auto& c: clienti) {
        cout<<" - "<<c->getNume();
    }

}




