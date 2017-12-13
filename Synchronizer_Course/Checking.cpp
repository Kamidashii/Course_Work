
#include"stdafx.h"
#include "Checking.h"


Checking::Checking()
{
}


Checking::~Checking()
{
}

void Checking::Check(FileorDirectory& file, FileorDirectory& fileto)
{
	_finddatai64_t in;
	_finddatai64_t out;
	intptr_t in_file;
	intptr_t out_file;
	in_file = _findfirsti64((file.getPath()).c_str(), &in);
	out_file = _findfirsti64((fileto.getPath()).c_str(), &out);
	if (in_file == -1)
		throw std::exception("Incorrect original file path trade");
	out_file = _findfirsti64((fileto.getPath()).c_str(), &out);
	if (!out_file)
	{
		Copying().FileCopy(file,fileto);
		return;
	}
			if (in.size!=out.size)
			{
				Copying().FileCopy(file,fileto);
				return;
			}
}
