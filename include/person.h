#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Persoana {
private:
    string nume;
    int varsta;
    string ocupatie;
public:
    Persoana();
    Persoana(const string& nume, int varsta, const string& ocupatie);
    Persoana(const Persoana& pers2);
    Persoana& operator=(const Persoana& pers2);
    virtual ~Persoana();

    //getter
    const string& getNume() const;
    int getVarsta() const;
    const string& getOcupatie() const;


    virtual void afiseazaProfil() const;

    friend ostream& operator<<(ostream& os, const Persoana& pers);
    friend istream& operator>>(istream& is, Persoana& pers);
};

#endif //PERSON_H
