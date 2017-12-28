#include"stdafx.h"
#include "Copying.h"

namespace SynSpace
{
	bool Copying::FileCopy(const FileorDirectory& path_in, const FileorDirectory& path_out, long long DirSize)
	{
		long long tmp = 0;
		std::string buf(4096, '\0');
		std::ifstream in(path_in.GetPath(), std::ios::binary);
		std::ofstream out(path_out.GetPath(), std::ios::binary | std::ios::trunc);
		if (!in || !out)
			throw SynSpace::ErrSyn("Can't open file");
		do
		{
			in.read(&buf[0], buf.size());
			if (!in.gcount())
				break;

			out.write(&buf[0], in.gcount());
			auto percent = CopyProgress(DirSize, in.gcount());
			if (percent != tmp)
			{
				std::cout << percent << "%\r";
				tmp = percent;
			}
		} while (!in.eof());
		return true;
	}
}