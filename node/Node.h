#include "A_Node.h"

#ifndef _NODE_H_
#define _NODE_H_

class Node : public A_Node

{
public:

	//constructor
	Node(Node* parent, int action, std::array<int, 9> state);

	//constructor
	Node(std::array<int, 9> state);

	//Returns parents Node
	Node* parent();

	//Returns action that generated current node. 1=right, 2=left,3=up,4=down.
	int action();

	//returns state of problem stored in current node
	std::array<int,9> state();

	//returns cumalative cost of path for current node
	int path_cost();

	//set path cost
	void set_path(int path_cost);

private:
	//Node details
	Node * parent_;
	int action_;
	std::array<int,9> state_;
	int path_cost_;

};

#endif  // !defined _NODE_H_