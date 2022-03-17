#include "Console.h"

void gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x * 2;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

void setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setConsoleView()
{
	system("mode con:cols=40 lines=40");
	system("title SHOOTING GAME #2");
}

void clrscr()
{
	system("cls");
}

void beep(int tone, int delay)
{
	Beep(tone, delay);
}

int getKeyDown()
{
	if (_kbhit() != 0)
		return _getch();

	return 0;
}