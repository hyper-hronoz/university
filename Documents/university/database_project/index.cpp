#include<iostream>
#include<math.h>

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#elif defined(__linux__)
#include <sys/ioctl.h>
#endif // Windows/Linux

using namespace std;

void getTerminalSize(int& width, int& height) {
#if defined(_WIN32)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = (int)(csbi.srWindow.Right-csbi.srWindow.Left+1);
    height = (int)(csbi.srWindow.Bottom-csbi.srWindow.Top+1);
#elif defined(__linux__)
    struct winsize w;
    ioctl(fileno(stdout), TIOCGWINSZ, &w);
    width = (int)(w.ws_col);
    height = (int)(w.ws_row);
#endif // Windows/Linux
}

void clear() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

int width=211, height=6;

void updateView() {
    // getTerminalSize(width, height);

    // cout << width << " " << height;

    // this is just creating of empty markup matrix
    char *markup = new char[height * width];

    // lets fill up this "matrix"
    for (int i = 0; i < width * height; i++) {
        char symbol = *" ";
        if (i <= width || width * (height - 1) <= i) {
            symbol = *"-";
        }
        if ((i + 1) % width == 0 || (i + 1) % width == 1) {
            symbol = *"|";
        }
        markup[i] = symbol;
    }


    cout << markup;
    clear();
    updateView();
}

#include <iostream>
using namespace std;
int main() {
    // and we will user this matrix for changes observing
    updateView();
    getchar();
    return 0;
}
