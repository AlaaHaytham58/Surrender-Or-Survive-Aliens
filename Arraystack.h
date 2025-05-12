
#pragma once
/** ADT stack: Array-based implementation.
@file ArrayStack.h */



#include "StackADT.h"

//Unless spesificed by the stack user, the default size is 100
template<typename T>
class ArrayStack : public StackADT<T>
{
private:
	T* items;		// Array of stack items
	int top;                   // Index to top of stack
	 int STACK_SIZE = 1000;

public:
	ArrayStack() {
		items = new T[STACK_SIZE];
		top = -1;
	}
	ArrayStack(int MaxSize) : STACK_SIZE(MaxSize)
	{
		items = new T[STACK_SIZE];
		top = -1;
	}  // end default constructor

	   //Function getCapacity() returns the stack max size
	   //added for array implementaion only
	int getCapacity()
	{
		return STACK_SIZE;
	}

	bool isEmpty() const
	{
		return top == -1;
	}  // end isEmpty

	bool push(const T& newEntry)
	{
		if (top == STACK_SIZE - 1) return false;	//Stack is FULL

		top++;
		items[top] = newEntry;
		return true;
	}  // end push

	bool pop(T& TopEntry) 
	{
		if (isEmpty()) return false;

		TopEntry = items[top];
		top--;
		return true;
	}  // end pop

	bool peek(T& TopEntry) const
	{
		if (isEmpty()) return false;

		TopEntry = items[top];
		return true;
	}  // end peek
	
	   //Destructor
	~ArrayStack()
	{
		delete[]items;
	}

	//Copy constructor
	ArrayStack(const ArrayStack<T>& S) :STACK_SIZE(S.STACK_SIZE)
	{
		items = new T[STACK_SIZE];
		for (int i = 0; i <= S.top; i++)
			items[i] = S.items[i];
		top = S.top;
	}
	//implemention function to get length of stack 
	int StackSize() const
	{
		return top + 1;
	}
	//print function to print items inside array stacks
	void print()
	{
		//cout << endl << "Printing stack contents :  ";
		//T x;
		//ArrayStack y(50);
		//for (int i = 0; i < STACK_SIZE; i++)
		//{
		//	cout << items[i]<< " ";
		//}
		for (int i = 0; i <= top; i++)  // Iterate up to 'top'
		{
			cout << items[i] << ", ";
		}
	}
}; // end ArrayStack


