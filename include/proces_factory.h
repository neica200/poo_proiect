#ifndef PROCES_FACTORY_H
#define PROCES_FACTORY_H
#include <memory>

#include "avocat.h"
#include "martor.h"
#include "proces.h"

struct DateProces {
    std::shared_ptr<Proces> proces;
    shared_ptr<Avocat> avocat;
};

class ProcesFactory {
private:
    static ListaElemente<Acuzat> acuzatiDisponibili;
    static ListaElemente<Avocat> avocatiDisponibili;
    static ListaElemente<Judecator> judecatoriDisponibili;
    static ListaElemente<Martor> martoriDisponibili;
    static ListaElemente<TipProces> tipuriProceseDisponibile;
    static ListaElemente<Proba> probeDisponibile;
    static ListaElemente<Strategie> strategiiDisponibile;
public:
    ProcesFactory();
  static DateProces creeazaProcesManual(
      TipProces tip,Acuzat acuzat, shared_ptr<Judecator> judecator, ListaElemente<Proba> probe,Avocat avocat);

    static DateProces creeazaProcesRandom();

};

#endif //PROCES_FACTORY_H
