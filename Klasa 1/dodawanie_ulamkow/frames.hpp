#pragma once
#include <windows.h>
#include <iostream>
#include "colors.hpp"

using namespace std;

void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
  }

int wherex()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.X;
  }

int wherey()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.Y;
  }
void frame1(int x1,int y1,int x2,int y2, string title, TerminalColor titleColor = TerminalColor())
{
  int i;
  gotoxy(x1,y1) ; cout<<char(218);
  for (i=x1+1;i<x2;i++) cout<<char(196);
  cout<<char(191);
  for(i=y1+1;i<y2;i++)
  {
      gotoxy(x1,i);cout<<char(179);
      gotoxy(x2,i);cout<<char(179);
  }
  gotoxy(x1,y2);cout<<char(192);
  for(i=x1+1;i<x2;i++) cout<<char(196);
  cout<<char(217);
  if(title!="")
  {
  int d=title.length();

  gotoxy((x2+x1)/2-d/2,y1);
  titleColor.set();
  cout<<title;
  TerminalColor::reset();
  gotoxy(x1+1,y1+1);
  }
}
void frame2(int x1,int y1,int x2,int y2, string title, TerminalColor titleColor = TerminalColor())
{
  int i;
  gotoxy(x1,y1) ; cout<<char(201);
  for (i=x1+1;i<x2;i++) cout<<char(205);
  cout<<char(187);
  for(i=y1+1;i<y2;i++)
  {
      gotoxy(x1,i);cout<<char(186);
      gotoxy(x2,i);cout<<char(186);
  }
  gotoxy(x1,y2);cout<<char(200);
  for(i=x1+1;i<x2;i++) cout<<char(205);
  cout<<char(188);
  if(title!="")
  {
  int d=title.length();

  gotoxy((x2+x1)/2-d/2,y1);
  titleColor.set();
  cout<<title;
  TerminalColor::reset();
  gotoxy(x1+1,y1+1);
  }

}

enum class FrameType
{
  normal = 1,
  doubleborder = 2
};

void frame(int x, int y, int width, int height, string title, FrameType frameType = FrameType::normal, TerminalColor titleColor = TerminalColor()) {
  int x2 = x + width;
  int y2 = y + height;

  if(frameType == FrameType::normal)
    frame1(x, y, x2, y2, title, titleColor);
  else if (frameType == FrameType::doubleborder)
    frame2(x, y, x2, y2, title, titleColor);
}