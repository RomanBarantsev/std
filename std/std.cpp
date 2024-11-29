// std.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <deque>
#include "Vector.h"

int main()
{
	std::vector<int> vec{ 1,2,3 };
	Vector<int> v{ 1,2,3 };
	for (const auto& i : v)
	{
		std::cout << i;
	}
	for (auto it=v.rbegin();it!=v.rend();++it)
	{
		std::cout << *it;
	}
}
