#include "stdafx.h"
#include "Synchronizer.h"


bool Synchronizer::_Syn(Synchronizer &file, Synchronizer&fileto)
{// Метод для рекурсивного сканирования файлов каталога принимает ссылку на объект сканирования и объект записи
	_finddatai64_t data;
	if (isFile(file))
	{
		fileto.path = fileto.path +"\\"+ file.getName();
		Checking().Check(file, fileto);
		return true;
	}
	intptr_t hFile = _findfirsti64((file.getPath() + "\\" + "*").c_str(), &data);
	if (hFile == -1)
	{
		std::cout << "Incorrect path to original file" << std::endl;
		return false;
	}
	do //Проходит по всем файлам в данной папке
	{
		if (strcmp(data.name, ".") != 0 && strcmp(data.name, "..") != 0)
		{
			Synchronizer tmp = (file.path + "\\" + data.name);
			std::cout << this->path << std::endl;
			Synchronizer tmpto = (fileto.path + "\\" + data.name);
			if (isDirectory(tmp))
			{
				Copying().DirCopy(tmpto.getPath());
				_Syn(tmp, tmpto);
			}
			else
				Checking().Check(tmp, tmpto);
		}

	} while (_findnexti64(hFile, &data) == 0);

	return true;
}