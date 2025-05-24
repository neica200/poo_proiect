#ifndef PROCES_H
#define PROCES_H

enum class TipProces {
    Penal,Civil
};

class Proces {
    TipProces tip;
    static int scor;

public:
    Proces(TipProces tip = TipProces::Civil);
    [[nodiscard]] TipProces getTip() const;
    static void setScor(int s);
};

#endif //PROCES_H
