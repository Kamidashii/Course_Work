#pragma once
#include"stdafx.h"
#include"FileorDirectory.h"
#include<iostream>
#include<string>
#include<fstream>
#include<direct.h>
#include<io.h>
class FileorDirectory;
class Copying
{
public:
	Copying();
	~Copying();
	 bool FileCopy(FileorDirectory&, FileorDirectory& pathto);
	 void DirCopy(std::string path)
	 {
		 auto a=_mkdir(path.c_str());//Создает папку по указанному пути
		 if (a)
		 {
			 if (errno == 17)
				 std::cout << "This directory already has" << std::endl;
			 else
				 std::cout << errno << std::endl;
		 }
	 }
};

