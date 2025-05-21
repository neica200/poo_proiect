#include "judecator_empatic.h"
#include <iostream>
using namespace std;

JudecatorEmpatic::JudecatorEmpatic(const string &nume, int varsta, int aniExp, Specializare spec) :
Judecator(nume, varsta, aniExp, spec){}

void JudecatorEmpatic::analizeazaProbe() const {
    cout<<"Judecatorul empatic analizeaza probele cu mare atentie,dar cauta cauze atenunate.\n";
    //implementeaza formula de verificat probe mai tarziu
}

void JudecatorEmpatic::audiazaMartori() const {
    cout<<"Judecatorul sever audiaza martorul empatic,intelegator.\n";
    //implementeaza formula de audiat martori mai tarziu
}

string JudecatorEmpatic::getStil() const {
    return "Empatic";
}






