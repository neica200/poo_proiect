#ifndef STRATEGIE_H
#define STRATEGIE_H

#include <memory>
#include "acuzat.h"
#include "judecator.h"
#include "proces.h"
#include "lista_elemente.h"
#include "proba.h"

using namespace std;

class Strategie {
    public:
    virtual string oferaSfat(const Acuzat& acuzat, const ListaElemente<Proba>& probe, const Judecator& judecator, const Proces& tip ) = 0;
    virtual ~Strategie() = default;
};

#endif //STRATEGIE_H
