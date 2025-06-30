#include "filelib.h"
#include <exception>


const char* FileNotFoundError::what() const noexcept {
    return "Файл не существует";
}

const char* FileCanNotBeOpenError::what() const noexcept {
	return "Файл не может быть открыт";
}