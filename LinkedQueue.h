#pragma once
#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include "Node.h"
#include "QueueADT.h"
#include <vector>
#include <iostream>
using namespace std;


template <typename T>
class LinkedQueue :public QueueADT<T>
{
protected:

	Node<T>* backPtr = nullptr;
	Node<T>* frontPtr = nullptr;
public:
	LinkedQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	int getSize() const;
	~LinkedQueue();
	void print() const;

	//copy constructor
	LinkedQueue(const LinkedQueue<T>& LQ);
};

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}

template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}


//template <typename T>
//bool LinkedQueue<T>::enqueue(const T& newEntry)
//{
//	Node<T>* newNodePtr = new Node<T>(newEntry);
//	// Insert the new node
//	if (isEmpty())	//special case if this is the first node to insert
//	{
//		frontPtr = newNodePtr; // The queue is empty
//		backPtr = frontPtr;
//	}
//	else
//		backPtr->setNext(newNodePtr); // The queue was not empty
//
//	backPtr = newNodePtr; // New node is the last node now
//	return true;
//}

template <typename T>
bool LinkedQueue<T>::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);

	// If both pointers are null, the queue is empty, so initialize them
	if (frontPtr == nullptr && backPtr == nullptr) {
		frontPtr = newNodePtr;
		backPtr = newNodePtr;
	}
	else {
		// Insert the new node at the end of the queue
		backPtr->setNext(newNodePtr);
		backPtr = newNodePtr; // New node is the last node now
	}

	return true;
}

template <typename T>
bool LinkedQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;

}

template <typename T>
bool LinkedQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}

template <typename T>
int LinkedQueue<T>::getSize() const
{
	int count = 0;

	if (isEmpty())
		return count;

	Node<T>* Ptr = frontPtr;
	while (Ptr)
	{
		count++;
		Ptr = Ptr->getNext();
	}

	return count;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	T temp;

	//Free (Dequeue) all nodes in the queue
	while (dequeue(temp));
}

template <typename T>
void LinkedQueue<T>::print() const
{
	Node<T>* current = frontPtr;
	if (current != nullptr)
	{
		while (current != nullptr)
		{
			cout << current->getItem() << ",";
			current = current->getNext();
		}
	}
}

template<typename T>
inline LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& LQ)
{
}



//template <typename T>
//LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& LQ)
//{
//	Node<T>* NodePtr = LQ.frontPtr;
//	if (!NodePtr) //LQ is empty
//	{
//		frontPtr = backPtr = nullptr;
//		return;
//	}
//
//	//insert the first node
//	Node<T>* ptr = new Node<T>(NodePtr->getItem());
//	frontPtr = backPtr = ptr;
//	NodePtr = NodePtr->getNext();
//
//	//insert remaining nodes
//	while (NodePtr)
//	{
//		Node<T>* ptr = new Node<T>(NodePtr->getItem());
//		backPtr->setNext(ptr);
//		backPtr = ptr;
//		NodePtr = NodePtr->getNext();
//	}
//}

#endif