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
class FileorDirectory;
class Checking
{
public:
	Checking() = default;
	~Checking() = default;
	bool Check(FileorDirectory& file, FileorDirectory& fileto);
};


