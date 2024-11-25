#pragma once
#include <iterator>

template<typename T>
struct Iterator {


public:
	using iterator_category = std::forward_iterator_tag;
	using different_type = std::ptrdiff_t;
	using value_type = T;
	using pointer = T*;
	using reference = T&;
	Iterator(pointer ptr) : m_ptr(ptr) {}

private:
	pointer m_ptr;

public:
	reference operator*() const { return *m_ptr; }
	pointer operator->() { return m_ptr; }

	Iterator& operator++() { m_ptr++; return *this; }

	friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
	friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
};
