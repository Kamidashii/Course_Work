#pragma once
#include"stdafx.h"
#include<iostream>
#include<direct.h>
#include<io.h>
#include<string>
#include<memory>
#include"Copying.h"
#include"FileorDirectory.h"
#include"Smart_Desc.h"
class SynSpace::FileorDirectory;
namespace SynSpace
{
	class Checking
	{
		Checking(const Checking&) = delete;
		Checking(Checking&) = delete;
		Checking& operator =(const Checking&) = delete;
		Checking& operator =(Checking&) = delete;
	public:
		Checking() = default;
		~Checking() = default;
		bool Check(FileorDirectory& file, FileorDirectory& fileto);
	};
}



