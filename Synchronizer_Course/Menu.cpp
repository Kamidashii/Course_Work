#include "stdafx.h"
#include "Menu.h"

namespace SynSpace
{
	Menu::Menu(const std::string& path, const std::string& pathto)
	{
		this->file.SetPath(path);
		this->fileto.SetPath(pathto);
	}

	std::string Menu::SetPath()
	{
		std::string path, pathto;
		std::cout << "Enter new original path and new copy path" << std::endl;
		std::cin.ignore();
		std::getline(std::cin, path);
		std::getline(std::cin, pathto);
		file.SetPath(path);
		fileto.SetPath(pathto);
		return this->Check();
	}
	std::string Menu::Check()
	{
		std::unique_ptr<Smart_Desc> ptr(new Smart_Desc(_findfirsti64((file.GetPath()).c_str(), &file.GetData())));
		std::unique_ptr<Smart_Desc> ptrto(new Smart_Desc(_findfirsti64((fileto.GetPath()).c_str(), &fileto.GetData())));
		if (!*ptr && !*ptrto)
		{
			return "Both paths do not exist";
		}
		else if (!*ptr)
		{
			return "Original path does not exist";
		}
		else if (!*ptrto)
		{
			return "Copy path does not exist";
		}
		else
			return "Paths exist";
	}
}