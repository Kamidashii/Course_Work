#pragma once
#include "FileorDirectory.h"
#include"Checking.h"
class Synchronizer :
	public FileorDirectory
{
	using FileorDirectory::FileorDirectory;
public:
	bool _Syn(Synchronizer &, Synchronizer&);
	bool Syn(Synchronizer&fileto)
	{
		if (this->path == fileto.path)
		{
			std::cout << "Copy path and original path are the same" << std::endl;
			return true;
		}
		return _Syn(*this, fileto);
	}
};

