#ifndef AVOCAT_H
#define AVOCAT_H

#include "person.h"
#include "acuzat.h"
#include "strategie.h"
#include <memory>

#include "lista_elemente.h"
using namespace std;

class Avocat:public Persoana {
private:
    ListaElemente<Acuzat> clienti;
    int cazuriCastigate;
    shared_ptr<Strategie> strategie;
public:
    Avocat(const string& nume, int varsta);

    void seteazaStrategie(const shared_ptr<Strategie> s);
    void adaugaClient(const shared_ptr<Acuzat>& acuzat);
    void castigaProces();
    [[nodiscard]] int getCazuriCastigate() const;


    string oferaSfat(const Acuzat& acuzat, const ListaElemente<Proba>& probe,const Judecator& judecator, const Proces& proces);
    void seteazaScoruri(map <string,int>& actiuni,const Acuzat& acuzat,const ListaElemente<Proba>& probe,const Judecator& judecator, const Proces& proces);
    void aplicaActiune(string& actiune);
    void afiseazaProfil() const override;
};

#endif //AVOCAT_H
