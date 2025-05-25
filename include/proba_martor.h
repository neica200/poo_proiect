#ifndef PROBA_MARTOR_H
#define PROBA_MARTOR_H

#include <memory>

#include "martor.h"
#include "proba.h"

class ProbaMartor : public Proba {
private:
  bool credibilitate;
  int relevantaDeclaratie;
  shared_ptr<Martor> martor;
public:
  ProbaMartor(const string& denumire, bool credibilitate, int relevanta,const shared_ptr<Martor>& martor);

  string descriere() const override;
  int importanta() const override;
  void validare() override;

  string get_denumire() const override {
    return "martor";
  }



};

#endif //PROBA_MARTOR_H
