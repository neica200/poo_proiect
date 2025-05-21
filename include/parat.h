#ifndef PARAT_H
#define PARAT_H

#include "acuzat.h"

class Parat :public Acuzat {
    Parat(const string& nume, int varsta, const string& ocupatie, const string& acuzatie, bool vinovatie);
    void reactioneazaLaSentinta() const override;
};

#endif //PARAT_H
