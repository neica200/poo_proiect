#ifndef JUDECATOR_SEVER_H
#define JUDECATOR_SEVER_H

#include "judecator.h"
using namespace std;

class JudecatorSever : public Judecator {
public:
    explicit JudecatorSever(const string& nume = "", int varsta = 0,
    int aniExp = 0, Specializare spec = Specializare::Civil);
    void analizeazaProbe() const override;
    void audiazaMartori() const override;
    [[nodiscard]] string getStil() const override;
};

#endif //JUDECATOR_SEVER_H
