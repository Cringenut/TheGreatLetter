#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <conio.h>

using namespace std;

void StopGame()
{
    system("cls");
    cout << "The end!";
}

void hideConsoleCursor()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

class menu
{
public:

    menu();

    char currentLetterSymbol = '!';

    int currentColorIndex = 7;
    string letterColors[16] =
    {
            "None",
            "Blue",
            "Green",
            "Cyan",
            "Red",
            "Purple",
            "Yellow_dark",
            "White",
            "Grey",
            "Blue_bright",
            "Green_bright",
            "Cyan_bright",
            "Red_bright",
            "Pink",
            "Yellow",
            "White_brigth" };

    int currentWindowWidth = 60;
    int currentWindowHeight = 20;

    int currentLetterWidth = 4;
    int currentLetterHeight = 3;

    int counter = 0;

    void startGame();
    void drawMenu();
    void drawOptions();

};

menu::menu()
{
    drawMenu();
}

void menu::drawMenu()
{
    int colors[3] = { 12, 7, 7 };
    counter = 0;

    while (true)
    {
        system("cls");

        gotoxy(10, 5);
        color(colors[0]);
        cout << "Start";

        gotoxy(10, 6);
        color(colors[1]);
        cout << "Options";

        gotoxy(10, 7);
        color(colors[2]);
        cout << "Exit";

        gotoxy(10, 10);
        color(15);
        cout << "Window width: " << currentWindowWidth;

        gotoxy(10, 11);
        color(15);
        cout << "Window height: " << currentWindowHeight;

        gotoxy(10, 12);
        color(15);
        cout << "Letter color: ";
        gotoxy(24, 12);
        color(currentColorIndex);
        cout << letterColors[currentColorIndex];

        gotoxy(10, 13);
        color(15);
        cout << "Letter symbol: " << currentLetterSymbol;

        gotoxy(10, 14);
        color(15);
        cout << "Letter width: " << currentLetterWidth;

        gotoxy(10, 15);
        color(15);
        cout << "Letter low point height: " << currentLetterHeight;

        char key = _getch();

        if (key == 72 && counter > 0)
        {
            colors[counter] = 7;
            counter--;
            colors[counter] = 12;
        }

        if (key == 80 && counter < 2)
        {
            colors[counter] = 7;
            counter++;
            colors[counter] = 12;
        }

        if (key == '\r')
        {
            switch (counter)
            {
            case 0:
            {
                startGame();
                return;
            }
            case 1:
            {
                drawOptions();
                return;
            }
            case 2:
            {
                StopGame();
                return;
            }
            }
        }
    }
}

