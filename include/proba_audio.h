#ifndef PROBA_AUDIO_H
#define PROBA_AUDIO_H

#include "proba.h"

class ProbaAudio : public Proba {
private:
    int durata;
    int claritate;
public:
    ProbaAudio( const string& denumire, int durata, int claritate);

    void descriere() const override;
    int importanta() const override;
    void validare() override;

    int getDurata() const;
    int getClaritate() const;
};

#endif //PROBA_AUDIO_H
