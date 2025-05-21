#include "proba_document.h"
#include <iostream>
using namespace std;

ProbaDocument::ProbaDocument(const string &denumire, const string &tip) : Proba(denumire), tipDocument(tip) {};

void ProbaDocument::descriere() const {
    cout<<"Document: "<<denumire<<" Tip: "<< tipDocument;
}

int ProbaDocument::importanta() const {
    int scor = 0;

    if(tipDocument=="contract") scor+=5;
    else if(tipDocument=="factura") scor+=3;
    else scor+=1;

    if (denumire.length() > 10) scor+=2;

    if (valida()) scor+=3;

    return scor;
}

void ProbaDocument::validare() {
    valida = tipDocument.length() > 3;
}



