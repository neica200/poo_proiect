#include "proba_document.h"
#include <sstream>
using namespace std;

ProbaDocument::ProbaDocument(const string &denumire, const string &tip) : Proba(denumire), tipDocument(tip) {};

string ProbaDocument::descriere() const {
    ostringstream s;
    s<<"Document: "<<denumire<<" Tip: "<< tipDocument;
    return s.str();
}

int ProbaDocument::importanta() const {
    int scor = 0;

    if(tipDocument=="contract") scor+=5;
    else if(tipDocument=="factura") scor+=3;
    else scor+=1;

    if (denumire.length() > 10) scor+=2;

    if (esteValida()) scor+=3;

    return scor;
}

string ProbaDocument::get_denumire() const {
    return tipDocument;
}






