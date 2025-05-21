#include "strategie_emotionanta.h"
#include <sstream>

string StrategieEmotionanta::oferaSfat(const Acuzat &acuzat, const ListaElemente<Proba> &probe, const Judecator &judecator, const Proces &tip) {
    ostringstream sfat;
    sfat<<"Strategie emotionanta:";

    if (!acuzat.esteVinovat()) {
        sfat << "- Evidențiază nevinovăția acuzatului prin apel emoțional.\n";
    }

    for (const auto& proba : probe) {
        if (proba->get_denumire() == "martor" && proba->importanta() > 5 && proba->esteValida()) {
            sfat << "- Folosește martorii pentru a susține caracterul și circumstanțele umane.\n";
        }
    }

    if(acuzat.getVarsta() < 25 || acuzat.getVarsta() >60)
        sfat<<"- Argumentează tinerețea sau vârsta înaintată pentru a genera empatie.\n ";

    if (judecator.getStil() == "Empatic")
        sfat << "- Mizează pe empatia judecătorului cu povești personale.\n";

    if (tip.getTip() == TipProces::Civil) {
        sfat << "- Fiind un proces civil, poți apela la convingerea morală mai mult decât la fapte rigide.\n";
    }

    if (judecator.getStil() == "Echilibrat")
        sfat << "- Mizează pe cooperare și sinceritate.\n";

    return sfat.str();
}
