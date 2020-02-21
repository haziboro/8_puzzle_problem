#include "A_Fringe.h"
#include "PriorityNode.h"

#ifndef _FRINGE_A_STAR_H_
#define _FRINGE_A_STAR_H_

class Fringe_A_Star : public A_Fringe
{
public:
	//constructor
	Fringe_A_Star(std::priority_queue<PriorityNode, std::vector<PriorityNode>, std::greater<PriorityNode>> queue);

	//adds new node to fringe queue
	void add(Node* node);

	//dequeues node from fringe queue and returns it
	Node* remove();

	//checks if fringe queue is empty, returns appropriate bool
	bool is_empty();

private:
	//Data structure for this fringe strategy
	std::priority_queue<PriorityNode, std::vector<PriorityNode>, std::greater<PriorityNode>> queue_;

};
#endif  // !defined _FRINGE_A_STAR_H_