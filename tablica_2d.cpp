#include <iostream>

using namespace std;

int main()
{
    cout<<"Program wypisuje tablice 2d wypelniona kolejnymi liczbami naturalnymi: "<<endl<<endl;
    int t[5][3];
    int k = 10;
    int suma;

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 3; j++)
        {
            k+=1;
            t[i][j] = k;
        }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout.width(3);
            cout<<t[i][j];
        }
        cout<<endl;
    }

    cout<<"-----------------------------------------------------"<<endl;

    for(int i = 0; i < 5; i++)
    {
        suma = 0;
        for(int j = 0; j < 3; j++)
        {
            suma+=t[i][j];
        }
        cout<<suma<<endl;
    }

    cout<<"-----------------------------------------------------"<<endl;

    for(int i = 0; i < 3; i++)
    {
        suma = 0;
        for(int j = 0; j < 5; j++)
        {
            suma+=t[j][i];
        }
        cout.width(3);
        cout<<suma;
    }

    cout<<endl<<"-----------------------------------------------------"<<endl;

    suma = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            suma+=t[i][j];
        }
    }

    double srednia = suma/15;
    cout<<srednia<<endl;



}
