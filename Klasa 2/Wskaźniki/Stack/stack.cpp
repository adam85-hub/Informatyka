#include <iostream>
using namespace std;

template<typename T>
struct Brick {
    T value;
    Brick* previous;
    Brick() {previous = nullptr;}
};

template<typename T>
class Stack {
    Brick<T>* top;
public:
    Stack() {
        top = new Brick<T>;
    }

    ~Stack() {
        this->clear();
        delete top;
    }

    void push(T value) {
        Brick<T>* newBrick = new Brick<T>;
        newBrick->value = value;
        newBrick->previous = top;
        top = newBrick;
    }

    T pop() {
        auto toDel = top;
        T v = top->value;
        top = top->previous;
        delete toDel;
        return v;
    }

    void clear() {
        while(hasElements()) {
            this->pop();
        }
    }

    bool hasElements() {
        return top->previous != nullptr;
    }
};

int main() {
    Stack<string> s;

    for(int i = 0; i < 3; i++) {
        string a;
        cin >> a;
        s.push(a);
    }

    cout << "##########" << endl;

    while(s.hasElements()) {
        cout << s.pop() << endl;
    }
}
