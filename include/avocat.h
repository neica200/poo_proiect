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
    int cazuriCastigate;
    shared_ptr<Strategie> strategie;
public:
    explicit Avocat(const string& nume = "", int varsta = 0, int cazuri=0);

    void seteazaStrategie(const shared_ptr<Strategie>& s);
    shared_ptr<Strategie> getStrategie();
    void seteazaCazuri(int i);
    void castigaProces();
    [[nodiscard]] int getCazuriCastigate() const;
    [[nodiscard]] shared_ptr<Strategie> getStrategie() const;

    string oferaSfat(const Acuzat& acuzat, const ListaElemente<Proba>& probe,const Judecator& judecator, const Proces& proces);
    void seteazaScoruri(map <string,int>& actiuni,const Acuzat& acuzat,const ListaElemente<Proba>& probe,const Judecator& judecator, const Proces& proces);
    void aplicaActiune(string& actiune);
    void afiseazaProfil() const override;

    friend std::istream& operator>>(std::istream& is, Avocat& a);
};

#endif //AVOCAT_H
