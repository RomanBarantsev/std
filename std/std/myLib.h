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

	template <typename T>
	class List {
	private:
		struct Node {
		public:
			Node* m_next = nullptr;
			Node* m_prev = nullptr;
			T* m_data=nullptr;
		};
		Node* firstNode = nullptr;
		Node* lastNode = nullptr;
		int m_size = 0;
	public:
		List(const std::initializer_list<T>& list)
		{
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
		List(int count,const T& data)
		{
			firstNode = new Node;
			Node* currentNode = firstNode;
			for (size_t i = 0; i < count; i++)
			{
				m_size++;
				currentNode->m_data = new T(data);
				if (m_size == count) {
					lastNode = currentNode;
					continue;
				}
				Node* nextNode = new Node;
				currentNode->m_next = nextNode;
				nextNode->m_prev = currentNode;
				currentNode = nextNode;
			}
		}
		~List() {
			Node* node;
			if (firstNode)
				node = firstNode;
			else
				return;
			do
			{
				delete node->m_data;
				if (!node->m_next)
					break;
				node = node->m_next;
				node->m_prev = nullptr;
			} while (node->m_next);
		}
		T front(){
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
		int size() {
			return m_size;
		}
		void assign(const std::initializer_list<T> list) {

		}
		void push_back(T& t) {

			m_size++;
		}
	};

	template<typename T>
	class ListAI {
	private:
		struct Node {
			T data;
			Node* prev;
			Node* next;
			Node(T value) : data(value), prev(nullptr), next(nullptr) {}
		};

		Node* head;
		Node* tail;
		size_t size;

	public:
		// Default constructor
		ListAI() : head(nullptr), tail(nullptr), size(0) {}

		// Constructor to initialize the ListAI with a given number of elements
		ListAI(int count, const T value) : head(nullptr), tail(nullptr), size(0) {
			for (size_t i = 0; i < count; ++i) {
				push_back(value);
			}
		}

		// Destructor to free all nodes
		~ListAI() {
			while (head != nullptr) {
				Node* temp = head;
				head = head->next;
				delete temp;
			}
		}

		// Add element to the back of the ListAI
		void push_back(const T& value) {
			Node* newNode = new Node(value);
			if (tail) {
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
			else {
				head = tail = newNode;  // First node in the ListAI
			}
			++size;
		}

		// Add element to the front of the ListAI
		void push_front(const T& value) {
			Node* newNode = new Node(value);
			if (head) {
				head->prev = newNode;
				newNode->next = head;
				head = newNode;
			}
			else {
				head = tail = newNode;  // First node in the ListAI
			}
			++size;
		}

		// Remove element from the front
		void pop_front() {
			if (head) {
				Node* temp = head;
				head = head->next;
				if (head) head->prev = nullptr;
				else tail = nullptr;  // ListAI becomes empty
				delete temp;
				--size;
			}
		}

		// Remove element from the back
		void pop_back() {
			if (tail) {
				Node* temp = tail;
				tail = tail->prev;
				if (tail) tail->next = nullptr;
				else head = nullptr;  // ListAI becomes empty
				delete temp;
				--size;
			}
		}

		// Get the size of the ListAI
		size_t getSize() const {
			return size;
		}

		// Check if the ListAI is empty
		bool empty() const {
			return size == 0;
		}

		// Print the ListAI elements
		void print() const {
			Node* current = head;
			while (current) {
				std::cout << current->data << " ";
				current = current->next;
			}
			std::cout << std::endl;
		}
	};
}
