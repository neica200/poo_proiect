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
    explicit Persoana(const string& nume ="", int varsta = 0, const string& ocupatie="");
    Persoana(const Persoana& pers2);
    Persoana& operator=(const Persoana& pers2);
    virtual ~Persoana();

    [[nodiscard]] const string& getNume() const;
    [[nodiscard]] int getVarsta() const;
    [[nodiscard]] const string& getOcupatie() const;


    virtual void afiseazaProfil() const;

    friend ostream& operator<<(ostream& os, const Persoana& pers);
    friend istream& operator>>(istream& is, Persoana& pers);
};

#endif //PERSON_H
