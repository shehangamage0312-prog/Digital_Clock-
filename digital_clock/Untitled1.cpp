#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

// Digits 0-9 and colon (as 10)
char d0[5][3] = {{178, 178, 178},
                 {178, ' ', 178},
                 {178, ' ', 178},
                 {178, ' ', 178},
                 {178, 178, 178}};

char d1[5][3] = {{' ', ' ', 178},
                 {' ', ' ', 178},
                 {' ', ' ', 178},
                 {' ', ' ', 178},
                 {' ', ' ', 178}};

char d2[5][3] = {{178, 178, 178},
                 {' ', ' ', 178},
                 {178, 178, 178},
                 {178, ' ', ' '},
                 {178, 178, 178}};

char d3[5][3] = {{178, 178, 178},
                 {' ', ' ', 178},
                 {178, 178, 178},
                 {' ', ' ', 178},
                 {178, 178, 178}};

char d4[5][3] = {{178, ' ', 178},
                 {178, ' ', 178},
                 {178, 178, 178},
                 {' ', ' ', 178},
                 {' ', ' ', 178}};

char d5[5][3] = {{178, 178, 178},
                 {178, ' ', ' '},
                 {178, 178, 178},
                 {' ', ' ', 178},
                 {178, 178, 178}};

char d6[5][3] = {{178, 178, 178},
                 {178, ' ', ' '},
                 {178, 178, 178},
                 {178, ' ', 178},
                 {178, 178, 178}};

char d7[5][3] = {{178, 178, 178},
                 {' ', ' ', 178},
                 {' ', ' ', 178},
                 {' ', ' ', 178},
                 {' ', ' ', 178}};

char d8[5][3] = {{178, 178, 178},
                 {178, ' ', 178},
                 {178, 178, 178},
                 {178, ' ', 178},
                 {178, 178, 178}};

char d9[5][3] = {{178, 178, 178},
                 {178, ' ', 178},
                 {178, 178, 178},
                 {' ', ' ', 178},
                 {178, 178, 178}};

char d10[5][3] = {{' ', ' ', ' '},
                  {' ', 178, ' '},
                  {' ', ' ', ' '},
                  {' ', 178, ' '},
                  {' ', ' ', ' '}};

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y) {
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size) {
    if (size == 0) size = 20;

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void printDigit(int no, int x, int y) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            gotoxy(x + j, y + i);
            switch (no) {
                case 0: cout << d0[i][j]; break;
                case 1: cout << d1[i][j]; break;
                case 2: cout << d2[i][j]; break;
                case 3: cout << d3[i][j]; break;
                case 4: cout << d4[i][j]; break;
                case 5: cout << d5[i][j]; break;
                case 6: cout << d6[i][j]; break;
                case 7: cout << d7[i][j]; break;
                case 8: cout << d8[i][j]; break;
                case 9: cout << d9[i][j]; break;
                case 10: cout << d10[i][j]; break;
            }
        }
    }
}

void drawBorder(int x = 0, int y = 0) {
    char v = 186;  // vertical
    char h = 205;  // horizontal
    char tr = 187;
    char br = 188;
    char tl = 201;
    char bl = 200;
    int width = 50;
    int height = 11;

    gotoxy((width / 2) + x - 11, y);
    cout << "C U R R E N T  T I M E";

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            gotoxy(j + x, i + y);
            if (i == 1 && j == 1) cout << tl;
            else if (i == height && j == 1) cout << bl;
            else if (i == 1 && j == width) cout << tr;
            else if (i == height && j == width) cout << br;
            else if (i == 1 || i == height) cout << h;
            else if (j == 1 || j == width) cout << v;
        }
    }
}

int main() {
    system("cls");
    setcursor(0, 0);

    time_t now;
    tm *ltm;
    int hour, min, sec;
    int gap = 5;
    int posX;
    int posY = 8;

    while (1) {
        now = time(0);
        ltm = localtime(&now);
        hour = ltm->tm_hour;
        min = ltm->tm_min;
        sec = ltm->tm_sec;

        system("cls");
        drawBorder(9, 4);

        posX = 15;

        if (kbhit()) {
            char ch = getch();
            if (ch == 27) break;  // ESC key
        }

        // Print hour
        if (hour < 10) {
            printDigit(0, posX, posY);
            printDigit(hour, posX += gap, posY);
        } else {
            printDigit(hour / 10, posX, posY);
            printDigit(hour % 10, posX += gap, posY);
        }

        // Colon
        printDigit(10, posX += gap, posY);

        // Print minutes
        if (min < 10) {
            printDigit(0, posX += gap, posY);
            printDigit(min, posX += gap, posY);
        } else {
            printDigit(min / 10, posX += gap, posY);
            printDigit(min % 10, posX += gap, posY);
        }

        // Colon
        printDigit(10, posX += gap, posY);

        // Print seconds
        if (sec < 10) {
            printDigit(0, posX += gap, posY);
            printDigit(sec, posX += gap, posY);
        } else {
            printDigit(sec / 10, posX += gap, posY);
            printDigit(sec % 10, posX += gap, posY);
        }

        Sleep(950);
    }

    return 0;
}

