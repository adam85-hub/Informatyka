#pragma once

#include <windows.h>

void setcolors(int kolortla, int kolortekstu)
{
    int atrybut=kolortla*16+kolortekstu;
    SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE ),atrybut);
}

enum class Colors
{
    black,
    darkblue,
    green,
    lightblue,
    darkred,
    purple,
    golden,
    lightgray,
    darkgray,
    blue,
    lightgreen,
    cyan,
    red,
    violet,
    ivory,
    white
};

struct TerminalColor {
    Colors Foreground;
    Colors Background;

    TerminalColor(Colors foreground = Colors::white, Colors background = Colors::black) {
        Foreground = foreground;
        Background = background;
    }

    void set() const {
        setcolors((int)Background, (int)Foreground);
    }

    static void reset() {
        TerminalColor().set();
    }    
};