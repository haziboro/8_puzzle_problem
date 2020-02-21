//See Fringe_A_Star.h for implementation details
#include "Fringe_A_Star.h"

//constructor
Fringe_A_Star::Fringe_A_Star(std::priority_queue<PriorityNode, std::vector<PriorityNode>, std::greater<PriorityNode>> queue)
	:queue_(queue) {}

//add
void Fringe_A_Star::add(Node* node)
{
	queue_.push({node->path_cost(),node});
}

//remove
Node* Fringe_A_Star::remove()
{
	PriorityNode pnode = queue_.top();
	Node* node = pnode.getValue();
	queue_.pop();
	return node;
}

//is_empty
bool Fringe_A_Star::is_empty()
{
	return queue_.empty();
}