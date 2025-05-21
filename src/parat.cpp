#include "parat.h"
#include <iostream>
using namespace std;

Parat::Parat(const string &nume, int varsta, const string &ocupatie, const string &acuzatie, bool vinovatie) : Acuzat(nume,varsta,ocupatie,acuzatie,vinovatie){
}

void Parat::reactioneazaLaSentinta() const {
    cout<<"Paratul"<<getNume()<<" primeste sentinta: "<< getSentinta();
}
