#ifndef MARTOR_H
#define MARTOR_H

#include "person.h"

enum class ParteSustinuta {
    Acuzat, Reclamant
};

class Martor : public Persoana {
private:
    ParteSustinuta parte;
    string declaratie;
    bool credibilitate;
public:
    Martor(const string& nume, int varsta, const string& ocupatie, const string& declaratie, bool credibilitate, ParteSustinuta parte);

    [[nodiscard]] const string& getDeclaratie() const;
    [[nodiscard]] bool getCredibilitate() const;
    ParteSustinuta getParte() const;
    friend std::ostream& operator<<(std::ostream& out, const Martor& m);
    friend std::istream& operator>>(std::istream& in, Martor& m);
};

#endif //MARTOR_H
