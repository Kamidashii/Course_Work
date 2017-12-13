#include"stdafx.h"
#include "Copying.h"



Copying::Copying()
{
}


Copying::~Copying()
{
}

bool Copying::FileCopy(FileorDirectory& path_in, FileorDirectory& path_out)
{
	std::string buf(4096, '\0');
	std::ifstream in(path_in.getPath(),std::ios::binary);
	std::ofstream out(path_out.getPath(),std::ios::binary|std::ios::trunc);
	if (!in||!out)
		throw std::exception("Can't open file");
	while (!in.eof())
	{
		in.read(&buf[0], buf.size());
		out.write(&buf[0], buf.size());
	}
	in.close();
	out.close();
	return true;
}