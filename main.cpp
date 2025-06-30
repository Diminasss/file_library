#include <iostream>
#include "lib/filelib.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    std::string locked_path = "examples/locked.txt";
    std::string not_a_file_path = "examples";
    std::string fake_path = "examples/exampl.txt";
    std::string read_true_path = "examples/example_read.txt";
    std::string write_true_path = "examples/example_write.txt";


    // Открытие несуществующего файла
    try {
        File file(fake_path);
    } 
    catch (const FileNotFoundError& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    // Открытие заблокированного файла
    try {
        File file(locked_path);
    }
    catch (const FileCanNotBeOpenError& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Открытие папки в качестве файла
    try {
        File file(not_a_file_path);
    }
    catch (const NotAFileError& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Открытие файла и чтение
    try {
        File file(read_true_path);
        // Файл read_true_path содержит 3 строки
        /*
        Должны вывестись строки:
        Файл успешно открыт
        Прочитана строка: Тестовая строка 1
        Прочитана строка: Тестовая строка 2
        Прочитана строка: Тестовая строка 3
        Прочитана строка:
        Прочитана строка:
        */
        std::cout << "Файл успешно открыт" << std::endl;
        std::cout << "Прочитана строка: " << file.readLine() << std::endl;
        std::cout << "Прочитана строка: " << file.readLine() << std::endl;
        std::cout << "Прочитана строка: " << file.readLine() << std::endl;
        std::cout << "Прочитана строка: " << file.readLine() << std::endl;
        std::cout << "Прочитана строка: " << file.readLine() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << '\n';
    }

    // Запись в файл
    /*
    В файле examples/example_write.txt появятся стрки
    Строка 1
    Строка 2
    Строка 3
    Строка 4
    Строка 5
    Строка 6
    */
    try {
        File file(write_true_path);
        file.writeLine("Строка 1");
        file.writeLine("Строка 2");
        file.writeLine("Строка 3");
        // Проверка строк
        file.goToBegin();
        for (int x = 0; x < 3; x++) {
            std::cout << "Проверка строк " << file.readLine() << std::endl;
        }
        // Запись в файл после goToBegin
        file.goToBegin();
        file.writeLine("Строка 4");
        file.writeLine("Строка 5");
        file.writeLine("Строка 6");
        // Строки должны записываться в конец файла
    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << '\n';
    }
    std::cout << "Нажмите Enter для выхода...";
    std::cin.get();
    return 0;
}