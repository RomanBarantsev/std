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
	std::list<int> li{1,2,3};
	li.assign({ 4,5,6 });
	myLib::List<int> l1{1,2,3};
	myLib::List<int> l3{1,2,3};
	l1.push_back(4);
	l1.push_front(0);
	l3 = l1;
	/*l3.clear();
	{
		myLib::List<long long> l{ 100000 };
		std::vector<myLib::List<long long>> ll(10000000, l);

	}*/
	
	/*l1.push_back(4);
	l1.push_front(0);*/

}
