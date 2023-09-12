#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;
void cursorBlink()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
void gotoxy(short int x, short int y) {	
    COORD pos = { x, y };						     
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleCursorPosition(output, pos);           
}

constexpr int area_SIZE = 16;
bool isRunning = true;

void printMap(int arr[area_SIZE])
{
    cout << "\n\n\t_________________________________________________\n";
    cout << "\t|           |           |           |           |\n";
    cout << "\t|           |           |           |           |\n";
    cout << "\t|     " << arr[0] << "     |     " << arr[1] << "     |     " << arr[2] << "     |     " << arr[3] << "     |\n";
    cout << "\t|           |           |           |           |\n";
    cout << "\t|___________|___________|___________|___________|\n";
    cout << "\t|           |           |           |           |\n";
    cout << "\t|           |           |           |           |\n";
    cout << "\t|     " << arr[4] << "     |     " << arr[5] << "     |     " << arr[6] << "     |     " << arr[7] << "     |\n";
    cout << "\t|           |           |           |           |\n";
    cout << "\t|___________|___________|___________|___________|\n";
    cout << "\t|           |           |           |           |\n";
    cout << "\t|           |           |           |           |\n";
    cout << "\t|     " << arr[8] << "     |     " << arr[9] << "     |     " << arr[10] << "     |     " << arr[11] << "     |\n";
    cout << "\t|           |           |           |           |\n";
    cout << "\t|___________|___________|___________|___________|\n";
    cout << "\t|           |           |           |           |\n";
    cout << "\t|           |           |           |           |\n";
    cout << "\t|     " << arr[12] << "     |     " << arr[13] << "     |     " << arr[14] << "     |     " << arr[15] << "     |\n";
    cout << "\t|           |           |           |           |\n";
    cout << "\t|___________|___________|___________|___________|\n\n\n";
}

int main()
{
    int arr[area_SIZE]{ 0 };
    cursorBlink();

    while (isRunning)
    {
       
        printMap(arr);
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            std::cout << "Up arrow key pressed!" << std::endl;
            Sleep(300);
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            std::cout << "Down arrow key pressed!" << std::endl;
            Sleep(300);
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            std::cout << "Left arrow key pressed!" << std::endl;
            Sleep(300);
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            std::cout << "Right arrow key pressed!" << std::endl;
            Sleep(300);
        }
        gotoxy(0, 0);
    }

    return 0;
}
