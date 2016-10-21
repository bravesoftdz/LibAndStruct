#pragma once

template <class T> class List {
private:
	struct Element {
		T data;
		Element *next;
		Element *prev;
	};
	Element *Head;
	Element *Curr;
public:
	int length;
	List(): Head(0), Curr(0), length(0) {};
	~List() { for(int i = 0; i < length; i++) pop(); };
	void init() { Curr = Head };
	void push(T data);
	T pop();
	void search(T adr) {
		for(int i = 0; i < length; i++, next())
		if(Curr->data == adr) return;
	};
	void  loop();
	void  next() { Curr = Curr ? Curr->next : 0; };
	void  prev() { Curr = Curr ? Curr->prev : 0; };
	T lp() { return Curr ? Curr->data : 0; };
};

template <class T> void List<T>::push (T data) {
	Element *inserted = new Element;
	inserted->data = data;

	if (!Curr) {
		Head = inserted;
		Curr = inserted;
		Curr->next = inserted;
		Curr->prev = inserted;
	} else {
		inserted->next = Curr->next;
		inserted->next->prev = inserted;
		Curr->next = inserted;
		inserted->prev = Curr;
	}

	length++;
	Curr = inserted;
}

template <class T> T List<T>::pop() {
	if (!Curr) return 0;

	Element *temp = Curr;
	T tag = temp->data; 

	if (length == 1)
		Head = Curr = 0;
	else {
		Curr->next->prev = Curr->prev;
		Curr->prev->next = Curr->next;
		Curr = Curr->prev;
	}
	if (temp == Head) 
		Head = Head->next;
	length--;
	delete temp;
	return tag;
}

#include <iostream>

template <class T> void List<T>::loop() {
	if (Curr) {
		Element *tempCar = Head;
		for (int i = 0; i < length; i++) { 
			std::cout << tempCar->data << " ";
			tempCar = tempCar->next;
		} 
		std::cout << "\n"; 
	} else
		std::cout<< "List is empty\n";
}