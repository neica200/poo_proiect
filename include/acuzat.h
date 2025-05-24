#ifndef ACUZAT_H
#define ACUZAT_H

#include "person.h"
#include <string>
using namespace std;

class Acuzat : public Persoana {
protected:
    string acuzatie;
    bool vinovatie;
    string sentinta;
public:
    Acuzat(const string& nume,int varsta, const string& ocupatie,const string&  acuzatie, bool vinovatie, const string& sentinta="Nedefinita");

    [[nodiscard]] const string& getAcuzatie() const;
    [[nodiscard]] bool esteVinovat() const;
    [[nodiscard]] const string& getSentinta() const;
    void seteazaSentinta(const string& sent);
    virtual void reactioneazaLaSentinta() const = 0;
    void afiseazaProfil() const override;

    virtual void primesteSfat(const string& sfat);
    friend std::ostream& operator<<(std::ostream& os, const Acuzat& a);
    friend std::istream& operator>>(std::istream& is, Acuzat& a);
};

#endif //ACUZAT_H
