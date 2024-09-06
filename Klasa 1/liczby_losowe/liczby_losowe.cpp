#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    cout <<"Program generuje liczby losowe"<<endl;
    srand(time(NULL));

    for(int i = 0; i < 10; i++)
    {
        cout << rand() << endl;
    }

    return 0;
}
