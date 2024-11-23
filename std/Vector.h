#pragma once
#include <initializer_list>
#include <exception>

template<typename T>
class Vector {
private:
	T* Data;
	size_t size = 0;
	size_t capacity = 4;
public:
	Vector() {
		Data = new T[capacity];
	}
	Vector(Vector& other) {
		Data = other.Data;
		size = other.size;
		capacity = other.capacity;
	}
	Vector(std::initializer_list<T> list) {
		capacity = list.size();
		Data = new T[capacity];
		for (auto& i : list)
		{
			Data[size] = i;
			size++;
		}
	}
	Vector(long long int count, int number)
	{
		capacity = count;
		Data = new T[capacity];
		for (size_t i = 0; i < capacity; i++)
		{
			Data[size] = number;
			size++;
		}
	}
	Vector(Vector&& other) {
		Data = other.Data;
		other.Data = nullptr;
		size = other.size;
		capacity = other.capacity;
	}
	void push_back(T t) {
		if (size == capacity)
		{
			capacity *= 2;
			T* newData = new T[capacity];
			//move semantics?
			for (size_t i = 0; i < size; i++) {
				newData[i] = Data[i];
			}
			delete[] Data;
			Data = newData;
			delete[] newData;
		}
		Data[size] = t;
		size++;
	}
	constexpr int at(int Pos)
	{
		if (Pos > size)
			throw std::exception("invalid position");
		else return Data[Pos];
	}
	void pop_back()
	{
		size--;
	}
	size_t getCapacity()
	{
		return capacity;
	}
	size_t getSize()
	{
		return size;
	}
	Vector& operator=(Vector& other)
	{
		if (this == &other)
			return *this;
		size = other.size;
		capacity = other.capacity;
		delete[] Data;
		Data = new T[capacity];
		for (size_t i = 0; i < other.size; i++)
		{
			Data[i] = other.Data[i];
		}
		return *this;
	}
	Vector& operator=(Vector&& other)
	{
		if (this == &other)
			return *this;
		delete[] Data;
		capacity = other.capacity;
		Data = other.Data;
		other.Data = nullptr;
		return *this;
	}
	T& operator[](unsigned int pos) {
		return Data[pos];
	}
	void clear()
	{
		size = 0;
	}
	~Vector()
	{
		delete[] Data;
	}
};



