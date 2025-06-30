#pragma once
#include <string>
#include <fstream>
#include <filesystem>


namespace fs = std::filesystem;

class File {
/*
		Файл открывается для чтения и записи по подобию режима r+ в Python.
		Поэтому он работает так:
		1. При чтении считывает строку и переходит на следующую
		2. При записи переходит на последнюю строку и производит запись
		3. Имеет общий указатель на строку для чтения и записи
		4. Если файла не существует, то выбрасывается исключение
*/
public:
	File(const std::string& path);
	~File();
private:
	std::fstream stream;
};


class FileNotFoundError : public std::exception {
public:
	const char* what() const noexcept override;
};

class FileCanNotBeOpenError : public std::exception {
public:
	const char* what() const noexcept override;
};