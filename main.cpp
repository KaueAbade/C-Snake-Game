#include "menu.h"
#include "output.h"

#include <windows.h>

int main()
{
    //Deixa o cursor do CMD invisivel
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = false;

    SetConsoleCursorInfo(hOut, &cursorInfo);

    //Muda a fonte do CMD para a fonte "L"Terminal"", a unica fonte quadrada do Windows
    CONSOLE_FONT_INFOEX cFont;

    cFont.cbSize = sizeof cFont;
    cFont.dwFontSize.X = 12;
    cFont.dwFontSize.Y = 16;
    wcscpy_s(cFont.FaceName, L"Terminal");

    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cFont);

    //Muda a posicao da tela do CMD e esconde a barra de scroll
    MoveWindow(GetConsoleWindow(),320,180,600,500,TRUE);
    ShowScrollBar(GetConsoleWindow(), SB_BOTH, FALSE);

    tutorial(); //Função de Menu
    menu(); //Função de Menu

    return 0;
}
