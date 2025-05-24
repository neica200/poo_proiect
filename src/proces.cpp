#include "proces.h"

int Proces::scor = 0;
Proces::Proces(TipProces tip) :tip(tip){}
TipProces Proces::getTip() const {
    return tip;
}
void Proces::setScor(int s) {
    scor+=s;
}
