#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n;
	cout << "Program sprawdza czy podana liczba jest pierwsza." << endl;
	cout << "Podaj liczbe: ";
	cin >> n;

	if (n <= 1) {
		cout << "Podales niepoprawna liczbe" << endl;
		return 0;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			cout << "Liczba nie jest pierwsza" << endl;			
			return 0;	
		}
	}

	cout << "Liczba jest pierwsza." << endl;
	return 0;
}