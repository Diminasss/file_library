#include "filelib.h"
#include <exception>


const char* FileNotFoundError::what() const noexcept {
    return "���� �� ����������";
}

const char* FileCanNotBeOpenError::what() const noexcept {
	return "���� �� ����� ���� ������";
}