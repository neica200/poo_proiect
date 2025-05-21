#ifndef INCULPAT_H
#define INCULPAT_H

#include "acuzat.h"

class Inculpat :public Acuzat {
    Inculpat(const string& nume, int varsta, const string& ocupatie, const string& acuzatie, bool vinovatie);
    void reactioneazaLaSentinta() const override;
};

#endif //INCULPAT_H
