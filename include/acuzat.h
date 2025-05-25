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
    explicit Acuzat(const string& nume = "",int varsta = 0, const string& ocupatie = "",const string&  acuzatie = "", bool vinovatie = false, const string& sentinta="Nedefinita");
    Acuzat(const Acuzat& acuzat);

    Acuzat& operator=(Acuzat const &aux);
    [[nodiscard]] const string& getAcuzatie() const;
    [[nodiscard]] bool esteVinovat() const;
    [[nodiscard]] const string& getSentinta() const;
    void seteazaSentinta(const string& sent);
    void afiseazaProfil() const override;

    friend std::ostream& operator<<(std::ostream& os, const Acuzat& a);
    friend std::istream& operator>>(std::istream& is, Acuzat& a);
};

#endif //ACUZAT_H
