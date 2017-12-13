#include"stdafx.h"
#include "FileorDirectory.h"



std::string FileorDirectory::list()
{
	std::string res;//Создается вектор в который будут записываться пути просканированых файлов
	_finddatai64_t data;//Создается объект структуры _finddata_t
	intptr_t hFile = _findfirsti64((path + "\\" + "*").c_str(), &data);//Открывает файл и записывает его в intptr_t указатель на структуру _finddata_t
	if (hFile == -1) return res;//Если данный файл не существует, возвращает пустой вектор
	do {
		if (strcmp(data.name, ".") == 0 || strcmp(data.name, "..") == 0)continue;//Исключает системные папки "." и ".."
		res=(path + "\\" + data.name);//Добавляет в вектор полный путь к файлу 
	} while (_findnexti64(hFile, &data) == 0);//Цикл идет пока не просканируются все файлы
	return res;//Возвращает вектор с записанными в нем полными путями файлов
}

