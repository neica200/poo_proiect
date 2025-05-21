#include "proba.h"

Proba::Proba(const string &denumire):denumire(denumire),valida(false) {}
bool Proba::esteValida() const {
    return valida;
}

Proba::~Proba(){}

ostream &operator<<(ostream &out, const Proba &proba) {
    proba.descriere();
    return out;
}

