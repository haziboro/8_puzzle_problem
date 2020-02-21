//See Node.h for implementation details
#include "Node.h"

//constructor
Node::Node(Node* parent, int action, std::array<int, 9> state)
	:parent_(parent),
	action_(action),
	state_(state),
	path_cost_(0){}

//constructor
Node::Node(std::array<int, 9> state)
	:parent_(NULL),
	action_(0),
	state_(state),
	path_cost_(0) {}

//parent
Node* Node::parent()
{
	return parent_;
}

//action
int Node::action()
{
	return action_;
}

//state
std::array<int, 9> Node::state()
{
	return state_;
}

//path_cost
int Node::path_cost()
{
	return path_cost_;
}

//set_path
void Node::set_path(int path_cost)
{
	path_cost_ = path_cost;
}
