#pragma once
#include<iostream>
#include<direct.h>
#include<io.h>
#include<memory>
#include"Synchronizer.h"
#include"FileorDirectory.h"
#include"Smart_Desc.h"
namespace SynSpace
{
	class ReDir
	{
		void _Rerecurse(FileorDirectory&);//private recurse directory remove metod
		ReDir(const ReDir&) = delete;
		ReDir(ReDir&) = delete;
		ReDir& operator =(const ReDir&) = delete;
		ReDir& operator =(ReDir&) = delete;
	public:
		ReDir() = default;
		~ReDir() = default;
		void Rerecurse(FileorDirectory&syn)//public recurse directory remove metod
		{
			_Rerecurse(syn);
		}
	};
}


