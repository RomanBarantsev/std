// std.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "myLib.h"
#include <list>

int main()
{
	myLib::List<int> L{ 1,2,3 };
	L.push
	std::list<int> L2{ 1,2,3 };
	L2.push_back(1);
	//std::cout << L2.size() << std::endl;
	{
		myLib::LogDuration l("1");
		std::list<int> L2(1e7,0);
	}
	{
		myLib::LogDuration l("3");
		myLib::ListAI<int> L(1e7, 0);
	}
}
