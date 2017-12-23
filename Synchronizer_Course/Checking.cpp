
#include"stdafx.h"
#include "Checking.h"


bool Checking::Check(FileorDirectory& file, FileorDirectory& fileto)
{
	_finddatai64_t in;
	_finddatai64_t out;
	intptr_t in_file;
	intptr_t out_file;
	in_file = _findfirsti64((file.getPath()).c_str(), &in);
	out_file = _findfirsti64((fileto.getPath()).c_str(), &out);
	bool res = !out_file || in.size != out.size;
	_findclose(in_file);
	_findclose(out_file);
	return res;

}
