#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

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
        gotoxy((kod/25)*7+1, kod%25+1);
        cout<<kod<<": "<<(char)kod;
    }

    getch();
    return 0;
}
