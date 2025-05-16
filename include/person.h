#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;
class Persoana {
protected:
    string nume;
    int varsta;
    string ocupatie;
public:
    Persoana();
    Persoana(const string& nume, int varsta, const string& ocupatie);
    Persoana(const Persoana& pers2);
    Persoana& operator=(const Persoana& pers2);
    virtual ~Persoana();

    virtual void afiseazaProfil() const = 0;

    friend ostream& operator<<(ostream& os, const Persoana& pers);
    friend istream& operator>>(istream& is, Persoana& pers);
};

#endif //PERSON_H
