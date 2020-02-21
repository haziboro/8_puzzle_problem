#include "PriorityNode.h"

//priority queue constructor
PriorityNode::PriorityNode(int priority, Node* const nodeValue)
	: priority_(priority),
	nodeValue_(nodeValue) {};

//priority queue overload
bool PriorityNode::operator< (PriorityNode const& other) const
{
	return priority_ < other.priority_;
}

//priority queue overload
bool PriorityNode::operator> (PriorityNode const& other) const
{
	return priority_ > other.priority_;
}

Node* PriorityNode::getValue()
{
	return nodeValue_;
}
