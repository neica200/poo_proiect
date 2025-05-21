#ifndef PROBA_MARTOR_H
#define PROBA_MARTOR_H

#include <memory>

#include "martor.h"
#include "proba.h"

class ProbaMartor : public Proba {
private:
  shared_ptr<Martor> martor;
  bool credibilitate;
  int relevantaDeclaratie;
public:
  ProbaMartor(const string& denumire, bool credibilitate, int relevanta,const shared_ptr<Martor>& martor);

  void descriere() const override;
  int importanta() const override;
  void validare() override;

  bool esteCredibil() const;
  int getRelevanta() const;
  shared_ptr<Martor> getMartor() const;

};

#endif //PROBA_MARTOR_H
