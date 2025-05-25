#ifndef MENIU_SINGLETON_H
#define MENIU_SINGLETON_H
#include "lista_elemente.h"
#include "proces.h"
#include "proces_factory.h"

class Meniu {
private:
    ListaElemente<Proces> procese;
    Meniu() = default;
public:
    Meniu(const Meniu &) = delete;
    Meniu &operator=(const Meniu &) = delete;
    static Meniu &getInstance();

    void ruleazaMeniu();
    void afiseazaMeniu() const;
    void creeazaProcesManual();
    void creeazaProcesRandom();


    void ruleazaTurnBased(DateProces dp);
    void vizualizeazaProbe(ListaElemente<Proba> probe) const ;


};

#endif //MENIU_SINGLETON_H
