#include "stdafx.h"
#include "ReDir.h"

namespace SynSpace
{
	void ReDir::_Rerecurse(FileorDirectory&syn)
	{
		if (syn.IsFile(syn))
		{
			remove((syn.GetPath()).c_str());
			return;
		}
		std::unique_ptr<Smart_Desc>hFile(new Smart_Desc(_findfirsti64((syn.GetPath() + "\\" + "*").c_str(), &syn.GetData())));
		if (!hFile)
		{
			std::cout << "Copy directory is empty! There is nothing to delete." << std::endl;
			return;
		}
		do
		{
			if (syn.GetData().name != std::string("..") && syn.GetData().name != std::string("."))
			{
				FileorDirectory tmp(syn.GetPath() + "\\" + syn.GetData().name);
				if (tmp.isDirectory(tmp))
				{
					_Rerecurse(tmp);
					try
					{
						if (_rmdir((tmp.GetPath()).c_str()) == -1)
							throw SynSpace::ErrSyn("Error directory remove ");
					}
					catch (SynSpace::ErrSyn error)
					{
						std::cout << error.what() << errno << std::endl;
					}
				}
				else
				{
					std::cout << "Now remove " << tmp.GetPath() << std::endl;
					try
					{
						if (remove(tmp.GetPath().c_str()))
							throw SynSpace::ErrSyn("Error remove file ");
					}
					catch (SynSpace::ErrSyn error)
					{
						std::cout << error.what() << errno << std::endl;
					}
				}
			}
		} while (_findnexti64(*hFile, &syn.GetData()) == 0);
		_findclose(*hFile);
	}
}


