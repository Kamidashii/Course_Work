#include "stdafx.h"
#include "ReDir.h"

void ReDir::_Rerecurse(FileorDirectory&syn)
{
	if (syn.isFile(syn))
	{
		remove((syn.getPath()).c_str());
		return;
	}
	std::unique_ptr<Smart_Desc>hFile(new Smart_Desc(_findfirsti64((syn.getPath() + "\\" + "*").c_str(), &syn.GetData())));
	if (!hFile)
	{
		std::cout << "Copy directory is empty! There is nothing to delete." << std::endl;
		return;
	}
	do
	{
		if (strcmp(syn.GetData().name, "..") != 0 && strcmp(syn.GetData().name, ".") != 0)
		{
			FileorDirectory tmp(syn.getPath() + "\\" + syn.GetData().name);
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
					std::cout << error.what() << errno << std::endl;
				}
			}
		}
	} while (_findnexti64(*hFile, &syn.GetData()) == 0);
	_findclose(*hFile);
}


