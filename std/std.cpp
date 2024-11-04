// std.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <deque>
#include "myLib.h"
#include "g:\Git\UsefulLibrary\UsefulLibrary\UsefulLibrary.h"

int main()
{
	myLib::Vector<int> v1{1,2,3};
	myLib::Vector<int> v2;
	v2 = v1;
	myLib::Vector<int> v3;
	v3 = std::move(v1);
	myLib::Vector<int> v4 = std::move(v3);	
	for (size_t i = 0; i < v2.getSize(); i++)
	{		
		std::cout << (v2[i]) << std::endl;		
	}
	std::deque<long long> deq{ 1,2,3 };
	std::vector<int> vec(1000, 1000);
	deq.push_back(1);
	std::vector<int> vec2(1000, 1000);
	deq.push_back(1);
	Usefull::isFragmented(deq);
}
