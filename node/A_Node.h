#include <list>
#include <array>

#ifndef _A_NODE_H_
#define _A_NODE_H_

//interface for defining Nodes
class A_Node
{
public:

	virtual A_Node* parent() = 0;

	virtual int action() = 0;

	virtual std::array<int,9> state() = 0;

	virtual int path_cost() = 0;

};

#endif  // !defined _A_NODE_H_