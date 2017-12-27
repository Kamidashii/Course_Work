
#include"stdafx.h"
#include "Checking.h"

bool Checking::Check(FileorDirectory& file, FileorDirectory& fileto)
{
	std::unique_ptr<Smart_Desc> in_file(new Smart_Desc(_findfirsti64((file.getPath()).c_str(), &file.GetData())));
	std::unique_ptr<Smart_Desc> out_file(new Smart_Desc(_findfirsti64((fileto.getPath()).c_str(), &fileto.GetData())));
	bool res = !*out_file || file.GetData().size != fileto.GetData().size;
	return res;

}
