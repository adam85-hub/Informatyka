#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    cout <<"Program generuje liczby losowe z danego przedzialu"<<endl;
    srand(time(NULL));
    int a, b;
    cout<<"Podaj a: "; cin>>a;
    cout<<"Podaj b: "; cin>>b;

    int buff;
    if(a>b) { buff = a; a = b; b = buff;}

    for(int i = 0; i < 10; i++)
    {
        cout << rand() % (b-a+1) + a << endl;
    }

    return 0;
}
