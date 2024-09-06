#include <iostream>
using namespace std;

template<typename T>
struct Brick {
    T value;
    Brick* previous;
    Brick() {previous = nullptr;}
};

//typedef Brick<string> test;

int main() {
    Brick<string>* top = new Brick<string>;

    for(int i = 0; i < 3; i++) {
        auto buf = new Brick<string>;
        cin >> buf->value;
        buf->previous = top;
        top = buf;
    }

    cout << "###############" << endl;

    while(top->previous != nullptr) {
        cout << top->value << endl;
        auto toDel = top;
        top = top->previous;
        delete toDel;
    }

    delete top;
}
