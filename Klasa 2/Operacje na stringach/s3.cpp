#include <iostream>

using namespace std;

struct Test {
    void operator[](string x) {
        cout << x << endl;
    }

};

bool x(string a) {
    cout << a;
    return 0;
}

int main()
{
    Test t = Test();
    t["test"];
    false&&x("1");
    true&&x("2");
    return 0;

    string a;
    cout << "Podaj string: ";
    getline(cin, a);
    int c = 0;
    for(int i = 1; i < a.size(); i++) {
        if((a[i-1] == ' ' && a[i] != ' ') || (i == 1 && a[i-1] != ' ')) {
            c++;
        }
    }
    cout << c;
    return 0;
}
