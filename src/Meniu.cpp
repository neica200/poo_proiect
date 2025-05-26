#include "judecator_empatic.h"
#include "judecator_sever.h"
#include "judecator_echilibrat.h"
#include "meniu_singleton.h"
#include "proba_audio.h"
#include "proba_document.h"
#include "proces.h"
#include <algorithm>

#include "strategie_agresiva.h"
#include "strategie_echilibrata.h"
#include "strategie_emotionanta.h"

Meniu &Meniu::getInstance() {
    static Meniu instance;
    return instance;
}

void Meniu::afiseazaMeniu() const {
    cout<<"1. Creeaza proces manual \n";
    cout<<"2. Creeaza proces random\n";
    cout<<"0. Iesire \n";
}

void Meniu::creeazaProcesManual() {
    cout<<"\n--- CREARE MANUALA PROCES ---\n";
    TipProces tip;
    while(true) {
        cout<<"Tip proces (0 - Civil, 1 - Penal)\n";
        int tipInt;
        cin>>tipInt;
        if(!cin.fail() && (tipInt == 0 || tipInt == 1)) {
            tip = static_cast<TipProces>(tipInt);
            break;
        }
        cout<<"Valoare invalida, incearca din nou.\n";
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }

    cout<<"\nIntrodu datele acuzatului:\n ";
    Acuzat acuzat1;
    while(true) {
        cin>>acuzat1;
        if(!cin.fail()) break;
        cout<<"Valoare invalida, incearca din nou.\n";
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }

    cout<<"\nIntrodu stilul judecatorului(0 - Sever, 1 - Empatic, 2 - Echilibrat)\n";
    int tipIntJ;
    cin>>tipIntJ;
    cout<<"Introdu datele judecatorului\n";
    JudecatorEchilibrat judecator_echilibrat;
    JudecatorSever judecator_sever;
    JudecatorEmpatic judecator_empatic;
    switch(tipIntJ) {
        case 0:
        while(true) {
            cin >> judecator_sever;
            if(!cin.fail()) break;
            cout<<"Valoare invalida, incearca din nou.\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        break;
        case 1:
        while(true) {
            cin >> judecator_echilibrat;
            if(!cin.fail()) break;
            cout<<"Valoare invalida, incearca din nou.\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        break;
        case 2:
        while(true) {
            cin >> judecator_empatic;
            if(!cin.fail()) break;
            cout<<"Valoare invalida, incearca din nou.\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        break;
    }

    cout<<"\nIntrodu datele avocatului:\n";
    Avocat avocat1;
    while(true) {
        cin>>avocat1;
        if(!cin.fail()) break;
        cout<<"Valoare invalida, incearca din nou.\n";
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }
    int j;
    cout<<"Ce strategie vrei sa foloseasca?(0 - Agresiva, 1 - Echilibrata, 2 - Empatica)\n";
    cin>>j;
    switch(j) {
        case 0:
            avocat1.seteazaStrategie(make_shared<StrategieAgresiva>());
        break;
        case 1:
            avocat1.seteazaStrategie(make_shared<StrategieEchilibrata>());
        break;
        case 2:
            avocat1.seteazaStrategie(make_shared<StrategieEmotionanta>());
        break;
    }

    cout<<"\n Introdu numarul de probe:\n";
    int i;
    cin>>i;
    ListaElemente<Proba> probe;
    while(i) {

        cout<<"Ce tip de proba?(0-Audio,1-Document)\n";
        int tipInt;
        cin>>tipInt;
        if(!cin.fail()) {
            if(tipInt == 0) {
                i--;
                string descriere;
                cout<<"Descriere: ";
                getline(cin,descriere);
                int claritate;
                cout<<"Claritate: ";
                cin>>claritate;
                int durata;
                cout<<"Durata: ";
                cin>>durata;
                probe.adauga(make_shared<ProbaAudio>(descriere,durata,claritate));
                continue;
            }
            else if(tipInt == 1) {
                i--;
                string descriere;
                cout<<"Descriere: ";
                getline(cin,descriere);
                string tipDoc;
                cout<<"Tip document: ";
                getline(cin,tipDoc);
                probe.adauga(make_shared<ProbaDocument>(descriere,tipDoc));
                continue;
            }
            cout<<"Valoare invalida, incearca din nou";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
   DateProces dp;
    if (tipIntJ == 0)
        dp = ProcesFactory::creeazaProcesManual(tip,acuzat1,make_shared<JudecatorSever>(judecator_sever),probe,avocat1);
    else if(tipIntJ == 1)
        dp = ProcesFactory::creeazaProcesManual(tip,acuzat1,make_shared<JudecatorEchilibrat>(judecator_echilibrat),probe,avocat1);
    else
        dp = ProcesFactory::creeazaProcesManual(tip,acuzat1,make_shared<JudecatorEmpatic>(judecator_empatic),probe,avocat1);

    cout<<"\n Proces creat cu succes! Start: \n ";
    cout<<"\n--- PROCES ---\n";
    cout<<"Procesul a inceput! Participanti:\n Avocat: ";
    dp.avocat->afiseazaProfil();
    cout<<"\n Acuzat: ";
    dp.proces->getAcuzat().afiseazaProfil();
    cout<<"\n Judecator: ";
    dp.proces->getJudecator().afiseazaProfil();
    ruleazaTurnBased(dp);

}

void Meniu::creeazaProcesRandom() {
    cout << "\n--- CREARE RANDOM PROCES ---\n";
    ProcesFactory factory;

    DateProces dp = factory.creeazaProcesRandom();

    cout<<"\n Proces creat cu succes! Start: \n";
    cout<<"\n--- PROCES ---\n";
    cout<<"Procesul a inceput! Participanti:\n Avocat: ";
    dp.avocat->afiseazaProfil();
    cout<<"\n Acuzat: ";
    dp.proces->getAcuzat().afiseazaProfil();
    cout<<"\n Judecator: ";
    dp.proces->getJudecator().afiseazaProfil();
    ruleazaTurnBased(dp);

}

void Meniu::vizualizeazaProbe(const ListaElemente<Proba> &probe) const {
    if (probe.size() == 0) {
        cout << "Nu există probe în proces.\n";
        return;
    }

    std::vector<std::shared_ptr<Proba>> temp;
    for (int i = 0; i < probe.size(); ++i)
        temp.push_back(probe.getElement(i));

    // Sortare cu lambda după importanță
    sort(temp.begin(), temp.end(),
              [](const std::shared_ptr<Proba>& a, const std::shared_ptr<Proba>& b) {
                  return a->importanta() > b->importanta();
              });

    cout << "\nProbe sortate după importanta:\n";
    for (size_t i = 0; i < temp.size(); ++i) {
        cout << "[" << i << "] ";
        cout<<temp[i]->descriere();
        std::cout << "\n";
    }
}

void Meniu::ruleazaTurnBased(DateProces dp) {
    while(true) {
        cout<<"\n--- PROCES ---\n";
        string sfat;
        try {
            sfat = dp.avocat->oferaSfat(dp.proces->getAcuzat(),dp.proces->getProbe(),dp.proces->getJudecator(),*(dp.proces));
        }catch(...) {
            sfat = "Niciun sfat disponibil";
        }
        cout<<"\n Sfatul avocatului: \n"<<sfat<<"\n\n";

        cout<<"Optiuni: \n";
        cout << "1. Aplica actiune\n";
        cout << "2. Vezi probe sortate dupa importanta\n";
        cout << "0. Termina procesul\n";
        cout << "Alege optiunea: ";

        int alegere;
        cin>>alegere;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Input invalid, reluare tura.";
            continue;
        }
        if(alegere == 0) {
            if(dp.proces->getScor()<10) {
                dp.proces->getAcuzat().seteazaSentinta("Vinovat");
                cout<<"Ai fost gasit: "<<dp.proces->getAcuzat().getSentinta();
                cout<<"\n";

            } else {
                cout<<"Ai fost gasit nevinovat";
                dp.avocat->castigaProces();
                dp.proces->getAcuzat().seteazaSentinta("Nevinovat");
                cout<<"Ai fost gasit: "<<dp.proces->getAcuzat().getSentinta();
                cout<<"Un nou proces castigat pentru avocat: "<<dp.avocat->getCazuriCastigate();
                cout<<"\n";

            }
            dp.proces->resetProces();
            break;
        }

        if(alegere == 2) {
            vizualizeazaProbe(dp.proces->getProbe());
            continue;
        }

        Strategie::getActiuniDisponibile();
        cout<<"0. Renunta la actiune\n";
        cout<<"Alege actiunea: ";

        cin>>alegere;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Input invalid, reluare tura.";
            continue;
        }
        if(alegere == 0) continue;
        vector<string> actiuni = {"Recunoaste partial si justifica contextul",
            "Pledeaza nevinovat",
            "Contesta validitatea probelor",
            "Contesta validitatea martorilor",
            "Vorbeste despre varsta si lipsa antecedentelor",
            "Vorbeste despre lipsa de discernamant",
            "Incearca sa manipulezi judecatorul",
            "Incearca sa empatizezi cu judecatorul fiind cooperant si sincer",
            "Cheama un martor din partea ta"};

        map <string,int> actiuniMap =dp.avocat->getStrategie()->paseazaActiuni() ;
        dp.avocat->seteazaScoruri(actiuniMap,dp.proces->getAcuzat(),dp.proces->getProbe(),dp.proces->getJudecator(),*(dp.proces));

        dp.avocat ->aplicaActiune(actiuni[alegere-1]);
        if(alegere==3) dp.proces->getJudecator().analizeazaProbe();
        if(alegere == 4 || alegere == 9) dp.proces->getJudecator().audiazaMartori();
    }
    }




void Meniu::ruleazaMeniu() {
    bool ruleaza = true;
    while(ruleaza) {
        afiseazaMeniu();
        int optiune;
        cout<<"\n Alege optiune: ";
        cin>>optiune;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input invalid. Încearcă din nou.\n";
            continue;
        }
        switch (optiune) {
            case 1:
                creeazaProcesManual();
            break;
            case 2:
                creeazaProcesRandom();
            break;
            case 0:
                ruleaza = false;
            break;

        }
    }

}


