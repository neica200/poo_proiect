#ifndef JUDECATOR_ECHILIBRAT_H
#define JUDECATOR_ECHILIBRAT_H

#include "judecator.h"
using namespace std;

class JudecatorEchilibrat : public Judecator {
public:
    JudecatorEchilibrat(const string& nume = "", int varsta = 0,
         const string& ocupatie="Judecator", int aniExp = 0, Specializare spec = Specializare::Civil);
    void analizeazaProbe() const override;
    void audiazaMartori() const override;
    [[nodiscard]] string getStil() const override;
};


#endif //JUDECATOR_ECHILIBRAT_H
