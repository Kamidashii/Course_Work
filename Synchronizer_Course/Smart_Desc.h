#pragma once
#include<iostream>
#include<direct.h>
#include<io.h>
#include<memory>
namespace SynSpace
{
	class Smart_Desc
	{
		intptr_t h = 0;
		Smart_Desc(const Smart_Desc&) = delete;
		Smart_Desc(Smart_Desc&) = delete;
		Smart_Desc& operator =(const Smart_Desc&) = delete;
		Smart_Desc& operator =(Smart_Desc&) = delete;
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
}

