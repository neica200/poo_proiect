#ifndef PROCES_H
#define PROCES_H
#include <memory>
#include "acuzat.h"

#include "judecator.h"
#include "lista_elemente.h"
#include "proba.h"


enum class TipProces {
    Penal,Civil
};

class Proces {
    TipProces tip = TipProces::Civil;
    Acuzat acuzat;
   // Avocat avocat;
    shared_ptr<Judecator> judecator;
    ListaElemente<Proba> probe;
    static int scor;

public:
    explicit Proces(TipProces t = TipProces::Civil,const Acuzat& a = Acuzat(), /*const Avocat& av*/const shared_ptr<Judecator>& j = nullptr,
           const ListaElemente<Proba>& p = ListaElemente<Proba>());

    void setTipProces(TipProces tip);
    void setAcuzat(Acuzat const &a);
    //void setAvocat(const Avocat& a);
    void setJudecator(shared_ptr<Judecator> j);
    void setProbe(ListaElemente<Proba> p);
    static void setScor(int s);


    [[nodiscard]] TipProces getTip() const;
    Acuzat& getAcuzat() ;
    //Avocat& getAvocat() ;
    [[nodiscard]] const Judecator& getJudecator() const;
    [[nodiscard]] const ListaElemente<Proba>& getProbe() const;
    [[nodiscard]] int getScor() const;

    void resetProces();


};

#endif //PROCES_H
