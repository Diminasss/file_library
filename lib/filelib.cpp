#include "filelib.h"

File::File(const std::string& path) {

	if (!fs::exists(path)) {
		throw FileNotFoundError(); // �������� ����� �� ������������� � �������� ����������
	}

	stream.open(path, std::ios::in | std::ios::out); // �������� � ��������� ����� ��� ������ � ������

	if (!stream.is_open()) {
		throw FileCanNotBeOpenError(); // �������� ����� �� ������������� � �������� ����������
	}
}

File::~File() {
	if (stream.is_open()) {
		stream.close();
	}
}