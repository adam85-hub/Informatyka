#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <random>
#include <time.h>
#include "helpers.cpp"

using namespace std;

void runSelectedGame(char);
void option(string, string);
void lotto();
void multilotek();
void jackpot();
void maly_lotek();

int main() {
    srand(time(NULL));

    do {
        system("cls");
    
        //* Wyświetlanie menu
        cout << "Menu:" << endl;
        option("1", "Lotto");
        option("2", "Multilotek");
        option("3", "Eurojackpot");
        option("4", "Maly lotek");
        option("ESC", "Wyjscie");

        char opt = getch();
        //* Uruchomienie wybranej gry
        system("cls");
        if(opt == '1')
            lotto();
        else if(opt == '2')
            multilotek();
        else if(opt == '3')
            jackpot();
        else if(opt == '4')
            maly_lotek();
        else if(opt == 27) { //* Wyjście po naciśnięciu escape
            return 0;
        }
        else { //* Jeżeli żadna z opcji nie pasuje do wybranej
            cout << "Taka opcja nie istnieje." << endl;
        }
        getch();
    } while (true);
}


void lotto() {
    cout << "Lotto:" << endl;
    generateLottoLikeGame(6, 1, 49);
}

void multilotek() {
    // Zasady gry ze strony: http://www.zasadygry.pl/multilotek_zasady_gry_6_1.htm
    const int wygrane[10][10] = { // [typowaliśmy][trafiliśmy]
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 26, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 4, 40, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 10, 330, 0, 0, 0, 0, 0},
        {0, 0, 1, 4, 60, 600, 0, 0, 0, 0},
        {0, 0, 1, 2, 10, 100, 2500, 0, 0, 0},
        {0, 0, 0, 2, 10, 30, 300, 10000, 0, 0},
        {0, 0, 0, 1, 40, 20, 150, 1000, 24000, 0},
        {0, 0, 0, 1, 2, 6, 70, 260, 5000, 100000},
    };
    int stawka, tLen, tryb;
    vector<int> selected, randomized, result;
    cout << "Multilotek:" << endl;
    stawka = getNumberFromBounds("Wybierz stawke (od 2 zl do 20 zl): ", 2, 20);
    tLen = getNumberFromBounds("Wybierz ilosc typow (od 1 do 10): ", 1, 10);
    tryb = getNumberFromBounds("Manualnie czy na chybil-trafil (1 lub 2): ", 1, 2);
    selected = tryb == 1 ? getNumbersFromKeyboard(tLen, 1, 80) : generateRandomNumbers(tLen, 1, 80);
    randomized = generateRandomNumbers(20, 1, 80);
    result = v_multiply(selected, randomized);
    separate();
    cout << "Wybrane kule: ";
    printVector(selected, " ");
    cout << "Wylosowane kule: ";
    printVector(randomized, " ");
    int score = result.size();
    cout << "Trafiles " << score << " kul(e). ";
    if(score > 0) {
        cout << "Byl(y/a) to: ";
        printVector(result, " ");
        cout << "Wygrales: " << wygrane[tLen-1][score-1] << " * " << stawka << "zl = " << stawka * wygrane[tLen-1][score-1] << "zl" << endl;
    }
}

void jackpot() {
    int tryb;
    vector<int> selected1, selected2, randomized1, randomized2, result1, result2;
    cout << "Eurojackpot:" << endl;
    tryb = getNumberFromBounds("Manualnie czy na chybil-trafil (1 lub 2): ", 1, 2);
    selected1 = tryb == 1 ? getNumbersFromKeyboard(5, 1, 50) : generateRandomNumbers(5, 1, 50);
    selected2 = tryb == 1 ? getNumbersFromKeyboard(2, 1, 10) : generateRandomNumbers(2, 1, 10);
    randomized1 = generateRandomNumbers(5, 1, 50);
    randomized2 = generateRandomNumbers(2, 1, 10);
    result1 = v_multiply(selected1, randomized1);
    result2 = v_multiply(selected2, randomized2);
    separate();
    cout << "Wybrane kule z pierwszej puli: ";
    printVector(selected1, " ");
    cout << "Wylosowane kule z pierwszej puli: ";
    printVector(randomized1, " ");
    cout << endl;
    cout << "Wybrane kule z drugiej puli: ";
    printVector(selected2, " ");
    cout << "Wylosowane kule z drugiej puli: ";
    printVector(randomized2, " ");
    cout << endl;

    cout << "Trafiles " << result1.size() << " kul(e) z pierwszej puli. ";
    if(result1.size() > 0) {
        cout << "Byl(y/a) to: ";
        printVector(result1, " ");
    } else cout << endl;
    cout << "Trafiles " << result2.size() << " kul(e) z drugiej puli. ";
    if(result2.size() > 0) {
        cout << "Byl(y/a) to: ";
        printVector(result2, " ");
    } else cout << endl;
    cout << "Twoj wynik to (" << result1.size() << " + " << result2.size() << ")" << endl;
}

void maly_lotek() {  
    cout << "Maly lotek:" << endl;
    generateLottoLikeGame(5, 1, 42);
}

void option(string pre, string suf) {
    cout << pre << " - " << suf << endl;
}