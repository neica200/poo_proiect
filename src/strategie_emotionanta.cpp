#include "strategie_emotionanta.h"
#include <sstream>

string StrategieEmotionanta::oferaSfat(const Acuzat &acuzat, const ListaElemente<Proba> &probe, const Judecator &judecator, const Proces &tip) {
    ostringstream sfat;
    sfat<<"Strategie emotionanta:";

    if (!acuzat.esteVinovat()) {
        sfat << "- Evidentiaza nevinovatia acuzatului prin apel emotional.\n";
    }

    for (const auto& proba : probe) {
        if (proba->get_denumire() == "martor" && proba->importanta() > 5 && proba->esteValida()) {
            sfat << "- Foloseste martorii pentru a sustine caracterul și circumstantele umane.\n";
            break;
        }
    }

    if(acuzat.getVarsta() < 25 || acuzat.getVarsta() >60)
        sfat<<"- Argumenteaza tinerețea sau varsta inaintata pentru a genera empatie.\n ";

    if (judecator.getStil() == "Empatic")
        sfat << "- Mizeaza pe empatia judecatorului cu povesti personale.\n";

    if (tip.getTip() == TipProces::Civil) {
        sfat << "- Fiind un proces civil, poti apela la convingerea morala mai mult decât la fapte rigide.\n";
    }

    if (judecator.getStil() == "Echilibrat")
        sfat << "- Mizeaza pe cooperare și sinceritate.\n";

    return sfat.str();
}

void StrategieEmotionanta::seteazaScoruri(std::map<std::string, int>& actiuni,
                                          const Acuzat& acuzat,
                                          const ListaElemente<Proba>& probe,
                                          const Judecator& judecator,
                                          const Proces& tip) {
    if (!acuzat.esteVinovat()) {
        actiuni["Pledeaza nevinovat"] += 1;
        actiuni["Incearca sa empatizezi cu judecatorul fiind cooperant si sincer"] += 1;
        actiuni["Recunoaste partial si justifica contextul"]-=3;
    }
    else {
        actiuni["Recunoaste partial si justifica contextul"]+=1;
        actiuni["Pledeaza nevinovat"] -=2;
        actiuni["Incearca sa empatizezi cu judecatorul fiind cooperant si sincer"] -=3;
    }

    for (const auto& proba : probe) {
        if (proba->get_denumire() == "martor" && proba->importanta() > 5 && proba->esteValida()) {
            actiuni["Cheama un martor din partea ta"] += 2;
            actiuni["Incearca sa empatizezi cu judecatorul fiind cooperant si sincer"] += 1;
        }
        else {
            actiuni["Cheama un martor din partea ta"] -=3;
        }

        if(proba->importanta() > 5 && proba->esteValida())
            actiuni["Contesta validitatea probelor"] -=3;
        else
            actiuni["Contesta validitatea probelor"] +=2;
    }



    if (acuzat.getVarsta() < 25 || acuzat.getVarsta() > 60) {
        actiuni["Vorbeste despre varsta si lipsa antecedentelor"] +=1;
    }
    else {
        actiuni["Vorbeste despre varsta si lipsa antecedentelor"] -=2;
    }

    if(acuzat.getVarsta() <18)
        actiuni["Vorbeste despre lipsa de discernamant"] +=3;
    else
        actiuni["Vorbeste despre lipsa de discernamant"] -=2;


    if (judecator.getStil() == "Empatic") {
        actiuni["Incearca sa empatizezi cu judecatorul fiind cooperant si sincer"] += 3;
    } else if (judecator.getStil() == "Echilibrat") {
        actiuni["Incearca sa empatizezi cu judecatorul fiind cooperant si sincer"] += 2;
    }

    if(judecator.getVarsta() < 5) {
        actiuni["Incearca sa manipulezi judecatorul"] +=3;
    }
    else {
        actiuni["Incearca sa manipulezi judecatorul"] -=2;
    }

    if (tip.getTip() == TipProces::Civil) {
        actiuni["Recunoaste partial si justifica contextul"] += 2;
        actiuni["Incearca sa empatizezi cu judecatorul fiind cooperant si sincer"] += 1;
    }
}

void StrategieEmotionanta::aplicaActiune(string& optiune) {
    Proces::setScor(actiuniDisponibile[optiune]);
}