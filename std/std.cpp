// std.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <deque>
#include "Vector.h"

class test {
public:
	int x=1;
public:
	test(int value) { x = value; };
	~test() {};
};

int main()
{
<<<<<<< Updated upstream
=======
	myLib::Vector<int> v1{1,2,3};
	myLib::Vector<int> v2 = std::move(v1);
	myLib::Vector<test> t(1);

>>>>>>> Stashed changes
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
