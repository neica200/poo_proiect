#ifndef PROBA_H
#define PROBA_H
#include <string>
using namespace std;

class Proba {
protected:
    string denumire;
    bool valida;
public:
    Proba(const string& denumire = "");
    virtual ~Proba();

    virtual string get_denumire() const = 0;
    virtual string descriere() const =0;
    virtual int importanta() const = 0;
    virtual void validare() = 0;

    bool esteValida() const;

    friend ostream& operator<<(ostream& os, const Proba& proba);

};

#endif //PROBA_H
