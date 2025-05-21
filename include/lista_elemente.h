#ifndef LISTA_ELEMENTE_H
#define LISTA_ELEMENTE_H

#include <vector>
#include <memory>
#include <stdexcept>
#include <iostream>

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
    shared_ptr<T> getElement(int index) const {
        if(index < 0 || index >= static_cast<int>(elemente.size())) {
            throw out_of_range("Index invalid în ListaElemente");
        }
        return elemente[index];
    }
    int size() const {
        return static_cast<int>(elemente.size());
    }
    void afiseazaToate(ostream& os = cout) const {
        for(const auto& e : elemente) {
            os << *e << "\n";
        }
    }
    auto begin(){return elemente.begin();}
    auto begin() const {return elemente.begin();}
    auto end(){return elemente.end();}
    auto end() const {return elemente.end();}
};

#endif //LISTA_ELEMENTE_H
