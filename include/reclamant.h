#ifndef RECLAMANT_H
#define RECLAMANT_H

#include "person.h"

class Reclamant : public Persoana {
private:
    string motivReclamatie;
public:
    Reclamant(const std::string& nume, int varsta,const string& ocupatie, const string& motiv);
    string getMotivReclamatie() const;

    friend std::ostream& operator<<(std::ostream& out, const Reclamant& r);
    friend std::istream& operator>>(std::istream& in, Reclamant& r);
};

#endif //RECLAMANT_H
