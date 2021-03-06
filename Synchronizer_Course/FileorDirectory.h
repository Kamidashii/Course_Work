#pragma once
#include"stdafx.h"
#include"ErrSyn.h"
#include"Smart_Desc.h"
namespace SynSpace
{
	class FileorDirectory
	{
		FileorDirectory(const FileorDirectory&) = delete;
		FileorDirectory(FileorDirectory&) = delete;
		FileorDirectory& operator =(const FileorDirectory&) = delete;
		FileorDirectory& operator =(FileorDirectory&) = delete;
	protected:
		std::string path;//directory path
		_finddatai64_t data;
	public:
		FileorDirectory() = default;
		FileorDirectory(std::string path) :path(path) {}
		bool isDirectory(FileorDirectory&file) const //checking, if it's directory return true
		{
			std::unique_ptr<Smart_Desc> hFile(new Smart_Desc(_findfirsti64((file.path).c_str(), &file.GetData())));
			if (!*hFile)
			{
				return false;
			}
			return data.attrib & _A_SUBDIR;
		}
		bool IsFile(FileorDirectory&file) const //checking, if it's file return true
		{
			std::unique_ptr<Smart_Desc> hFile(new Smart_Desc(_findfirsti64((file.path).c_str(), &file.GetData())));
			if (!*hFile)
			{
				return false;
			}
			return !(data.attrib & _A_SUBDIR);
		}

		std::string GetName() //get name metod
		{
			std::unique_ptr<Smart_Desc> hFile(new Smart_Desc(_findfirsti64((this->path).c_str(), &this->GetData())));
			if (!*hFile)
			{
				return false;
			}
			return data.name;
		}
		std::string GetPath()const //get path metod
		{
			return this->path;
		}
		void SetPath(std::string path)//set path metod
		{
			this->path = path;
		}
		_finddatai64_t& GetData()
		{
			return this->data;
		}
	};
}
