#ifndef JUDECATOR_H
#define JUDECATOR_H

#include "person.h"
#include "proces.h"
#include <string>
#include <iostream>
using namespace std;

enum class Specializare {
    Civil,Penal
};

ostream& operator<<(std::ostream& out, const Specializare& s);

class Judecator : public Persoana {
protected:
    int aniExperienta;
    Specializare specializare;
public:
    Judecator(const string& nume = "", int varsta = 0,
         const string& ocupatie="Judecator", int aniExp = 0, Specializare spec = Specializare::Civil);
    Judecator(const Judecator& ju);
    Judecator& operator=(const Judecator& ju);
    virtual ~Judecator();

    void afiseazaProfil() const override;
    virtual string getStil() const=0;
    int getExperienta() const;

    virtual void solutioneazaProces(const Proces& proces) const = 0;
    virtual void analizeazaProbe() const = 0;
    virtual void audiazaMartori() const = 0;

    friend ostream& operator<<(ostream& os, const Judecator& ju);
    friend istream& operator>>(istream& is, Judecator& ju);
};

#endif //JUDECATOR_H
