#include <iostream>


// linked list
// 2d array -> insert...

template <typename T>
class list_node {
private:
	list_node<T> *prev;
	list_node<T> *next;
	T data;
public:
	list_node();
	list_node(const T &);	// ...
	~list_node();
	void pop_from_list();
	void push_at_tail(list_node<T> &);
	T operator*();
	list_node<T> & operator++();
	list_node<T> operator++(int);
	list_node<T> & operator--();
	list_node<T> operator--(int);
};

template <typename T>
struct graph {
	list_node<T> *nodes;
};

template <typename T>
list_node<T>::list_node() : data(), prev(NULL), next(NULL) {
}


template <typename T>
list_node<T>::list_node(const T &_data) : data(_data), prev(NULL), next(NULL) {
}

template <typename T>
list_node<T>::~list_node() {
	pop_from_list();
}

template <typename T>
void list_node<T>::pop_from_list() {
	list_node<T> *prev_node = prev;
	list_node<T> *next_node = next;

	if(prev_node != NULL)
		prev_node->next = next;
	if(next_node != NULL)
		next_node->prev = prev;

	prev = NULL;
	next = NULL;
}


template <typename T>
void list_node<T>::push_at_tail(list_node<T> & list) {
	while (list.next != NULL) {
		++list;
	}
	list.next = this;
	this->prev = &list;
}

template <typename T>
T list_node<T>::operator*() {
	return data;
}

template <typename T>
list_node<T> & list_node<T>::operator++() {
	if (next == NULL)
		return *this;

//  this = next;	// error
	list_node<T> *new_node = next;
	prev = this;
	data = **new_node;
	next = new_node->next;
	
	return *this;	// how to access original this??
}

template <typename T>
list_node<T> list_node<T>::operator++(int) {
	if (next == NULL)
		return *this;

	list_node<T> tmp = *this;
	list_node<T> *new_node = next;
	prev = this;
	data = **new_node;
	next = new_node->next;

	return tmp;
}

template <typename T>
list_node<T> & list_node<T>::operator--() {
	if (prev == NULL)
		return *this;

	list_node<T> *new_node = prev;
	prev = new_node->prev;
	data = **new_node;
	next = this;
	
	return *this;
}

template <typename T>
list_node<T> list_node<T>::operator--(int) {
	std::cout << "as" << std::endl;
	if (prev == NULL)
		return *this;

	list_node<T> tmp = *this;
	list_node<T> *new_node = prev;
	prev = new_node->prev;
	data = **new_node;
	next = this;

	return tmp;
}


int main(void) {
	list_node<int> a(1);
	list_node<int> b(2);
	b.push_at_tail(a);
	std::cout << *b-- << std::endl;
	std::cout << *(++a) << std::endl;
	printf(" s");
	return 0;
}
