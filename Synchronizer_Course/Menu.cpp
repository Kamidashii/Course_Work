#include "stdafx.h"
#include "Menu.h"


Menu::Menu(std::string path,std::string pathto)
{
	this->file.SetPath(path);
	this->fileto.SetPath(pathto);
}


Menu::~Menu()
{
}
std::string Menu::SetPath()
{
	std::string path, pathto;
	std::cout << "Enter path and new path" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, path);
	std::getline(std::cin, pathto);
	file.SetPath(path);
	fileto.SetPath(pathto);
	return this->Check();
}
std::string Menu::Check()
{
	_finddatai64_t data;
	_finddatai64_t datato;
	intptr_t ptr = _findfirsti64((file.getPath()).c_str(), &data);
	intptr_t ptrto = _findfirsti64((fileto.getPath()).c_str(), &datato);
	if (ptr == -1 && ptrto == -1)
	{
		_findclose(ptr);
		_findclose(ptrto);
		return "Both paths do not exist";
	}
	else if (ptr == -1)
	{
		_findclose(ptr);
		_findclose(ptrto);
		return "Original path does not exist";
	}
	else if (ptrto == -1)
	{
		_findclose(ptr);
		_findclose(ptrto);
		return "Copy path does not exist";
	}
	else
		return "Paths exist";
}