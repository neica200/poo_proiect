#include "judecator_echilibrat.h"
#include <iostream>
using namespace std;

JudecatorEchilibrat::JudecatorEchilibrat(const string &nume, int varsta, const string &ocupatie, int aniExp, Specializare spec) :
Judecator(nume, varsta, "Judecator", aniExp, spec){}

void JudecatorEchilibrat::analizeazaProbe() const {
    cout<<"Judecatorul echilibrat analizeaza probele cu mare atentie,e impartial.\n";
    //implementeaza formula de verificat probe mai tarziu
}

void JudecatorEchilibrat::audiazaMartori() const {
    cout<<"Judecatorul sever audiaza martorul neutru.\n";
    //implementeaza formula de audiat martori mai tarziu
}

string JudecatorEchilibrat::getStil() const {
    return "Echilibrat";
}






