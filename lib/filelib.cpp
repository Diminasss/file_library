#include "filelib.h"

File::File(const std::string& path) {

	if (!fs::exists(path)) {
		throw FileNotFoundError(); // Проверка файла на существование с выбросом исключения
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