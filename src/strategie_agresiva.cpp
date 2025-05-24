#include "strategie_agresiva.h"

#include <sstream>

string StrategieAgresiva::oferaSfat(const Acuzat &acuzat, const ListaElemente<Proba> &probe, const Judecator &judecator, const Proces &tip) {
    ostringstream sfat;
    sfat << "Strategie Agresiva:\n";

    if (acuzat.esteVinovat()) {
        sfat << "- Recomanda recunoașterea partiala și justificarea contextului.\n";
    } else {
        sfat << "- Neaga orice acuzație și ataca argumentele acuzatorului direct.\n";
    }

    if(acuzat.getVarsta() < 30 && !acuzat.esteVinovat()) {
        sfat << "-Scoate in evidenta tineretea si lipsa antecedentelor. \n";
    }

    if(probe.size()>2) {
        sfat<<"- Adu în discuție fiecare proba, inclusiv pe cele mai slabe, pentru a destabiliza cazul acuzării.\n";

    }

    for(const auto &proba : probe) {
        if(!proba->esteValida()) {
            sfat<<"- Contestă validitatea probei \"" << proba->descriere() << "\".\n";
        }
        else if (proba->importanta() > 7) {
            sfat << "- Contraargumentează proba importantă: \"" << proba->descriere() << "\".\n";
        }
    }

    if(judecator.getStil() =="Sever") {
        sfat<<"- Atenție: stilul sever al judecătorului impune o abordare atentă.\n";
    }

    if (tip.getTip() == TipProces::Penal)
        sfat << "- Insistă pe lipsa de dovezi clare și pe nevinovăția prezumată.\n";

    return sfat.str();
}

void StrategieAgresiva::seteazaScoruri(std::map<std::string, int>& actiuni,
                                          const Acuzat& acuzat,
                                          const ListaElemente<Proba>& probe,
                                          const Judecator& judecator,
                                          const Proces& tip) {
    if (!acuzat.esteVinovat()) {
        actiuni["Pledeaza nevinovat"] += 2;
        actiuni["Incearca sa empatizezi cu judecatorul fiind cooperant si sincer"] += 3;
        actiuni["Recunoaste partial si justifica contextul"]-=2;
    }
    else {
        actiuni["Recunoaste partial si justifica contextul"]+=2;
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

void StrategieAgresiva::aplicaActiune(string& optiune) {
    Proces::setScor(actiuniDisponibile[optiune]);
}

