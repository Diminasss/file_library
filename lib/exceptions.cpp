#include "filelib.h"



const char* FileNotFoundError::what() const noexcept {
    return "Файл не существует";
}

const char* FileCanNotBeOpenError::what() const noexcept {
	return "Файл не может быть открыт";
}

const char* NotAFileError::what() const noexcept {
	return "Путь не является файлом";
}

const char* ReadingError::what() const noexcept {
	return "Ошибка при чтении строки из файла";
}

const char* WritingError::what() const noexcept {
	return "Ошибка при записи строки в файл";
}