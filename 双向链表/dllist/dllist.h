#ifndef _DLLIST_H
#define _DLLIST_H

#include<iostream>
#include<assert.h>
// Linked DLList object that maintains both head and tail pointers
// and the count of the list. 
template<typename Type>
class DLList {
public:

	DLList();

	DLList(const DLList<Type>& other);

	DLList<Type>& operator=(const DLList<Type>& other);

	~DLList();

	void	print() const;
	bool	empty() const;

	void	insert_front(const Type& value);
	void	insert_rear(const Type& value);
	void	insert(int idx, const Type& value);

	// Note that the user must first ensure the list is not empty
	// prior to calling these functions. 
	Type	front() const;
	Type	rear() const;
	Type	get(int idx) const;

	int		size() const;
	int		find(const Type& value) const;

	bool	remove_front();
	bool	remove_rear();
	bool	remove(int idx);
	int		remove_value(const Type& value);

private:
	// Forward declare the nodes for our DLList.
	// Will be implemented along with list
	// member functions
	struct Node;

	// Both head and tail points for 
	// Fast insertion/deletion from both ends.
	Node* head;
	Node* tail;

	// Keep track of number of nodes in the list
	int		count;
};


/* DLList Implementation
*/
template<typename Type>
struct DLList<Type>::Node {
	Node() :next(nullptr), prev(nullptr) {}
	Node(Type it, Node* p, Node* n) : value(it), next(n), prev(p) {}

	Type  value;
	Node* next;
	Node* prev;
};

/* DLList default constructor
//		Set head and tail pointer to point to nothing.
*/
template<typename Type>
DLList<Type>::DLList() :head(nullptr), tail(nullptr), count(0) {
	/*  DONE  */
}


/* Copy constructor
*/
template<typename Type>
DLList<Type>::DLList(const DLList<Type>& other) {

	/*  TODO  */
	for (Node* p = other.head;p;p = p->next)
		insert_rear(p->value);

}
/* Overloaded assignment operator
*/
template<typename Type>
DLList<Type>& DLList<Type>::operator=(const DLList<Type>& other) {

	/*  TODO  */
	this->~DLList();
	for (Node* p = other.head;p;p = p->next)
		insert_rear(p->value);
	return *this;
}

/* DLList destructor
*/
template<typename Type>
DLList<Type>::~DLList() {

	/*  TODO  */
	for (Node* p = head->next;p;p = p->next) {
		free(p->prev);
	}
	if (tail)
		free(tail);
}

/* DLList print
*/
template<typename Type>
void DLList<Type>::print() const {

	/*  TODO  */
	if (!head)
		return;
	std::cout << head->value;
	for (Node* p = head->next;p;p = p->next) {
		std::cout << " " << p->value;
	}
	std::cout << std::endl;
}

/* DLList empty
*/
template<typename Type>
bool DLList<Type>::empty() const {

	/*  TODO  */
	return !count;
	return false;
}


/* DLList insert_front
*/
template<typename Type>
void DLList<Type>::insert_front(const Type& value) {

	/*  TODO  */
	if (count == 0) {
		head = new Node(value, nullptr, nullptr);
		tail = head;
		count++;
	}
	else if (count == 1) {
		Node* t = new Node(value, nullptr, head);
		head->prev = t;
		tail = head;
		head = t;
		count++;
	}
	else {
		Node* t = new Node(value, nullptr, head);
		head->prev = t;
		head = t;
		count++;
	}
}

/* DLList insert_rear
*/
template<typename Type>
void DLList<Type>::insert_rear(const Type& value) {

	/*  TODO  */
	if (count == 0) {
		head = new Node(value, nullptr, nullptr);
		tail = head;
		count++;
	}
	else if (count == 1) {
		Node* t = new Node(value, tail, nullptr);
		tail->next = t;
		tail = t;
		count++;
	}
	else {
		Node* t = new Node(value, tail, nullptr);
		tail->next = t;
		tail = t;
		count++;
	}
}

/* DLList insert
*/
template<typename Type>
void DLList<Type>::insert(int idx, const Type& value) {

	/*  TODO  */
	if (idx < 0) {
		insert_front(value);
	}
	else if (idx >= count) {
		insert_rear(value);
	}
	else {
		Node* p = head;
		while (idx--) {
			p = p->next;
		}
		Node* t = new Node(value, p->prev, p);
		if (t->prev) {
			t->prev->next = t;
		}
		p->prev = t;
		count++;
	}
}

/*  DLList front
*/
template<typename Type>
Type DLList<Type>::front() const {

	assert(head != nullptr);

	/*  TODO  */
	return head->value;

}

/* DLList rear
*/
template<typename Type>
Type DLList<Type>::rear() const {

	assert(tail != nullptr);

	/*  TODO  */
	return tail->value;

}

/* DLList get
*/
template<typename Type>
Type DLList<Type>::get(int idx) const {

	// Assert that index is correct before getting the Item
	assert(idx >= 0 && idx < count);

	/*  TODO  */
	Node* p = head;
	while (idx--) {
		p = p->next;
	}
	return p->value;

}

/* DLList size
*/
template<typename Type>
int DLList<Type>::size() const {

	/*  TODO  */
	return count;

	return 90000000;
}

/* DLList find
*/
template<typename Type>
int DLList<Type>::find(const Type& value) const {

	/*  TODO  */
	int pos = 0;
	for (Node* p = head;p;p = p->next, pos++) {
		if (p->value == value)
			return pos;
	}
	return -1;
}

/* DLList remove_front
*/
template<typename Type>
bool DLList<Type>::remove_front() {

	/*  TODO  */
	if (count == 0) {
		return false;
	}
	else if (count == 1) {
		delete head;
		head->prev = head->next = nullptr;
		tail->prev = tail->next = nullptr;
		count = 0;
		return true;
	}
	else {
		Node* t = head;
		head = head->next;
		head->prev = nullptr;
		delete t;
		count--;
		return true;
	}
	return false;
}
/* DLList remove_rear
*/
template<typename Type>
bool DLList<Type>::remove_rear() {

	/*  TODO  */
	if (count == 0) {
		return false;
	}
	else if (count == 1) {
		delete tail;
		head->prev = head->next = nullptr;
		tail->prev = tail->next = nullptr;
		count = 0;
		return true;
	}
	else {
		Node* t = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete t;
		count--;
		return true;
	}
	return false;
}

/* DLList remove on index
*/
template<typename Type>
bool DLList<Type>::remove(int idx) {

	/*  TODO  */
	if (idx < 0 || idx >= count)
		return false;

	if (idx == 0)
		remove_front();
	else if (idx == count - 1)
		remove_front();
	else {
		Node* p = head;
		while (idx--) {
			p = p->next;
		}
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		count--;
		return true;
	}
	return false;
}

/* DLList remove_value on value
*/
template<typename Type>
int DLList<Type>::remove_value(const Type& value) {

	/*  TODO  */
	int pos = 0;
	for (Node* p = head;p;p = p->next, pos++) {
		if (p->value == value)
		{
			if (remove(pos))
				return pos;
		}
	}

	return -2;
}

#endif

