#ifndef AVOCAT_H
#define AVOCAT_H

#include "person.h"
#include "acuzat.h"
#include <vector>
#include <memory>

#include "lista_elemente.h"
using namespace std;

class Avocat:public Persoana {
private:
    ListaElemente<Acuzat> clienti;
    int cazuriCastigate;
public:
    Avocat(const string& nume, int varsta);


    void adaugaClient(const shared_ptr<Acuzat>& acuzat);
    void castigaProces();
    [[nodiscard]] int getCazuriCastigate() const;


    void oferaSfat();
    void afiseazaProfil() const override;
};

#endif //AVOCAT_H
