#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <mmsystem.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <io.h>
#include <fcntl.h>
#define MAX 13

using namespace std;

void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}

void gotoxy(int x, int y)
{
    HANDLE  h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD g;
    g.X = x;
    g.Y = y;
    SetConsoleCursorPosition(h, g);
}

void textcolor(int x)
{
    HANDLE  h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

#pragma comment(lib, "winmm.lib")
int main() {
    DisableCtrButton(true, true, true);
    int n = 2023;

    string s = to_string(n);
    gotoxy(40, 12);
    for (auto c : s) {
        Sleep(300);
        cout << c;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '3') {
            s[i] = '4';
        }
    }
    system("cls");
    gotoxy(40, 12);
    cout << s[0] << s[1] << s[2];
    Sleep(1000);
    cout << s[3];
    Sleep(1500);
    int color = 1, i = 59;
    while (i--) {
        gotoxy(40, 12);
        textcolor(color);
        cout << "HAPPY NEW YEARRRR !!";
        color = (color + 1) % 10;
        Sleep(100);
    }
    textcolor(4);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"\nCHÚC MỪNG NĂM MỚI! Có thể năm nay mang lại cho bạn niềm vui, thành công và thịnh vượng. \nChúc bạn và những người thân yêu sức khỏe, hạnh phúc và vô số phước lành trong năm tới. \nChúc mừng những khởi đầu mới và một năm tuyệt vời phía trước!";
    PlaySound(TEXT(".Music\\Happy_new_year.mp3"), NULL, SND_FILENAME);
    return 0;
}
