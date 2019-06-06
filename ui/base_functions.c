#include "../header_interface_functions.h"

void mgotoxy (const int x, const int y) {
    COORD p={x, y};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, p);
}

void setColor (const int x) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, x);
}

void setSize (const int width, const int height) {
    if (width<15 || height<=0) {
        printf("ERRO: Tamanho invalido para janela");
        return;
    }

    char code[50], aux[10];

    strcpy(code, "MODE CON lines=");
        itoa(height, aux, 10);
    strcat (code, aux);
    strcat(code, " cols=");
        itoa(width*2, aux, 10);
    strcat(code, aux);

    system(code);
}

void screenSize (const int x, const int y) {
    COORD p={x, y};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT Rect;
        Rect.Top = 0;
        Rect.Left = 0;
        Rect.Bottom = x-1;
        Rect.Right = y-1;

    SetConsoleScreenBufferSize(hConsole, p);
    SetConsoleWindowInfo(hConsole, TRUE, &Rect);
}

void hideCursor(bool hide) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;

    info.dwSize = 100;
    info.bVisible = !hide;

    SetConsoleCursorInfo(consoleHandle, &info);
}

void presets (char title[], const int color, const int width, const int heigth, bool cursor) {
    char code[250] = "title ";

    strcat (code, title);
    system (code);

    setColor (color);
        system ("cls");
    setSize(width, heigth);

    hideCursor (cursor);
}
