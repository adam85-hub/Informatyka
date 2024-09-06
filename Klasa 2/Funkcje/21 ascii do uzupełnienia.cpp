#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int y,g;

void gotoxy(int x, int y)
{
    COORD kursor;
    kursor.X = x-1;
    kursor.Y = y-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),kursor);
}


int main()
{
    for (int kod=0; kod<=255; kod++)
    {
        gotoxy(kod%24, kod/24 * 7);
        cout << (char)kod;
    }

    getch();
    return 0;
}
