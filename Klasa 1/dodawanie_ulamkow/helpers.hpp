#pragma once

#include <iostream>
#include <math.h>
#include <string>
#include <vector>

#include "frames.hpp"
#include "colors.hpp"
#include "math.hpp"

template <typename T>
void print(T msg, int x, int y, TerminalColor color) {
    gotoxy(x, y);
    color.set();
    cout << msg;
    TerminalColor::reset();
}

template <typename T>
void print(T msg, int x, int y) {
    gotoxy(x, y);
    cout << msg;
}

void clear() {
    system("cls");
}

std::string repeat(std::string toRepeat, int count) {
    std::string repeated = "";
    for (int i = 0; i < count; i++) {
        repeated += toRepeat;
    }

    return repeated;
}

class Factor {
private:
    int charsToNumber(const vector<char>& chars) {
        int number = 0;
        for (int i = chars.size()-1; i >= 0; i--) {
            number += ((int)chars[i]-48) * pow(10, (chars.size() - i - 1));
        }

        return number;
    }
public:
    int L;
    int M;
    std::vector<char> lInput;
    std::vector<char> mInput;

    Factor(int l=0, int m=0) {
        L = l;
        M = m;
    }

    int getRequiredSpace() {
        if(lInput.size() == 0 && mInput.size() == 0)
            return 1;

        return max(lInput.size(), mInput.size());
    }

    int getNumberOfDigits() {
        return max(log10(L), log10(M)) +1;
    }

    void simplify() {
        if(M == 0 || L == 0)
            return;

        int n = nwd(L, M);
        L = L / n;
        M = M / n;
    }

    std::string getL() {
        std::string toReturn = "";
        for(char digit : lInput) {
            toReturn += digit;
        }

        return toReturn;
    }

    std::string getM() {
        std::string toReturn = "";
        for(char digit : mInput) {
            toReturn += digit;
        }

        return toReturn;
    }

    void parseInputs() {
        L = charsToNumber(lInput);
        M = charsToNumber(mInput);
    }

    Factor add(const Factor& other) const {
        int m = this->M * other.M;
        int l = this->L * other.M + other.L * this->M;
        return Factor(l, m);
    }

    Factor operator+(const Factor& other) const {
        return this->add(other);
    }

    //Zwraca true kiedy jest dokładnie taki sam (bez uproszczenia)
    bool operator==(const Factor& other) const {
        return this->L == other.L && this->M == other.M;
    }

    bool operator!=(const Factor& other) const {
        return !(*this == other);
    }
};