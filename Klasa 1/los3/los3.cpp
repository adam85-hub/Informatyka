#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int a, b, n;
    double srednia;
    cout<<"Program oblicza srednia z n liczb z przedzialu <a, b>"<<endl;
    cout<<"Podaj n: "; cin>>n;
    cout<<"Podaj a: "; cin>>a;
    cout<<"Podaj b: "; cin>>b;
    srand(time(NULL));

    if(a>b) swap(a, b);

    double liczby[n];

    for(int i = 0; i < n; i++)
    {
        liczby[i] = rand()%(b-a+1)+a;
    }

    srednia = 0;
    for(int i = 0; i < n; i++)
    {
        srednia += liczby[i];
    }
    cout<<"Srednia wylosowanych liczb: "<<srednia/n<<endl;

    return 0;
}
