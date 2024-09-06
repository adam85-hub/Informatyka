#include <iostream>
#include <vector>
#include <conio.h>
#include "helpers.hpp"

using namespace std;

const TerminalColor separatorsColor(Colors::darkgray, Colors::black);
const TerminalColor operatorsColor(Colors::lightgreen, Colors::black);
const TerminalColor digitsColor(Colors::ivory, Colors::black);

Factor f1 = Factor();
Factor f2 = Factor();
Factor fResult = Factor();
Factor fSimplified = Factor();

// Program wygląda najlepiej kiedy wysokość i szerokość ramki są parzyste
const int frameWidth = 60;
const int frameHeight = 6;
int startX = 1;
int startY = 1;

void log(string msg, TerminalColor color = separatorsColor) {
    print(msg, 0, frameHeight+1, color);
}

void printEquationTemplate(int eStartX, int eStartY) {
    int f1r = f1.getRequiredSpace();
    int f2r = f2.getRequiredSpace();
    print(repeat("-", f1r), eStartX, eStartY + 1, separatorsColor);
    print("+", eStartX + f1r + 1, eStartY + 1, operatorsColor);
    print(repeat("-", f2r), eStartX + f1r + 3, eStartY + 1, separatorsColor);
    print("=", eStartX + f1r + f2r + 4, eStartY + 1, operatorsColor);
}

void printResultTemplate(int eStartX, int eStartY) {
    int f1r = f1.getRequiredSpace();
    int f2r = f2.getRequiredSpace();
    int fRr = fResult.getNumberOfDigits();
    int fSr = fSimplified.getNumberOfDigits();
    printEquationTemplate(eStartX, eStartY);
    print(repeat("-", fRr), eStartX + f1r + f2r + 6, eStartY + 1, separatorsColor);
    if(fResult != fSimplified) 
    {
        print("=", eStartX + f1r + f2r + fRr + 7, eStartY + 1, operatorsColor);
        print(repeat("-", fSr), eStartX + f1r + f2r + fRr + 9, eStartY + 1, separatorsColor);
    }

}

void printFactor(int factorSX, int factorSY, Factor factor) {
    print(factor.getL(), factorSX, factorSY, digitsColor);
    print(factor.getM(), factorSX, factorSY + 2, digitsColor);
}

void printResultFactor(int factorSX, int factorSY, Factor factor, TerminalColor color = digitsColor) {
    print(factor.L, factorSX, factorSY, color);
    print(factor.M, factorSX, factorSY + 2, color);
}

void printFrame() {
    clear();

    TerminalColor(Colors::lightgray, Colors::black).set();
    frame(0, 0, frameWidth, frameHeight, " Dodawanie ulamkow ", FrameType::doubleborder, TerminalColor(Colors::blue, Colors::black));
    TerminalColor::reset();
    int f1r = f1.getRequiredSpace();
    int f2r = f2.getRequiredSpace();

    startY = ((frameHeight - 1) / 2);
    if(fResult.M == 0) startX = ((frameWidth - f1r - f2r - 6) / 2);

    printEquationTemplate(startX, startY);

    printFactor(startX, startY, f1);
    printFactor(startX + f1r + 3, startY, f2);
}

void printResultFrame() {
    int f1r = f1.getRequiredSpace();
    int f2r = f2.getRequiredSpace();

    if(fResult != fSimplified) startX = ((frameWidth - (f1r + f2r + fResult.getNumberOfDigits() + fSimplified.getNumberOfDigits() + 9)) / 2);
    else startX = ((frameWidth - (f1r + f2r + fResult.getNumberOfDigits() + 9)) / 2);

    printFrame();

    printResultTemplate(startX, startY);

    TerminalColor resultColor = TerminalColor(digitsColor);
    if(fResult == fSimplified) resultColor = TerminalColor(Colors::red, Colors::black);

    printResultFactor(startX + f1r + f2r + 6, startY, fResult, resultColor);
    if(fResult != fSimplified) printResultFactor(startX + f1r + f2r + fResult.getNumberOfDigits() + 9, startY, fSimplified, TerminalColor(Colors::red, Colors::black));
}

void getNumber(int numberSX, int numberSY, vector<char>& input) {
     do {
        gotoxy(input.size() + numberSX, numberSY);
        char ch = getch();
        bool invalidChar = false;
        if(ch == 13) // Enter
            break;
        else if (ch == 27){ // Escape
            clear();
            exit(0);
        }
        else if(ch == 8 && input.size() != 0) //Usuwanie znaków i zabezpieczenie przed usuwanie z pustej tablicy
            input.pop_back();
        else if (ch == 48 && input.size() == 0) //Zabezpieczenie przed wpisanie zera jako pierwsze
            invalidChar = true;
        else if(ch >= 48 && ch <=57) //Przyjmuje tylko cyfry
            input.push_back(ch);
        else
            invalidChar = true;          

        printFrame();

        if(invalidChar == true) log("Wprowadzono nieprawidlowy znak!", TerminalColor(Colors::black, Colors::red));
    } while (true);
}

int main() {
    printFrame();

    getNumber(startX, startY, f1.lInput);
    getNumber(startX, startY+2, f1.mInput);
    getNumber(startX + f1.getRequiredSpace() + 3, startY, f2.lInput);
    getNumber(startX + f1.getRequiredSpace() + 3, startY + 2, f2.mInput);

    clear();

    f1.parseInputs();
    f2.parseInputs();
    fResult = f1 + f2;
    fSimplified = Factor(fResult);
    fSimplified.simplify();

    printResultFrame();

    gotoxy(0, frameHeight+1);
    getch();
    clear();
}