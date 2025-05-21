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
        sfat<<"- Aduce în discuție fiecare proba, inclusiv pe cele mai slabe, pentru a destabiliza cazul acuzării.\n";

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

