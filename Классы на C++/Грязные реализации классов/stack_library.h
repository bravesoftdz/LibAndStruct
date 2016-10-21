#pragma once

#include <cassert>
#include <iostream>
#include <iomanip>

template <typename T>
class Stack {
private:
	T *stackPtr; 
	const int size;
	int top;
public:
	Stack(int maxSize = 10) : size(maxSize) { stackPtr = new T[size]; top = 0; };
	Stack(const Stack<T> &);
	~Stack() { delete[] stackPtr; };

	inline void push(const T &value) { assert(top < size); stackPtr[top++] = value; };
	inline T pop() { assert(top > 0); return stackPtr[--top]; };
	inline void printStack();
	inline const T &Peek(int nom) const {  assert(nom <= top); return stackPtr[top - nom]; };
	inline int getStackSize() const { return size; };
	inline T *getPtr() const { return stackPtr; };
	inline int getTop() const { return top; };
};

template <typename T> Stack<T>::Stack(const Stack<T> & otherStack)
: size(otherStack.getStackSize())
{
	stackPtr = new T[size];
	top = otherStack.getTop();

	for(int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.getPtr()[ix];
}

template <typename T> inline void Stack<T>::printStack() {
	for (int ix = top - 1; ix >= 0; ix--)
		std::cout << "|" << std::setw(4) << stackPtr[ix] << std::endl;
}