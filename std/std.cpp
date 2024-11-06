// std.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <deque>
#include "myLib.h"
//#include "g:\Git\UsefulLibrary\UsefulLibrary\UsefulLibrary.h"

int main()
{
	myLib::Vector<int> v1{1,2,3};
	myLib::Vector<int> v2 = v1;
	std::vector<int> vec{ 1,2,3 };
	
}
