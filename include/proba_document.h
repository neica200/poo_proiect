#ifndef PROBA_DOCUMENT_H
#define PROBA_DOCUMENT_H

#include "proba.h"

class ProbaDocument : public Proba {
    string tipDocument;
public:
    ProbaDocument(const string& denumire, const string& tip);
    string get_denumire() const override;
    string descriere() const  override;
    int importanta() const override;
    void validare() override;

};

#endif //PROBA_DOCUMENT_H
