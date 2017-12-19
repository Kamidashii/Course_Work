#pragma once
#include"stdafx.h"
#include"ErrSyn.h"
class FileorDirectory 
{ 
protected:
	std::string path;// ���� ��� ��������
	std::string list();
public:
	FileorDirectory(std::string path) :path(path) {}//����������� �� ���������, ��������� ���� � ����� ���������� � � ����� ������. ���������� �� � ����������� ����

	bool isDirectory(FileorDirectory&file) const 
	{
		_finddatai64_t data;
		intptr_t hFile = _findfirsti64((file.path).c_str(), &data);
		if (hFile == -1)
		{
			_findclose(hFile);
			return false;//���� ���� �� ������ ���������� ����
		}
		_findclose(hFile);
		return data.attrib & _A_SUBDIR;//���� ������� ����� _A_SUBDIR(������ ��� �����) ���������� ������
	}
	bool isFile(FileorDirectory&file) const 
	{
		_finddatai64_t data;
		intptr_t hFile = _findfirsti64((file.path).c_str(), &data);
		if (hFile == -1)
		{
			_findclose(hFile);
			return false;//���� ���� �� ������ ���������� ����
		}
		_findclose(hFile);
		return !(data.attrib & _A_SUBDIR);//���� ������� ����� �� _A_SUBDIR(������ ��� �� �����) ���������� ������ 
	}
	
	std::string getName() const 
	{
		_finddatai64_t data;
		intptr_t hFile = _findfirsti64((this->path).c_str(), &data);
		if (hFile == -1)
		{
			_findclose(hFile);
			return false;
		}
		_findclose(hFile);
		return data.name;//���������� ��� �����
	}
	std::string getPath() 
	{
		return this->path;//���������� ��������� ����
	}
};