void menu::drawOptions()
{
    system("cls");
    counter = 0;
    bool selected = false;

    int colors[7] = { 12, 7, 7, 7, 7, 7, 7 };
    int SecondaryColors[7] = { 7, 7, 7, 7, 7, 7, 7 };

    while (true)
    {
        system("cls");

        gotoxy(10, 5);
        color(colors[0]);
        cout << "Back";

        gotoxy(10, 7);
        color(colors[1]);
        cout << "Window width: ";
        gotoxy(23, 7);
        color(SecondaryColors[1]);
        cout << currentWindowWidth;


        gotoxy(10, 8);
        color(colors[2]);
        cout << "Window height: ";
        gotoxy(24, 8);
        color(SecondaryColors[2]);
        cout << currentWindowHeight;


        gotoxy(10, 9);
        color(colors[3]);
        cout << "Letter color: ";
        gotoxy(24, 9);
        color(currentColorIndex);
        cout << letterColors[currentColorIndex];

        gotoxy(10, 10);
        color(colors[4]);
        cout << "Letter symbol: ";
        color(SecondaryColors[4]);
        gotoxy(24, 10);
        cout << currentLetterSymbol;

        gotoxy(10, 11);
        color(colors[5]);
        cout << "Letter width: ";
        gotoxy(24, 11);
        color(SecondaryColors[5]);
        cout << currentLetterWidth;

        gotoxy(10, 12);
        color(colors[6]);
        cout << "Letter low point height: ";
        gotoxy(35, 12);
        color(SecondaryColors[6]);
        cout << currentLetterHeight;

        char key = _getch();

        if (counter == 4 && selected && key >= 33 && key <= 126)
        {
            currentLetterSymbol = char(key);
        }
        if (key == 72 && counter > 0 && !selected)
        {
            colors[counter] = 7;
            counter--;
            colors[counter] = 12;
        }
        else if (key == 72 && selected)
        {
            switch (counter)
            {
            case 1:
            {
                ++currentWindowWidth;

                break;
            }
            case 2:
            {
                ++currentWindowHeight;

                break;
            }
            case 3:
            {
                if (currentColorIndex < 15)
                {
                    ++currentColorIndex;
                }

                break;
            }
            case 5:
            {
                ++currentLetterWidth;

                break;
            }
            case 6:
            {
                ++currentLetterHeight;

                break;
            }
            }
        }

        if (key == 80 && counter < sizeof(colors) / sizeof(colors[0]) - 1 && !selected)
        {
            colors[counter] = 7;
            counter++;
            colors[counter] = 12;
        }
        else if (key == 80 && selected)
        {
            switch (counter)
            {
            case 1:
            {
                if (currentWindowWidth > 1)
                {
                    --currentWindowWidth;
                }

                break;
            }
            case 2:
            {
                if (currentWindowHeight > 1)
                {
                    --currentWindowHeight;
                }

                break;
            }
            case 3:
            {
                if (currentColorIndex > 1)
                {
                    --currentColorIndex;
                }

                break;
            }
            case 5:
            {
                if (currentLetterWidth > 1)
                {
                    --currentLetterWidth;
                }

                break;

            }
            case 6:
            {
                if (currentLetterHeight > 1)
                {
                    --currentLetterHeight;
                }

                break;
            }

            }
        }

        if (key == '\r')
        {
            switch (counter)
            {
            case 0:
            {
                system("cls");
                drawMenu();
                return;
            }
            case 1:
            {
                if (!selected)
                {
                    colors[1] = 7;
                    SecondaryColors[1] = 12;

                    selected = true;
                }
                else
                {
                    colors[1] = 12;
                    SecondaryColors[1] = 7;

                    selected = false;
                }

                break;
            }
            case 2:
            {
                if (!selected)
                {
                    colors[2] = 7;
                    SecondaryColors[2] = 12;

                    selected = true;
                }
                else
                {
                    colors[2] = 12;
                    SecondaryColors[2] = 7;

                    selected = false;
                }

                break;
            }
            case 3:
            {
                if (!selected)
                {
                    colors[3] = 7;

                    selected = true;
                }
                else
                {
                    colors[3] = 12;

                    selected = false;
                }
                SecondaryColors[3] = currentColorIndex;

                break;
            }
            case 4:
            {
                if (!selected)
                {
                    colors[4] = 7;
                    SecondaryColors[4] = 12;


                    selected = true;
                }
                else
                {
                    colors[4] = 12;
                    SecondaryColors[4] = 7;

                    selected = false;
                }

                break;
            }
            case 5:
            {
                if (!selected)
                {
                    colors[5] = 7;
                    SecondaryColors[5] = 12;


                    selected = true;
                }
                else
                {
                    colors[5] = 12;
                    SecondaryColors[5] = 7;

                    selected = false;
                }

                break;
            }
            case 6:
            {
                if (!selected)
                {
                    colors[6] = 7;
                    SecondaryColors[6] = 12;


                    selected = true;
                }
                else
                {
                    colors[6] = 12;
                    SecondaryColors[6] = 7;

                    selected = false;
                }

                break;
            }

            }
        }
    }
}

class letter
{
public:
    letter(menu*);

    enum directions
    {
        Up,
        Down,
        Left,
        Right
    };

    COORD anchor;

    int baseColor;
    char baseSymbol;

    int windowColumns;
    int windowRows;

    int currentLetterWidth;
    int currentLetterHeight;
    int middlePointHeight;

    int originalLetterWidth;
    int originalLetterHeight;
    int originalMiddlePointHeight;

    void drawBorder();
    void drawLetter();
    void increaseLetter();
    void decreaseLetter();
    void moveLetter(directions);
};

