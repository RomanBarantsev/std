// std.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <deque>
#include "myLib.h"
#include <list>
#include "List.h"
//#include "g:\Git\UsefulLibrary\UsefulLibrary\UsefulLibrary.h"

int main()
{
	std::list<int> li{1,2,3};
	li.assign({ 4,5,6 });
	List<int> l{ 1,2,3 };


}
