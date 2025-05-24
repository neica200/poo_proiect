#ifndef STRATEGIE_ECHILIBRATA_H
#define STRATEGIE_ECHILIBRATA_H

#include "strategie.h"

class StrategieEchilibrata : public Strategie {
    public:
    string oferaSfat(const Acuzat &acuzat, const ListaElemente<Proba> &probe, const Judecator &judecator, const Proces &tip) override;
    void seteazaScoruri(std::map<std::string, int> &actiuni, const Acuzat &acuzat, const ListaElemente<Proba> &probe, const Judecator &judecator, const Proces &tip) override;
    void aplicaActiune(string &optiune) override;
};



#endif //STRATEGIE_ECHILIBRATA_H
