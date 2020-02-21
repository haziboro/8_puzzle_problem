#include "../node/Node.h"
#include <array>
#include <queue>
#include <stack>

#ifndef _A_PROBLEM_H_
#define _A_PROBLEM_H_

//interface for defining Problems
class A_Problem
{
public:

	virtual std::array<int, 9> initial_state() = 0;

	bool solvable(std::array<int, 9> initial);
	
	virtual bool goal_test(std::array<int, 9> state) = 0;

	virtual Node* make_node(std::array<int, 9> state) = 0;

	virtual Node* make_node(Node* parent, int action, std::array<int, 9> state) = 0;

	virtual std::stack<Node*> solution(Node* solutionNode) = 0;

	virtual std::list<std::array<int,10>> successor_fn(std::array<int, 9> state) = 0;

	//parent, action, successor
	virtual int step_cost(Node* parent, int action, Node* successor) = 0;

private:
	//prevent default construction, copy-contruction, and assignment outside of subclasses
	//A_Problem() {};
	//A_Problem(const A_Problem&) {};
	//const A_Problem& operator = (const A_Problem&) {};
};

#endif  // !defined _A_PROBLEM_H_