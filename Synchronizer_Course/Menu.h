#pragma once
#include<string>
#include"Synchronizer.h"
#include"ReDir.h"
class Menu
{
	Synchronizer file, fileto;
public:
	Menu(std::string path,std::string pathto);
	~Menu();
	std::string Sync()
	{
		file.Syn(fileto);
		return "\n\nSynchronizing was finished\n";
	}
	std::string Del()
	{
		ReDir().Rerecurse(fileto);//recurse directory remove metod
		return "\nCopy dorectory remove was finished";
	}
	std::string SetPath();//set new path metod
	std::string SeePaths()
	{
		std::string paths;
		paths = "Original file path: " + file.getPath() + "\nCopy file path: " + fileto.getPath();
		return paths;
	}
	std::string Check();//return hint about exist paths
	std::string GetPath()
	{
		return file.getPath();
	}
	std::string GetPathto()
	{
		return fileto.getPath();
	}
	std::string(Menu::*metod[4])() = { &Menu::Sync,&Menu::Del,&Menu::SetPath,&Menu::SeePaths };//menu metods pointers
	std::string MenuSyn(int num)//Synchronizer menu
	{
		return(this->*metod[num])();
	}
};

