//See Fringe_Queue.h for implementation details
#include "Fringe_Queue.h"

//constructor
Fringe_Queue::Fringe_Queue(std::queue<Node*> queue)
	:queue_(queue) {}

//add
void Fringe_Queue::add(Node* node)
{
	queue_.push(node);
}

//remove
Node* Fringe_Queue::remove()
{
	Node* next = queue_.front();
	queue_.pop();
	return next;
}

//is_empty
bool Fringe_Queue::is_empty()
{
	return queue_.empty();
}