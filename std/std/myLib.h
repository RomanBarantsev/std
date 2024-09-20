#pragma once
#include <chrono>

namespace myLib {
	template<typename T>
	class Vector {
	private:
		T* Data;
		size_t size = 0;
		size_t capacity;
	public:
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
		void push_back(T t) {
			if (size == capacity)
			{
				capacity *= 2;
				T* newData = new T[capacity];
				//move semantics?
				for (size_t i = 0; i < size; i++) {
					newData[i] = Data[i];
				}
				Data = newData;
			}
			size++;
			Data[size] = t;
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
			if (this == other)
				return this;
			size = other.size;
			capacity = other.capacity;
			Data = new T[capacity];
			for (size_t i = 0; i < other.size; i++)
			{
				Data[i] = other.Data[i];
			}
		}
		void clear()
		{
			size = 0;
			delete Data;
		}
		~Vector()
		{
			delete Data;
		}
	};

	class LogDuration {
	public:
		LogDuration(std::string id)
			: id_(std::move(id)) {
		}
		long long time()
		{
			const auto end_time = std::chrono::steady_clock::now();
			const auto dur = end_time - start_time_;
			return std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		}
		~LogDuration() {
			const auto end_time = std::chrono::steady_clock::now();
			const auto dur = end_time - start_time_;
			std::cout << id_ << ": ";
			std::cout << "operation time"
				<< ": " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
				<< " ms" << std::endl;
		}

	private:
		const std::string id_;
		const std::chrono::steady_clock::time_point start_time_ = std::chrono::steady_clock::now();
	};

	template<typename T>
	class Deque {

	};
}
