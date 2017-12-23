#pragma once
#include"stdafx.h"
#include"ErrSyn.h"
class FileorDirectory 
{ 
protected:
	std::string path;//directory path
	std::string list();
public:
	FileorDirectory() = default;
	FileorDirectory(std::string path) :path(path) {}

	bool isDirectory(FileorDirectory&file) const //checking, if it's directory return true
	{
		_finddatai64_t data;
		intptr_t hFile = _findfirsti64((file.path).c_str(), &data);
		if (hFile == -1)
		{
			_findclose(hFile);
			return false;
		}
		_findclose(hFile);
		return data.attrib & _A_SUBDIR;
	}
	bool isFile(FileorDirectory&file) const //checking, if it's file return true
	{
		_finddatai64_t data;
		intptr_t hFile = _findfirsti64((file.path).c_str(), &data);
		if (hFile == -1)
		{
			_findclose(hFile);
			return false;
		}
		_findclose(hFile);
		return !(data.attrib & _A_SUBDIR);
	}
	
	std::string getName() const//get name metod
	{
		_finddatai64_t data;
		intptr_t hFile = _findfirsti64((this->path).c_str(), &data);
		if (hFile == -1)
		{
			_findclose(hFile);
			return false;
		}
		_findclose(hFile);
		return data.name;
	}
	std::string getPath()//get path metod
	{
		return this->path;
	}
	void SetPath(std::string path)//set path metod
	{
		this->path = path;
	}
};

