#pragma once
#include<string>
#include"Synchronizer.h"
#include"ReDir.h"
#include"Smart_Desc.h"
#include<memory>
namespace SynSpace
{
	class Menu
	{
		Synchronizer file, fileto;
		Menu(const Menu&) = delete;
		Menu(Menu&) = delete;
		Menu& operator =(const Menu&) = delete;
		Menu& operator =(Menu&) = delete;
	public:
		Menu(const std::string& path, const std::string& pathto);
		~Menu() = default;
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
			paths = "Original file path: " + file.GetPath() + "\nCopy file path: " + fileto.GetPath();
			return paths;
		}
		std::string Check();//return hint about exist paths
		std::string GetPath()
		{
			return file.GetPath();
		}
		std::string GetPathto()
		{
			return fileto.GetPath();
		}
		std::string(Menu::*metod[4])() = { &Menu::Sync,&Menu::Del,&Menu::SetPath,&Menu::SeePaths };//menu metods pointers
		std::string MenuSyn(int num)//Synchronizer menu
		{
			return(this->*metod[num])();
		}
	};
}


