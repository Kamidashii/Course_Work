#pragma once
#include<iostream>
#include<direct.h>
#include<io.h>
#include<memory>
class Smart_Desc
{
	intptr_t h = 0;
public:
	explicit Smart_Desc(intptr_t h = 0)noexcept : h(h) {}
	~Smart_Desc()noexcept
	{
		if (this->h&&this->h != -1)
			_findclose(this->h);
	}
	operator intptr_t()const noexcept
	{
		return this->h;
	}
	bool operator ! ()const noexcept
	{
		return this->h == -1;
	}
};
