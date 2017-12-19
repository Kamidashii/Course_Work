#pragma once
#include<iostream>
namespace Err
{
	class ErrSyn :public std::exception
{
public:
	ErrSyn(const char*error) :std::exception(error) {}
	~ErrSyn() = default;
};
}


