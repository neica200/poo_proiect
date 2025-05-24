#include "strategie.h"

map <string,int> Strategie::actiuniDisponibile = {
    {"Recunoaste partial si justifica contextul", 0},
        {"Pledeaza nevinovat", 0},
        {"Contesta validitatea probelor", 0},
        {"Contesta validitatea martorilor", 0},
        {"Vorbeste despre varsta si lipsa antecedentelor", 0},
        {"Vorbeste despre lipsa de discernamant", 0},
        {"Incearca sa manipulezi judecatorul", 0},
        {"Incearca sa empatizezi cu judecatorul fiind cooperant si sincer", 0},
        {"Cheama un martor din partea ta", 0}
};

void Strategie::getActiuniDisponibile() {
    cout << "Ce vrei sa faci:\n";
    int index = 1;
    for (const auto& [actiune, _] : Strategie::actiuniDisponibile) {
        std::cout << index++ << ". " << actiune << "\n";
    }
}




