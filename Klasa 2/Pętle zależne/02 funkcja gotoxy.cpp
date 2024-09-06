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
    gotoxy (10,2);
    cout <<'x';
    Sleep(1000);
}
