#pragma once
#include <string>
#include <fstream>
#include <filesystem>


namespace fs = std::filesystem;

class File {
/*
		���� ����������� ��� ������ � ������ �� ������� ������ r+ � Python.
		������� �� �������� ���:
		1. ��� ������ ��������� ������ � ��������� �� ���������
		2. ��� ������ ��������� �� ��������� ������ � ���������� ������
		3. ����� ����� ��������� �� ������ ��� ������ � ������
		4. ���� ����� �� ����������, �� ������������� ����������
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