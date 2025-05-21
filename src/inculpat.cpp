#include "inculpat.h"
#include <iostream>
using namespace std;

Inculpat::Inculpat(const string &nume, int varsta, const string &ocupatie, const string &acuzatie, bool vinovatie) : Acuzat(nume,varsta,ocupatie,acuzatie,vinovatie){
}

void Inculpat::reactioneazaLaSentinta() const {
    cout<<"Inculpatul"<<getNume()<<" primeste sentinta: "<< getSentinta();
}



