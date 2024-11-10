// std.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <deque>
#include "myLib.h"
#include <list>
//#include "g:\Git\UsefulLibrary\UsefulLibrary\UsefulLibrary.h"

int main()
{
	myLib::List<int> l1{1,2,3};
	myLib::List<int> l2 = l1;
	l1.push_back(4);
	l1.push_front(0);
	std::cout << l1.front();
	
}
