#pragma once
#include<iostream>
#include<memory>
#include"Copying.h"
#include "FileorDirectory.h"
#include"Synchronizer.h"
#include"Checking.h"
#include"Smart_Desc.h"
class SynSpace::Copying;
namespace SynSpace
{
	class Synchronizer :
		public FileorDirectory
	{
		using FileorDirectory::FileorDirectory;
		Synchronizer(const Synchronizer&) = delete;
		Synchronizer(Synchronizer&) = delete;
		Synchronizer& operator =(const Synchronizer&) = delete;
		Synchronizer& operator =(Synchronizer&) = delete;
		bool _Syn(Synchronizer &, Synchronizer&, Copying&, int);//private Synchronize metod
		long long FullSize(Synchronizer&, long long&);//conside directory size metod
		bool FileSize(Synchronizer&);//file size metod
	protected:
		long long DirSize = 0;//Full size of original Directory or file
	public:
		Synchronizer() = default;
		Synchronizer(std::string path) :FileorDirectory(path) {}
		bool Syn(Synchronizer&fileto);//public Synchronize metod
		void SizeHelper();//understandable size convert metod
	};
}


