#include "stdafx.h"
#include "Synchronizer.h"

bool Synchronizer::_Syn(Synchronizer &file, Synchronizer&fileto,Copying&copyobj,int percent)
{// Метод для рекурсивного сканирования файлов каталога принимает ссылку на объект сканирования и объект записи
	_finddatai64_t data;
	if (isFile(file))
	{
		fileto.path = fileto.path +"\\"+ file.getName();
		std::cout << "Now copying " << file.getPath() << std::endl;
		if (Checking().Check(file, fileto))
			Copying ().FileCopy(file,fileto,DirSize);
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
			Synchronizer tmpto = (fileto.path + "\\" + data.name);
			if (isDirectory(tmp))
			{
				std::cout << "Now copying " << tmp.getPath() << std::endl;
				try
				{
					Copying().DirCopy(tmpto.getPath());
				}
				catch (Err::ErrSyn error)
				{
					std::cout << error.what() << errno << std::endl;
				}
				_Syn(tmp, tmpto,copyobj,percent);
			}
			else
			{
				if (Checking().Check(tmp, tmpto))
				{
					std::cout << "Now copying " << tmp.getPath() << std::endl;
					try
					{
						copyobj.FileCopy(tmp, tmpto, DirSize);
					}
					catch (Err::ErrSyn error)
					{
						std::cout << error.what();
					}
				}
				else
				{
					int  work = copyobj.CopyProgress(DirSize, data.size);
						if (percent != work)
						{
							std::cout << work << "%\r";
							percent = work;
						}
				}
			}
		}

	} while (_findnexti64(hFile, &data) == 0);
	_findclose(hFile);
	return true;
}
long long& Synchronizer::Fullsize(Synchronizer&file,long long& amount)
{
	_finddatai64_t data;
	intptr_t hFile = _findfirsti64((file.path + "\\" + "*").c_str(), &data);
	if (hFile == -1)
	{
		return amount;
	}
	long long amounttmp = 0;
	do
	{
		if (strcmp(data.name, ".") != 0 && strcmp(data.name, "..") != 0)
		{
			Synchronizer tmp = (file.path + "\\" + data.name);
			if (isDirectory(tmp))
				Fullsize(tmp, amount);
				amount+=data.size;
		}
	} while (_findnexti64(hFile,&data)==0);
	_findclose(hFile);
	return amount;
}