#include <iostream>
#include "lib/filelib.h" // Включение заголовочного файла с определением класса FileLib

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    File file("example.txt");
    cout << "Файл открыт";
    return 0;
}
