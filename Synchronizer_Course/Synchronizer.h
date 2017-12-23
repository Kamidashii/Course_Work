#pragma once
#include"Copying.h"
#include "FileorDirectory.h"
#include"Synchronizer.h"
#include"Checking.h"
class Copying;
class Synchronizer :
	public FileorDirectory
{
	using FileorDirectory::FileorDirectory;
	bool _Syn(Synchronizer &, Synchronizer&,Copying&,int);//private Synchronize metod
	long long& Fullsize(Synchronizer&,long long&);//conside directory size metod
	bool Filesize(Synchronizer&);//file size metod
protected:
	long long DirSize=0;//Full size of original Directory or file
public:
	Synchronizer() = default;
	Synchronizer(std::string path):FileorDirectory(path){}
	bool Syn(Synchronizer&fileto);//public Synchronize metod
	void SizeHelper();//understandable size convert metod
};

