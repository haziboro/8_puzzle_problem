#include "A_Problem.h"

#ifndef _PROBLEM_H_
#define _PROBLEM_H_

class Problem : public A_Problem

{
public:

	//constructor
	Problem(std::array<int, 9> initial, std::array<int, 9> goal);

	//returns initial state of problem
	std::array<int, 9> initial_state();

	//returns true if the problem is solvable
	bool solvable(std::array<int, 9> initial);

	//returns number of inversions in problem for use by solvable
	int inv_count(std::array<int, 9> initial);

	/**
	*Test if state of given node is equivalent to goal state
	*
	*@param[in]		state		state of node to evaluate
	*@retval		true		goal state achieved, call solution
	*@retval		false		goal state not achieved, continue to expand
	*
	**/
	bool goal_test(std::array<int, 9> state);

	/**
	* Takes the state given and returns the associated node
	*
	*@param[in]		state		state from problem to base first node from
	*@return		Node*		Node to act as root node for search tree
	*
	**/
	Node* make_node(std::array<int, 9> state);

	/**
	* Overload
	* Makes Node with more initial information specified
	*
	*@param[in]		parent		Parent Node
	*@param[in]		action		Action taken to create this node from parent
	*@param[in]		state		Node state
	*@return		Node*		Created Node
	*
	**/
	Node* make_node(Node* parent, int action, std::array<int, 9> state);

	//If goal state achieved, returns solution
	std::stack<Node*> solution(Node* solutionNode);

	//makes and return starting node

	/**
	*determine values needed to create successors nodes to the given state
	*
	*@param[in]		state		state of node to create successor values from
	*@return		list		list of possible actions and their resultant states
	*
	**/
	std::list<std::array<int,10>> successor_fn(std::array<int, 9> state);

	/**
	*calculates cost of taking a step between two nodes and sets the sum of the parent
	*Node's path cost and the computed step cost as the successor node's path cost
	*
	*@param[in]		parent			Parent Node of current Node
	*@param[in]		action			action taken by parent node to arrive at current node state
	*@param[in]		successor		current node
	*@return		int				step cost of the action
	*
	**/
	int step_cost(Node* parent, int action, Node* successor);

private:

	//Initial state and goal state for problem
	std::array<int, 9> initial_state_ ;
	std::array<int, 9> goal_state_;

	//number of actions for each tile from it's desired position given it's index
	//format: costs_[tile_num][index] == distance from goal
	int costs_[9][9] = {
		{ 4,3,2,3,2,1,2,1,0 },
		{ 0,1,2,1,2,3,2,3,4 },
		{ 1,0,1,2,1,2,3,2,3 },
		{ 2,1,0,3,2,1,4,3,2 },
		{ 1,2,3,0,1,2,1,2,3 },
		{ 2,1,2,1,0,1,2,1,2 },
		{ 3,2,1,2,1,0,3,2,1 },
		{ 2,3,4,1,2,3,0,1,2 },
		{ 3,2,3,2,1,2,1,0,1 },
	};//end costs

	//Allowed movements given blanks position. allowed movements give their new index, banned are 0's.
	//format: rules_[tile_idx][action_idx]. actions = {right,left,up,down}
	int moves_[9][4] = {
		{1,9,9,3},
		{2,0,9,4},
		{9,1,9,5},
		{4,9,0,6},
		{5,3,1,7},
		{9,4,2,8},
		{7,9,3,9},
		{8,6,4,9},
		{9,7,5,9},

	};//end rules

};

#endif  // !defined _PROBLEM_H_