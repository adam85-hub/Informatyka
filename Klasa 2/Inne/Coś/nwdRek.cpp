#include <iostream>
#include <string>

using namespace std;

int nwd(int a, int b) {
    if(b == 0) return a;
    return nwd(b, a%b);
}

class String : public string {
public:
    void operator[](string a) {
        cout << a;
    }
};

int main()
{
    cout << nwd(15, 20) <<  endl;
    String test;
    test["sdfdsf"];
    return 0;
}
