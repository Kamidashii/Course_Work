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
	void Check(FileorDirectory& file, FileorDirectory& fileto);
};


