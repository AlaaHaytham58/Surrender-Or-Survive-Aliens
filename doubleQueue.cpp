#include "doubleQueue.h"
bool  doubleQueue::enqueueFront(AlienDrone* newEntry) {
	Node<AlienDrone*>* newNodePtr = new Node<AlienDrone*>(newEntry);

	// Insert the new node
	if (isEmpty()) {//special case if this is the first node to insert
		backPtr = this->frontPtr = newNodePtr; // The queue is empty
		return true;
	}
	else {
		newNodePtr->setNext(frontPtr);
		frontPtr = frontPtr; // The queue was not empty
		return true;
	}
	return false;
}
bool  doubleQueue::enqueueBack(AlienDrone*& newEntry) {
	Node<AlienDrone*>* newNodePtr = new Node<AlienDrone*>(newEntry);
	// Insert the new node
	if (isEmpty()) {//special case if this is the first node to insert
		backPtr = this->frontPtr = newNodePtr; // The queue is empty
		return true;
	}
	else {
		backPtr->setNext(newNodePtr);
		backPtr = newNodePtr;
		return true;
	}
	return false;
}

bool  doubleQueue::dequeueFront(AlienDrone*& frontEntry) {
	if (isEmpty())
		return false;

	Node<AlienDrone*>* nodeToDeletePtr = frontPtr;
	frontEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;

}

bool  doubleQueue::dequeueBack(AlienDrone*& backEntry) {
	if (isEmpty())
		return false;
	backEntry = backPtr->getItem();
	Node< AlienDrone*>* temp = frontPtr;
	while (temp->getNext()->getNext()) {
		temp = temp->getNext();
	}
	delete backPtr;
	backPtr = temp;
	backPtr->setNext(NULL);
	// Free memory reserved for the dequeued node

	return true;

}

bool doubleQueue::peekback(AlienDrone*& ad)
{ 
	if(isEmpty())
	return false;
	ad= 
}
