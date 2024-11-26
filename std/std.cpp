// std.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "List.h"
#include "std.h"

int main()
{
	int arr[] = { 10, 20, 30, 40, 50 };
	int* p1 = &arr[1];  // Points to 20
	int* p2 = &arr[4];  // Points to 50

	std::ptrdiff_t diff = p2 - p1;  // Difference between pointers

	std::cout << "Difference: " << diff << std::endl; // Output: 3

	std::list<int> l{1,2,3};
	for (auto& i : l)
	{
		std::cout << i;
	}
	List<int> l1{1,2,3};
	for (auto& i : l1)
	{
		std::cout << i << std::endl;
	}
}
