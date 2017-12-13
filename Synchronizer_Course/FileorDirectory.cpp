#include"stdafx.h"
#include "FileorDirectory.h"



std::string FileorDirectory::list()
{
	std::string res;//��������� ������ � ������� ����� ������������ ���� ��������������� ������
	_finddatai64_t data;//��������� ������ ��������� _finddata_t
	intptr_t hFile = _findfirsti64((path + "\\" + "*").c_str(), &data);//��������� ���� � ���������� ��� � intptr_t ��������� �� ��������� _finddata_t
	if (hFile == -1) return res;//���� ������ ���� �� ����������, ���������� ������ ������
	do {
		if (strcmp(data.name, ".") == 0 || strcmp(data.name, "..") == 0)continue;//��������� ��������� ����� "." � ".."
		res=(path + "\\" + data.name);//��������� � ������ ������ ���� � ����� 
	} while (_findnexti64(hFile, &data) == 0);//���� ���� ���� �� �������������� ��� �����
	return res;//���������� ������ � ����������� � ��� ������� ������ ������
}

