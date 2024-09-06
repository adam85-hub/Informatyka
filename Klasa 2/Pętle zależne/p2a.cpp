#include <iostream>
#include <windows.h>                // podac nowa biblioteke
using namespace std;

void gotoxy(int x, int y)
{
    COORD kursor;
    kursor.X = x-1;
    kursor.Y = y-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),kursor);
}


main()
{
    int px = 30; // wspó³rzêdne œrodka
    int py = 5;
    int n = 30; // wysokoœæ piramidy

    if(px<n) {
        cout << "Piramida wyjdzie poza ekran" << endl;
        return 0;
    }

    for(int i = 0; i < n; i++) {
        gotoxy(px - i, py + i);
        for(int j = 0; j < 2*i+1; j++) {
            cout << "*";
        }
    }
}
