#include "stdafx.h"
#include "Synchronizer.h"

bool Synchronizer::Syn(Synchronizer&fileto)
{
	long long tmp = 0;
	long long &linktmp = tmp;
	if (!(Filesize(*this)))
		Fullsize(*this, linktmp);
	this->DirSize = linktmp;
	SizeHelper();
	int percent = 0;
	Copying copyobj;
	if (this->path == fileto.path)
	{
		std::cout << "Copy path and original path are the same" << std::endl;
		return true;
	}
	return _Syn(*this, fileto, copyobj, percent);
}
bool Synchronizer::Filesize(Synchronizer&)//file size metod
{
	if (isFile(*this))
	{
		_finddatai64_t data;
		intptr_t hFile = _findfirsti64((this->path).c_str(), &data);
		this->DirSize = data.size;
		_findclose(hFile);
		return true;
	}
	return false;
}
void Synchronizer::SizeHelper()
{
	long double Understandble = DirSize;
	if (Understandble > 1024)
	{
		Understandble /= 1024;
		if (Understandble > 1024)
		{
			Understandble /= 1024;
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
		else
			std::cout << "Synchronizing was started\n Full size of copying directory " << Understandble << " KBytes" << std::endl;
	}
	else
		std::cout << "Synchronizing was started\n Full size of copying directory " << Understandble << " Bytes" << std::endl;
}
bool Synchronizer::_Syn(Synchronizer &file, Synchronizer&fileto,Copying&copyobj,int percent)
{
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
		throw Err::ErrSyn((file.getPath()).c_str());
		return false;
	}
	do 
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