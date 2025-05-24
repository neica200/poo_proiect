#ifndef STRATEGIE_AGRESIVA_H
#define STRATEGIE_AGRESIVA_H

#include "strategie.h"

class StrategieAgresiva :public Strategie {
public :
    string oferaSfat(const Acuzat &acuzat, const ListaElemente<Proba> &probe, const Judecator &judecator, const Proces &tip) override;
    void seteazaScoruri(std::map<std::string, int> &actiuni, const Acuzat &acuzat, const ListaElemente<Proba> &probe, const Judecator &judecator, const Proces &tip) override;
    void aplicaActiune(string &optiune) override;
};



#endif //STRATEGIE_AGRESIVA_H
