#include "A_Fringe.h"
#include <queue>

#ifndef _FRINGE_QUEUE_H_
#define _FRINGE_QUEUE_H_

class Fringe_Queue : public A_Fringe
{
public:
	//constructor
	Fringe_Queue(std::queue<Node*> queue);

	//adds new node to fringe queue
	void add(Node* node);

	//dequeues node from fringe queue and returns it
	Node* remove();

	//checks if fringe queue is empty, returns appropriate bool
	bool is_empty();

private:
	//Data structure for this fringe strategy
	std::queue<Node*> queue_;
};

#endif  // !defined _FRINGE__QUEUE_H_