#pragma once
#include"Copying.h"
#include "FileorDirectory.h"
#include"Synchronizer.h"
#include"Checking.h"
class Copying;
class Synchronizer :
	public FileorDirectory
{
	using FileorDirectory::FileorDirectory;
	bool _Syn(Synchronizer &, Synchronizer&,Copying&,int);
	long long& Fullsize(Synchronizer&,long long&);
	bool Filesize(Synchronizer&)
	{
		if (isFile(*this))
		{
			_finddatai64_t data;
			intptr_t hFile = _findfirsti64((this->path).c_str(), &data);
			this->DirSize = data.size;
			return true;
		}
		else
			return false;
	}
protected:
	long long DirSize=0;//Full size of original Directory or file
public:
	Synchronizer(std::string path):FileorDirectory(path)
	{
		
	}
	bool Syn(Synchronizer&fileto)
	{
		long long tmp = 0;
		long long &linktmp=tmp;
		if (!(Filesize(*this)))
			Fullsize(*this,linktmp);
		DirSize = linktmp;
		SizeHelper();
		int percent = 0;
		Copying copyobj;
		if (this->path == fileto.path)
		{
			std::cout << "Copy path and original path are the same" << std::endl;
			return true;
		}
		return _Syn(*this, fileto,copyobj,percent);
	}
	void SizeHelper()
	{
		long Understandble = DirSize / 1024 / 1024;
		if (Understandble / 1024 > 1)
		{
			Understandble /= 1024;
			std::cout << "Synchronizing was started\n Full size of copying directory " << Understandble << " GBytes" << std::endl;
		}
		else
		{
			std::cout << "Synchronizing was started\n Full size of copying directory " << Understandble << " MBytes" << std::endl;
		}
	}
};

