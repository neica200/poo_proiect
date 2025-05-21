#include "judecator_sever.h"
#include <iostream>
using namespace std;

JudecatorSever::JudecatorSever(const string &nume, int varsta, int aniExp, Specializare spec) :
Judecator(nume, varsta, aniExp, spec){}

void JudecatorSever::analizeazaProbe() const {
    cout<<"Judecatorul sever analizeaza probele cu mare atentie si strictete.\n";
    //implementeaza formula de verificat probe mai tarziu
}

void JudecatorSever::audiazaMartori() const {
    cout<<"Judecatorul sever audiaza martorul agresiv,autoritar.\n";
    //implementeaza formula de audiat martori mai tarziu
}

string JudecatorSever::getStil() const {
    return "Sever";
}





