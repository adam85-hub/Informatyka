#include <iostream>
using namespace std;

template<typename T>
struct Brick {
    T value;
    Brick* previous;
    Brick() {previous = NULL;}
};

Brick<int>* na_stos(Brick<int>* top, int ile) {
    for(int i = 1; i <= ile; i++) {
        Brick<int>* n = new Brick<int>;
        n->value = i;
        n->previous = top;
        top = n;
    }

    return top;
}

template<typename T>
void wypisz(Brick<T>* top) {
    while(top->previous != NULL) {
        cout << top->value << ", ";
        top = top->previous;
    }
    cout << endl;
}

template<typename T>
void del(Brick<T>* top) {
    Brick<T>* buff;
    while(top != NULL) {
        buff = top->previous;
        delete top;
        top = buff;
    }
}

template<typename T>
Brick<T>* wskaz_ze_stosu(Brick<T>* top, int k) {
    for(int i = 1; i < k; i++) {
        top = top->previous;
    }
    return top;
}

template<typename T>
Brick<T>* pop_many(Brick<T>* top, int k) {
    Brick<T>* buff;
    for(int i = 0; i < k; i++) {
        buff = top->previous;
        delete top;
        top = buff;
    }

    return top;
}
template<typename T>
T pop_inside(Brick<T>* top, int k) {
    for(int i = 1; i < k-1; i++) {
        top = top->previous;
    }
    auto prev = top->previous->previous;
    T value = top->previous->value;
    delete top->previous;
    top->previous = prev;

    return value;
}

int main() {
    Brick<int>* top = new Brick<int>;
    top = na_stos(top, 10);
    wypisz(top);
    cout << "3 od gory: " << wskaz_ze_stosu(top, 3)->value << endl;
    top = pop_many(top, 3);
    cout << "po usunieciu trzech: " << top->value << endl;

    // reset stosu
    del(top);
    top = new Brick<int>;
    top = na_stos(top, 10);
    cout << "reset" << endl;
    // test wyciagania ze srodka
    int v = pop_inside(top, 5);
    cout << "po wyciagnieciu 5 od gory: ";
    wypisz(top);
    cout << "wyciagniety: " << v << endl;
    del(top);
}
