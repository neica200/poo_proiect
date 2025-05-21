#ifndef PROCES_H
#define PROCES_H

enum class TipProces {
    Penal,Civil
};

class Proces {
    TipProces tip;
    public:
    Proces(TipProces tip);
    [[nodiscard]] TipProces getTip() const {
        return tip;
    };
};



#endif //PROCES_H
