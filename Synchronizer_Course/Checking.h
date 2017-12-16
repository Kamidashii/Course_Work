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
	Checking();
	~Checking();
	bool Check(FileorDirectory& file, FileorDirectory& fileto);
};


