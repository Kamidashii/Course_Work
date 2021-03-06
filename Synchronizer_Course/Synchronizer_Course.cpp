// Synchronizer_Course.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include"stdafx.h"
#include<iostream>
#include"FileorDirectory.h"
#include"Synchronizer.h"
#include"ReDir.h"
#include"Menu.h"
#include<sstream>

void Interface(char**str);
int SafeEnter(std::string option);

int main(int count, char**str)
{
	try
	{
		Interface(str);
	}
	catch (SynSpace::ErrSyn error)
	{
		std::cout << "Incorrect path to original file or this directory is protect " << error.what() << std::endl;
	}
	catch (std::out_of_range out)
	{
		std::cout << out.what() << std::endl;
	}
	catch (std::exception exc)
	{
		std::cout << exc.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown exception" << std::endl;
	}
	return 0;
}

void Interface(char**str)
{
	int safeoption;
	std::string option;
	SynSpace::Menu m(str[1], str[2]);
	if ((m.GetPath()).size() > 0 && (m.GetPathto()).size() > 0)
	{
		str[1] = &(m.GetPath())[0];
		str[2] = &(m.GetPathto())[0];
	}
	do
	{
		std::cout << "\n\tSynchronizer menu\n0 Two directories Synchronize\n1 Clear copy directory\n2 Enter new paths\n3 See entered paths\n-1 for exit" << std::endl;

		std::cin >> option;
		safeoption = SafeEnter(option);
		if (safeoption > 3 || safeoption < -1)
			throw std::out_of_range("Incorrect choose");
		if (safeoption == -1)
			continue;
		std::cout << m.MenuSyn(safeoption);
	} while (safeoption != -1);
}

int SafeEnter(std::string option)
{
	for (int i = 0;i < option.length();i++)
	{
		if (option[i] == '-'&&option[i + 1] == '1')
		{
			i++;
			continue;
		}
		if (isdigit(option[i]));
		else
		{
			std::cout << "Enter numbers from -1 to 3" << std::endl;
			std::cin >> option;
			i = -1;
		}
	}
	return atoi((option).c_str());
}

