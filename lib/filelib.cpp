#include "filelib.h"


File::File(const std::string& path) {

	if (!fs::exists(path)) {
		throw FileNotFoundError(); // Проверка файла на существование с выбросом исключения
	}

	if (!fs::is_regular_file(path)) {
		throw NotAFileError(); // Проверка пути на то, является ли он файлом
	}

	stream.open(path, std::ios::in | std::ios::out); // Открытие и удержание файла для чтения и записи

	if (!stream.is_open()) {
		throw FileCanNotBeOpenError(); // Проверка файла на открываемость с выбросом исключения
	}
}

File::~File() {
	if (stream.is_open()) {
		stream.close();
	}
}

std::string File::readLine() {
	std::string line;
	if (!std::getline(stream, line)) {
		if (stream.eof()) {
			return "";
		}
		throw ReadingError(); // Ошибка чтения
	}
	return line;
}

void File::writeLine(const std::string& line) {
	stream.clear();
	stream.seekp(0, std::ios::end);
	stream.seekg(0, std::ios::end);
	stream << line << std::endl;
	if (stream.fail()) {
		throw WritingError(); // Ошибка записи
	}
}

void File::goToBegin() {
	// Чтение (нет смысла передвигать указатель записи, так как запись доступна только в конец)
	stream.seekg(0); 
}