letter::letter(menu* mainMenu)
{
    cout << "Created";
    windowRows = mainMenu->currentWindowWidth;
    windowColumns = mainMenu->currentWindowHeight;

    anchor.X = windowRows - 2;
    anchor.Y = windowColumns - 2;

    baseColor = mainMenu->currentColorIndex;
    baseSymbol = mainMenu->currentLetterSymbol;

    currentLetterWidth = mainMenu->currentLetterWidth + 2;
    currentLetterHeight = mainMenu->currentLetterHeight + ceil(float(mainMenu->currentLetterWidth) / 2) + 1;
    middlePointHeight = mainMenu->currentLetterHeight;

    originalLetterWidth = currentLetterWidth;
    originalLetterHeight = currentLetterHeight;
    originalMiddlePointHeight = middlePointHeight;

    cout << endl;
    cout << endl << ceil(float(mainMenu->currentLetterWidth) / 2) << endl;
    cout << endl << currentLetterWidth << endl;
    cout << currentLetterHeight << endl;

    while (true)
    {
        system("cls");
        color(baseColor);
        drawLetter();
        color(12);
        drawBorder();
        char key = _getch();

        switch (key)
        {
        case 27:
        {
            color(7);
            StopGame();
            return;
        }
        case 43:
        {
            increaseLetter();
            break;
        }
        case 45:
        {
            decreaseLetter();
            break;
        }
        case 72:
        {
            moveLetter(Up);
            break;
        }
        case 80:
        {
            moveLetter(Down);
            break;
        }
        case 75:
        {
            moveLetter(Left);
            break;
        }
        case 77:
        {
            moveLetter(Right);
            break;
        }
        }
    }
}

void letter::drawBorder()
{
    for (int i = 0; i < windowRows; i++)
    {
        gotoxy(i, 0);
        cout << "#";
        gotoxy(i, windowColumns - 1);
        cout << "#";
    }

    for (int i = 0; i < windowColumns; i++)
    {
        gotoxy(0, i);
        cout << "#";
        gotoxy(windowRows - 1, i);
        cout << "#";
    }
}

void letter::drawLetter()
{
    for (size_t i = 0; i < currentLetterHeight; i++)
    {
        gotoxy(anchor.X, anchor.Y - i);
        cout << baseSymbol;
        gotoxy(anchor.X - currentLetterWidth + 1, anchor.Y - i);
        cout << baseSymbol;
    }

    if (currentLetterWidth % 2 != 0)
    {
        gotoxy(anchor.X - float(currentLetterWidth / 2), anchor.Y - middlePointHeight);
        cout << baseSymbol;
        for (size_t i = 1; i < ceil(float(currentLetterWidth / 2)); i++)
        {
            gotoxy(anchor.X - float(currentLetterWidth / 2) + i, anchor.Y - middlePointHeight - i);
            cout << baseSymbol;
            gotoxy(anchor.X - float(currentLetterWidth / 2) - i, anchor.Y - middlePointHeight - i);
            cout << baseSymbol;
        }
    }
    else
    {

        for (size_t i = 1; i < currentLetterWidth / 2; i++)
        {
            gotoxy(anchor.X - currentLetterWidth / 2 + i, anchor.Y - middlePointHeight - i + 1);
            cout << baseSymbol;
            gotoxy(anchor.X - currentLetterWidth / 2 - i + 1, anchor.Y - middlePointHeight - i + 1);
            cout << baseSymbol;
        }
    }

}

void letter::increaseLetter()
{
    if (anchor.X - currentLetterWidth > 0 && anchor.Y - currentLetterHeight > 0)
    {
        ++currentLetterWidth;
        ++currentLetterHeight;
        if (currentLetterWidth % 2 == 0)
        {
            ++middlePointHeight;
        }
    }
}

void letter::decreaseLetter()
{
    if (currentLetterWidth > originalLetterWidth || currentLetterHeight > originalLetterHeight || middlePointHeight > originalMiddlePointHeight)
    {
        if (currentLetterWidth % 2 == 0)
        {
            --middlePointHeight;
        }
        --currentLetterWidth;
        --currentLetterHeight;

        return;
    }
}

void letter::moveLetter(directions currentDirection)
{
    switch (currentDirection)
    {
    case Up:
    {
        if (anchor.Y - currentLetterHeight > 0)
        {
            --anchor.Y;
        }

        break;
    }
    case Down:
    {
        if (anchor.Y < windowColumns - 2)
        {
            ++anchor.Y;
        }

        break;
    }
    case Left:
    {
        if (anchor.X - currentLetterWidth > 0)
        {
            --anchor.X;
        }

        break;
    }
    case Right:
    {
        if (anchor.X < windowRows - 2)
        {
            ++anchor.X;
        }
    }
    }
}

void menu::startGame()
{
    CONSOLE_SCREEN_BUFFER_INFOEX consolesize;

    consolesize.cbSize = sizeof(consolesize);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfoEx(hConsole, &consolesize);

    COORD c;
    c.X = currentWindowWidth;
    c.Y = currentWindowHeight;
    consolesize.dwSize = c;

    SetConsoleScreenBufferInfoEx(hConsole, &consolesize);
    system("cls");

    letter(this);
}

int main()
{
    hideConsoleCursor();
    menu MainMenu;

    return 0;
}


