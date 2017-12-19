#pragma once
#include<iostream>
#include<direct.h>
#include<io.h>
#include"Synchronizer.h"
#include"FileorDirectory.h"
class ReDir
{
	void _Rerecurse(FileorDirectory&);
public:
	ReDir();
	~ReDir();
	void Rerecurse(FileorDirectory&syn)
	{
		_Rerecurse(syn);
	}
};

