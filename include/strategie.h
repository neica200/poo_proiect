#ifndef STRATEGIE_H
#define STRATEGIE_H


#include <map>
#include "acuzat.h"
#include "judecator.h"
#include "proces.h"
#include "lista_elemente.h"
#include "proba.h"

using namespace std;

class Strategie {
protected:
    static map<string,int> actiuniDisponibile;

    public:
    map<string,int> paseazaActiuni();
    virtual string oferaSfat(const Acuzat& acuzat, const ListaElemente<Proba>& probe, const Judecator& judecator, const Proces& tip ) = 0;
    static void getActiuniDisponibile();
    virtual void seteazaScoruri(std::map<std::string, int>& actiuni,const Acuzat& acuzat,const ListaElemente<Proba>& probe,const Judecator& judecator,const Proces& tip) = 0;
    virtual void aplicaActiune(string &optiune)=0;
    virtual ~Strategie() = default;
};

#endif //STRATEGIE_H
