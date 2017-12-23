#include "stdafx.h"
#include "ReDir.h"

void ReDir::_Rerecurse(FileorDirectory&syn)
{
	if (syn.isFile(syn))
	{
		remove((syn.getPath()).c_str());
		return;
	}
	_finddatai64_t data;
	intptr_t hFile = _findfirsti64((syn.getPath()+"\\"+"*").c_str(), &data);
	if (hFile == -1)
	{
		std::cout << "Empty directory" << std::endl;
		return;
	}
	do
	{
		if (strcmp(data.name, "..")!=0 && strcmp(data.name, ".")!=0)
		{
			FileorDirectory tmp(syn.getPath() + "\\" + data.name);
			if (tmp.isDirectory(tmp))
			{
				_Rerecurse(tmp);
				try
				{
					if (_rmdir((tmp.getPath()).c_str()) == -1)
						throw Err::ErrSyn("Error directory remove ");
				}
				catch (Err::ErrSyn error)
				{
					std::cout << error.what() << errno << std::endl;
				}
			}
			else 
			{
				std::cout << "Now remove " << tmp.getPath() << std::endl;
				try 
				{ 
					if (remove(tmp.getPath().c_str())) 
						throw Err::ErrSyn("Error remove file ");
				}
				catch (Err::ErrSyn error)
				{
					std::cout<<error.what() << errno<<std::endl;
				}
			}
		}
	} while (_findnexti64(hFile, &data) == 0);
	_findclose(hFile);
}


