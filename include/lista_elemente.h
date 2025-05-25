#ifndef LISTA_ELEMENTE_H
#define LISTA_ELEMENTE_H

#include <vector>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <random>
#include <limits>

using namespace std;

template <typename T>
class ListaElemente {
private:
    vector<shared_ptr<T>> elemente;
public:
    ListaElemente() = default;

    void adauga(shared_ptr<T> element) {
        elemente.push_back(element);
    }
    ListaElemente<T>& operator+=(std::shared_ptr<T> element) {
        elemente.push_back(element);
        return *this;  // ca să permiti concatenarea
    }


    shared_ptr<T> getElement(int index) const {
        if(index < 0 || index >= static_cast<int>(elemente.size())) {
            throw out_of_range("Index invalid în ListaElemente");
        }
        return elemente[index];
    }
    [[nodiscard]] int size() const {
        return static_cast<int>(elemente.size());
    }

    shared_ptr<T> alegeRandom() {
        if(elemente.size() == 0)
            return nullptr;

        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, elemente.size() - 1);

        int i = dis(gen);
        auto element = elemente[i];
        elemente.erase(elemente.begin() + i);
        return element;
    }

    auto begin(){return elemente.begin();}
    auto begin() const {return elemente.begin();}
    auto end(){return elemente.end();}
    auto end() const {return elemente.end();}
};

#endif //LISTA_ELEMENTE_H
