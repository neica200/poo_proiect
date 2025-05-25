#include "proces_factory.h"

#include "judecator_empatic.h"
#include "judecator_sever.h"
#include "proba_audio.h"
#include "proba_document.h"
#include "proba_martor.h"
#include "strategie_agresiva.h"
#include "strategie_echilibrata.h"
#include "strategie_emotionanta.h"

ListaElemente<Acuzat>    ProcesFactory::acuzatiDisponibili;
ListaElemente<Avocat>    ProcesFactory::avocatiDisponibili;
ListaElemente<Judecator> ProcesFactory::judecatoriDisponibili;
ListaElemente<Martor>    ProcesFactory::martoriDisponibili;
ListaElemente<Proba>     ProcesFactory::probeDisponibile;
ListaElemente<Strategie> ProcesFactory::strategiiDisponibile;

ProcesFactory::ProcesFactory() {
    acuzatiDisponibili+=make_shared<Acuzat>("Miruna Bombo",30,"It-ist","Evaziune fiscala",true);
    acuzatiDisponibili+=make_shared<Acuzat>("Melysa", 16,"Elev","Furt",false);
    acuzatiDisponibili+=make_shared<Acuzat>("Rares Hriscu",20,"Student","Intrare prin efractie",true);
    acuzatiDisponibili += make_shared<Acuzat>("Ion Popescu", 45, "Muncitor", "Furt calificat", false);
    acuzatiDisponibili += make_shared<Acuzat>("Elena Vasile", 28, "Contabila", "Frauda", true);
    acuzatiDisponibili += make_shared<Acuzat>("Mihai Georgescu", 33, "Sofer", "Lovire", false);
    acuzatiDisponibili += make_shared<Acuzat>("Ana Marin", 19, "Studentă", "Vătămare corporală", true);
    acuzatiDisponibili += make_shared<Acuzat>("Mihai Pop", 16, "Elev", "Furt", false);
    acuzatiDisponibili += make_shared<Acuzat>("Ana Georgescu", 17, "Studentă", "Vătămare corporală", true);


    avocatiDisponibili+=make_shared<Avocat>("Teodora Maria",25,5);
    avocatiDisponibili += make_shared<Avocat>("Andrei Ionescu", 38, 10);
    avocatiDisponibili += make_shared<Avocat>("Maria Stan", 30, 7);
    avocatiDisponibili += make_shared<Avocat>("Florin Dinu", 42, 12);
    avocatiDisponibili += make_shared<Avocat>("Raluca Tamas", 29, 4);

    judecatoriDisponibili+=make_shared<JudecatorSever>("Darius Beldi",40,10,Specializare::Civil);
    judecatoriDisponibili+=make_shared<JudecatorEchilibrat>("Andreea Popa", 35,5,Specializare::Penal);
    judecatoriDisponibili+=make_shared<JudecatorEmpatic>("David Lapusneanu", 50,15,Specializare::Penal);
    judecatoriDisponibili += make_shared<JudecatorSever>("Gheorghe Mihai", 55, 20, Specializare::Civil);
    judecatoriDisponibili += make_shared<JudecatorEmpatic>("Claudia Neagu", 44, 15, Specializare::Penal);
    judecatoriDisponibili += make_shared<JudecatorEchilibrat>("Victor Stan", 50, 18, Specializare::Civil);
    judecatoriDisponibili += make_shared<JudecatorSever>("Cristina Iliescu", 48, 22, Specializare::Penal);

    martoriDisponibili+= make_shared<Martor>("Andreea Capitanu",26,"Profesoara","Eram langa acuzat la momentul comiterii infractiunii",1,ParteSustinuta::Acuzat);
    martoriDisponibili += make_shared<Martor>("George Florescu", 34, "Șofer taxi", "Am văzut totul de la geam", 1, ParteSustinuta::Acuzat);
    martoriDisponibili += make_shared<Martor>("Livia Petrescu", 40, "Farmacistă", "Eram la farmacie când s-a întâmplat", 0, ParteSustinuta::Reclamant);
    martoriDisponibili += make_shared<Martor>("Alexandru Moldovan", 29, "Vânzător", "Am auzit țipetele", 1, ParteSustinuta::Reclamant);
    martoriDisponibili += make_shared<Martor>("Simona Iancu", 37, "Educatoare", "Era foarte nervos înainte de incident", 0, ParteSustinuta::Acuzat);

    probeDisponibile+=make_shared<ProbaMartor>("Declaratie Martor",true,5,martoriDisponibili.getElement(0));
    probeDisponibile += make_shared<ProbaMartor>("Declarație martor taxi", true, 6, martoriDisponibili.getElement(1));
    probeDisponibile += make_shared<ProbaMartor>("Declarație martor farmacie", false, 5, martoriDisponibili.getElement(2));
    probeDisponibile += make_shared<ProbaMartor>("Declarație martor vânzător", true, 7, martoriDisponibili.getElement(3));
    probeDisponibile += make_shared<ProbaMartor>("Declarație martor educatoare", true, 4, martoriDisponibili.getElement(4));

    probeDisponibile += make_shared<ProbaAudio>("Înregistrare telefon", 120, 9);
    probeDisponibile += make_shared<ProbaAudio>("Înregistrare interfon", 45, 6);
    probeDisponibile+=make_shared<ProbaAudio>("Inregistrare",60,7);

    probeDisponibile+=make_shared<ProbaDocument>("Contract de vanzare-cumparare","contract");
    probeDisponibile += make_shared<ProbaDocument>("Certificat de naștere", "document oficial");
    probeDisponibile += make_shared<ProbaDocument>("Contract de închiriere", "contract");
    probeDisponibile += make_shared<ProbaDocument>("Raport expertiză", "expertiză");
    probeDisponibile += make_shared<ProbaDocument>("Proces verbal", "document oficial");
    probeDisponibile += make_shared<ProbaDocument>("Factura", "factura");

    strategiiDisponibile +=make_shared<StrategieAgresiva>();
    strategiiDisponibile+=make_shared<StrategieEchilibrata>();
    strategiiDisponibile+=make_shared<StrategieEmotionanta>();

}


DateProces ProcesFactory::creeazaProcesManual(TipProces tip, Acuzat acuzat, shared_ptr<Judecator> judecator, ListaElemente<Proba> probe, Avocat avocat) {
    auto proces = make_shared<Proces>();
    proces->setTipProces(tip);
    proces->setAcuzat(acuzat);
    proces->setJudecator(judecator);
    proces->setProbe(probe);




    return {proces, make_shared<Avocat>(avocat)};
}

DateProces ProcesFactory::creeazaProcesRandom() {
    auto acuzatp = acuzatiDisponibili.alegeRandom();
    const Acuzat& acuzat = *acuzatp;
    auto judecatorp = judecatoriDisponibili.alegeRandom();
    auto avocatp = avocatiDisponibili.alegeRandom();
    auto strategiep = strategiiDisponibile.alegeRandom();
    TipProces tip = TipProces::Penal;
    ListaElemente<Proba> probe;
    avocatp->seteazaStrategie(strategiep);
    int nrProbe = rand() % 3 + 1;
    for (int i = 0; i < nrProbe; i++) {
        auto proba = probeDisponibile.alegeRandom();
        probe+=proba;
    }
    auto procesp = make_shared<Proces>(tip,acuzat,judecatorp,probe);
    return {procesp,avocatp};
}

