#pragma once
#include "List.cpp"
#include <initializer_list>
#include <iterator>

template <typename T>
class List {
private:
	struct Node {
	public:
		Node* m_next = nullptr;
		Node* m_prev = nullptr;
		T* m_data = nullptr;
	};	
	Node* firstNode = nullptr;
	Node* lastNode = nullptr;
	int m_size = 0;
	void deepCoping(const List& other) {
		clear();
		m_size = 0;
		firstNode = nullptr;
		lastNode = nullptr;
		Node* prevNode = nullptr;
		Node* nodeToCopy = other.firstNode;
		do {
			m_size++;
			Node* node = new Node;
			if (!firstNode) {
				firstNode = prevNode;
			}
			{
				node->m_data = new T(*nodeToCopy->m_data);
				node->m_prev = prevNode;
				if (prevNode) {
					prevNode->m_next = node;
				}
			}
			prevNode = node;
			nodeToCopy = nodeToCopy->m_next;
		} while (m_size != other.m_size);
		lastNode = prevNode;
	}
	void initializerListCopy(const std::initializer_list<T>& list) {
		firstNode = new Node;
		Node* currentNode = firstNode;
		for (const auto& it : list)
		{
			m_size++;
			currentNode->m_data = new T(it);
			if (m_size == list.size()) {
				lastNode = currentNode;
				continue;
			}
			Node* nextNode = new Node;
			currentNode->m_next = nextNode;
			nextNode->m_prev = currentNode;
			currentNode = nextNode;
		}
	}
public:	
	List() {}
	List(const List& other) {
		deepCoping(other);
	}
	List(const std::initializer_list<T>& list)
	{
		initializerListCopy(list);
	}
	List(int count, const T& data)
	{
		firstNode = new Node;
		Node* currentNode = firstNode;
		for (size_t i = 0; i < count; i++)
		{
			currentNode->m_data = new T(data);
			if (m_size == count) {
				lastNode = currentNode;
				continue;
			}
			Node* nextNode = new Node;
			currentNode->m_next = nextNode;
			nextNode->m_prev = currentNode;
			currentNode = nextNode;
			m_size++;
		}
	}
	~List() {
		clear();
	}
	List& operator=(const List& other) {

		deepCoping(other);
		return *this;
	}
	T front() {
		return *firstNode->m_data;
	}
	T back() {
		return *lastNode->m_data;
	}
	void pop_back() {
		delete lastNode->m_data;
		if (lastNode->m_prev) {
			Node* tempNode = lastNode;
			lastNode = lastNode->m_prev;
			lastNode->m_next = nullptr;
			delete tempNode;
		}
		else {
			delete lastNode;
		}
		m_size--;
	}
	void pop_front() {
		delete firstNode->m_data;
		if (firstNode->m_next) {
			Node* tempNode = firstNode;
			firstNode = firstNode->m_next;
			firstNode->m_prev = nullptr;
			delete tempNode;
		}
		else
		{
			delete firstNode;
		}
		m_size--;
	}
	const int size() {
		return m_size;
	}
	void clear() {
		if (firstNode == lastNode) {
			delete firstNode->m_data;
			delete firstNode;
		}
		else {
			Node* node;
			if (firstNode)
				node = firstNode;
			else
				return;
			do
			{
				delete node->m_data;
				node = node->m_next;
				delete node->m_prev;
			} while (node->m_next);
			delete node;
		}

	}
	void assign(const std::initializer_list<T>& list) {
		clear();
		initializerListCopy(list);
	}
	void push_back(T&& t) {
		Node* newNode = new Node;
		newNode->m_data = new T(t);
		lastNode->m_next = newNode;
		newNode->m_prev = lastNode;
		lastNode = newNode;
		m_size++;
	}
	void push_front(T&& t) {
		Node* newNode = new Node;
		newNode->m_data = new T(t);
		firstNode->m_prev = newNode;
		newNode->m_next = firstNode;
		firstNode = newNode;
		m_size++;
	}

	template<typename T>	
	struct Iterator {
	public:
		using iterator_category = std::forward_iterator_tag;
		using different_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		Iterator(Node* node) : m_node(node) {}

	private:
		Node* m_node;

	public:
		reference operator*() const { return *m_node->m_data; }
		pointer operator->() const { return *m_node->m_data; }

		Iterator operator++() {
			if (m_node) {
				m_node = m_node->m_next;
			}
			return *this;
		}

		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_node == b.m_node; }
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_node != b.m_node; }
	};
	Iterator<T> begin() { return Iterator<T>(firstNode); }
	Iterator<T> end() { return Iterator<T>(nullptr); }
};
