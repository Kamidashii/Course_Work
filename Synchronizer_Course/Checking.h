#pragma once
#include"stdafx.h"
#include<iostream>
#include<direct.h>
#include<io.h>
#include<string>
#include"Copying.h"
#include"FileorDirectory.h"
class FileorDirectory;
class Checking
{
public:
	Checking()=default;
	~Checking()=default;
	bool Check(FileorDirectory& file, FileorDirectory& fileto);
};


