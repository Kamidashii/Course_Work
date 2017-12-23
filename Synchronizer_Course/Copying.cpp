#include"stdafx.h"
#include "Copying.h"


bool Copying::FileCopy(FileorDirectory& path_in, FileorDirectory& path_out,long long DirSize)
{
	long long tmp = 0;
	std::string buf(4096, '\0');
	std::ifstream in(path_in.getPath(),std::ios::binary);
	std::ofstream out(path_out.getPath(),std::ios::binary|std::ios::trunc);
	if (!in||!out)
		throw Err::ErrSyn("Can't open file");
	do 
	{
		in.read(&buf[0], buf.size());
		buf.resize(in.gcount());
		out.write(&buf[0], buf.size());
		auto percent=CopyProgress(DirSize, buf.size());
			if (percent != tmp)
			{
				std::cout << percent << "%\r";
				tmp = percent;
			}
	} while (!in.eof());
	in.close();
	out.close();
	return true;
}