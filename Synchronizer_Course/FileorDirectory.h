#pragma once
#include"stdafx.h"
class FileorDirectory 
{ 
protected:
	std::string path;// Поле для хранения

public:
	FileorDirectory(std::string path) :path(path) {}//Конструктор по умолчанию, принимает путь к файлу считывания и к файлу записи. Записывает их в специальные поля
	std::string list();

	bool isDirectory(FileorDirectory&file) const 
	{
		_finddata_t data;
		intptr_t hFile = _findfirst((file.path).c_str(), &data);
		if (hFile == -1) return false;//Если файл не найден возвращает ложь
		return data.attrib & _A_SUBDIR;//Если атрибут файла _A_SUBDIR(тоесть это папка) возвращает правду
	}
	bool isFile(FileorDirectory&file) const 
	{
		_finddata_t data;
		intptr_t hFile = _findfirst((file.path).c_str(), &data);
		if (hFile == -1) return false;//Если файл не найден возвращает ложь
		return !(data.attrib & _A_SUBDIR);//Если атрибут файла не _A_SUBDIR(тоесть это не папка) возвращает правду 
	}
	
	std::string getName() const 
	{
		_finddatai64_t data;
		intptr_t hFile = _findfirsti64((this->path).c_str(), &data);
		if (hFile == -1) return false;
		return data.name;//Возвращает имя файла
	}
	std::string getPath() 
	{
		return this->path;//Возвращает введенный путь
	}
};

