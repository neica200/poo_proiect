#include "strategie_echilibrata.h"
#include <sstream>

string StrategieEchilibrata::oferaSfat(const Acuzat &acuzat, const ListaElemente<Proba> &probe, const Judecator &judecator, const Proces &tip) {
    ostringstream sfat;
    sfat << "Strategie echilibrata:\n";

    if(acuzat.esteVinovat())
        sfat<<"- Incearca sa obtii circumstante atenunate si recunoaste partial faptele";

    int probePuternice = 0;
    for (const auto& p : probe)
        if (p->importanta() > 7) probePuternice++;

    if (probePuternice >= 2)
        sfat << "- Concentrează apărarea doar pe cele mai convingătoare probe.\n";
    else
        sfat << "- Nu sunt probe convingătoare, recomandă negocierea sau retragerea acuzării.\n";

    if (judecator.getExperienta() > 15) {
        sfat << "- Judecătorul are experiență mare: evită manipulările, bazează-te pe logică simplă.\n";
    }

    if (tip.getTip() == TipProces::Penal) {
        sfat << "- În penal trebuie siguranță, evită să aduci martori slabi sau probe îndoielnice.\n";
    }

    return sfat.str();


}

void StrategieEchilibrata::seteazaScoruri(std::map<std::string, int>& actiuni,
                                          const Acuzat& acuzat,
                                          const ListaElemente<Proba>& probe,
                                          const Judecator& judecator,
                                          const Proces& tip) {
    if (!acuzat.esteVinovat()) {
        actiuni["Pledeaza nevinovat"] += 2;
        actiuni["Incearca sa empatizezi cu judecatorul fiind cooperant si sincer"] += 1;
        actiuni["Recunoaste partial si justifica contextul"]-=3;
    }
    else {
        actiuni["Recunoaste partial si justifica contextul"]+=1;
        actiuni["Pledeaza nevinovat"] -=2;
        actiuni["Incearca sa empatizezi cu judecatorul fiind cooperant si sincer"] -=2;
    }

    for (const auto& proba : probe) {
        if (proba->get_denumire() == "martor" && proba->importanta() > 5 && proba->esteValida()) {
            actiuni["Cheama un martor din partea ta"] += 2;
            actiuni["Incearca sa empatizezi cu judecatorul fiind cooperant si sincer"] += 1;
        }
        else {
            actiuni["Cheama un martor din partea ta"] -=2;
        }

        if(proba->importanta() > 5 && proba->esteValida())
            actiuni["Contesta validitatea probelor"] -=2;
        else
            actiuni["Contesta validitatea probelor"] +=2;
    }



    if (acuzat.getVarsta() < 25 || acuzat.getVarsta() > 60) {
        actiuni["Vorbeste despre varsta si lipsa antecedentelor"] += 2;
    }
    else {
        actiuni["Vorbeste despre varsta si lipsa antecedentelor"] -=2;
    }

    if(acuzat.getVarsta() <18)
        actiuni["Vorbeste despre lipsa de discernamant"] +=2;
    else
        actiuni["Vorbeste despre lipsa de discernamant"] -=2;


    if (judecator.getStil() == "Empatic") {
        actiuni["Incearca sa empatizezi cu judecatorul fiind cooperant si sincer"] += 3;
    } else if (judecator.getStil() == "Echilibrat") {
        actiuni["Incearca sa empatizezi cu judecatorul fiind cooperant si sincer"] += 2;
    }

    if(judecator.getVarsta() < 5) {
        actiuni["Incearca sa manipulezi judecatorul"] +=2;
    }
    else {
        actiuni["Incearca sa manipulezi judecatorul"] -=3;
    }

    if (tip.getTip() == TipProces::Civil) {
        actiuni["Recunoaste partial si justifica contextul"] += 1;
        actiuni["Incearca sa empatizezi cu judecatorul fiind cooperant si sincer"] += 1;
    }
}

void StrategieEchilibrata::aplicaActiune(string& optiune) {
    Proces::setScor(actiuniDisponibile[optiune]);
}



