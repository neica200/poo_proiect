#include "judecator_echilibrat.h"
#include <iostream>

#include "proces.h"
using namespace std;

JudecatorEchilibrat::JudecatorEchilibrat(const string &nume, int varsta, int aniExp, Specializare spec) :
Judecator(nume, varsta, aniExp, spec){}

void JudecatorEchilibrat::analizeazaProbe() const {
    cout<<"Judecatorul echilibrat analizeaza probele cu mare atentie,e impartial.\n";

}

void JudecatorEchilibrat::audiazaMartori() const {
    cout<<"Judecatorul sever audiaza martorul neutru.\n";

}

string JudecatorEchilibrat::getStil() const {
    return "Echilibrat";
}








