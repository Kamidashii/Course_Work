#pragma once
#include"stdafx.h"
class FileorDirectory 
{ 
protected:
	std::string path;// ���� ��� ��������

public:
	FileorDirectory(std::string path) :path(path) {}//����������� �� ���������, ��������� ���� � ����� ���������� � � ����� ������. ���������� �� � ����������� ����
	std::string list();

	bool isDirectory(FileorDirectory&file) const 
	{
		_finddata_t data;
		intptr_t hFile = _findfirst((file.path).c_str(), &data);
		if (hFile == -1) return false;//���� ���� �� ������ ���������� ����
		return data.attrib & _A_SUBDIR;//���� ������� ����� _A_SUBDIR(������ ��� �����) ���������� ������
	}
	bool isFile(FileorDirectory&file) const 
	{
		_finddata_t data;
		intptr_t hFile = _findfirst((file.path).c_str(), &data);
		if (hFile == -1) return false;//���� ���� �� ������ ���������� ����
		return !(data.attrib & _A_SUBDIR);//���� ������� ����� �� _A_SUBDIR(������ ��� �� �����) ���������� ������ 
	}
	
	std::string getName() const 
	{
		_finddatai64_t data;
		intptr_t hFile = _findfirsti64((this->path).c_str(), &data);
		if (hFile == -1) return false;
		return data.name;//���������� ��� �����
	}
	std::string getPath() 
	{
		return this->path;//���������� ��������� ����
	}
};

