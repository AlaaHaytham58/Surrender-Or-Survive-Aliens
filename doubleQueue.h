#pragma once
#include "LinkedQueue.h"
#include "AlienDrone.h"
class doubleQueue : public LinkedQueue<AlienDrone*> {
public:
	bool  enqueueFront( AlienDrone *);
	bool  enqueueBack( AlienDrone*&);
	bool  dequeueFront(AlienDrone*&);
	bool  dequeueBack(AlienDrone*&);
	bool peekback(AlienDrone*&);
};


