#pragma once
#include"stdafx.h"
#include"FileorDirectory.h"
#include<iostream>
#include<string>
#include<fstream>
#include<direct.h>
#include<io.h>
class SynSpace::FileorDirectory;
namespace SynSpace
{
	class Copying
	{
		Copying(const Copying&) = delete;
		Copying(Copying&) = delete;
		Copying& operator =(const Copying&) = delete;
		Copying& operator =(Copying&) = delete;
		long long Progress = 0;//Copying progress in bytes
	public:
		Copying() = default;
		~Copying() = default;
		bool FileCopy(const FileorDirectory&, const FileorDirectory& pathto, long long);//file directory metod
		void DirCopy(std::string path)//directory copying metod 
		{
			auto a = _mkdir(path.c_str());
			if (a&&errno != 17)
			{
				throw SynSpace::ErrSyn("Error remove directory ");
			}
		}
		long long CopyProgress(long long fullsize, long long work)//conside copying progress in percents metod
		{
			if (fullsize == 0)
			{
				std::cout << "Empty original file" << std::endl;
				return 0;
			}
			this->Progress += work;
			if (Progress == 0)
				return 0;
			return(Progress * 100 / fullsize);
		}

	};
}
