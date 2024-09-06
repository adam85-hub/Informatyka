#include <vector>
#include <iostream>
#include <random>

using namespace std;

//* Funkcje pomocnicze:

//Sprawdza czy wektor zawiera dany element
template <typename T>
bool v_contains(const vector<T>& vector, T element) {
    for(T el : vector) {
        if(element == el)
            return true;
    }

    return false;
}

template <typename T>
vector<T> v_multiply(const vector<T>& a, const vector<T>& b) {
    vector<T> result;
    for (T a_el : a) {
        for(T b_el : b) {
            if(a_el == b_el) {
                if(v_contains(result, a_el) == false) result.push_back(a_el);
            }
        }
    }

    return result;
}

template <typename T>
void printVector(const vector<T>& v, string separator) {
    for(T el : v) {
        cout << el << separator;
    }
    cout << endl;
}

void separate() {
    cout << "-----------------------------------" << endl;
}

//Wczytuje określoną ilość liczb z klawiatury (z podanego zakresu i nie akceptuje powtórzeń)
vector<int> getNumbersFromKeyboard(int len, int min, int max) {
    vector<int> numbers;
    cout << "Wypisz " << len << " liczb od " << min << " do " << max << "." << endl;
    for (int i = 0; i < len; i++) {
        int n;
        cout << "Podaj " << i+1 << " liczbe: ";
        cin >> n;
        if(n < min || n > max || v_contains(numbers, n)) {
            i--;
            cout << "Wpisana liczba jest nieprawidlowa." << endl;
        }
        else {
            numbers.push_back(n);
        }
    }

    return numbers;
}

//Generuje losowe liczby bez powtórzeń
vector<int> generateRandomNumbers(int len, int min, int max) { 
    vector<int> numbers;
    max++; // Generuje do max włącznie
    for (int i = 0; i < len; i++) {
        int n = rand()%(max-min)+min;
        if(v_contains(numbers, n)) i--;
        else numbers.push_back(n);
    }

    return numbers;
}

int getNumberFromBounds(string msg, int min, int max) {
    do {
        int input;
        cout << msg;
        cin >> input;
        if(input < min || input > max) {
            cout << "Wybrana liczba jest nieprawidlowa." << endl;
        }
        else {
            return input;
        }
    } while (true);
}

int generateLottoLikeGame(int sLen, int min, int max) {
    int tryb;
    string selectedStr;
    vector<int> selected, randomized, result;
    tryb = getNumberFromBounds("Manualnie czy na chybil-trafil (1 lub 2): ", 1, 2);
    selected = tryb == 1 ? getNumbersFromKeyboard(sLen, min, max) : generateRandomNumbers(sLen, min, max);
    separate();
    cout << "Wybrane kule: ";
    printVector(selected, " ");
    randomized = generateRandomNumbers(sLen, min, max);
    cout << "Wylosowane kule: ";
    printVector(randomized, " ");
    result = v_multiply(selected, randomized);
    cout << "Trafiles " << result.size() << " kul(e). ";
    if(result.size() > 0) {
        cout << "Byl(y/a) to: ";
        printVector(result, " ");
    }
    
    return result.size();
}

//* Koniec sekcji z funkcjami pomocniczymi