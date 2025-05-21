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

