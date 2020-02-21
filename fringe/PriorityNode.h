#include "..//node/Node.h"
#include <queue>

#ifndef _PRIORITY_NODE_H_
#define _PRIORITY_NODE_H_

//Overloaded priority queue
class PriorityNode
{
public:
	int priority_;
	Node* nodeValue_;

	//constructor
	PriorityNode(int priority, Node* const nodeValue);

	//overload <
	bool operator< (PriorityNode const& other) const;

	//overload >
	bool operator> (PriorityNode const& other) const;

	//return Node
	Node* getValue();
};
#endif  // !defined _PRIORITY_NODE_H_