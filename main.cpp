#include "meniu_singleton.h"
int main() {
    auto &x = Meniu::getInstance();
    x.ruleazaMeniu();
    return 0;
}
