#ifndef STRATEGIE_EMOTIONANTA_H
#define STRATEGIE_EMOTIONANTA_H

#include "strategie.h"
class StrategieEmotionanta : public Strategie {
public:
    string oferaSfat(const Acuzat &acuzat, const ListaElemente<Proba> &probe, const Judecator &judecator, const Proces &tip) override;
};

#endif //STRATEGIE_EMOTIONANTA_H
