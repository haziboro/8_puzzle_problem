#include "../problem/A_Problem.h"
#include "../fringe/A_Fringe.h"
#include "../node/Node.h"
#include <iostream>
#include <vector>


#ifndef _CLIENT_H_
#define _CLIENT_H_

//Client for managing interactions between problems and different data structures stored in fringe
class Client
{
public:

	//constructor
	Client(A_Fringe* fringe, A_Problem* problem);

	//initiates the search
	void run();

	/**
	* Attempts to find solution to given problem. Uses strategy according to fringe
	* 
	*@param[in]		problem		Problem to solve
	*@param[in]		fringe		Strategy to solve problem with, represented by data structure
	*@return		list		Returns list of steps that solves the problem, or empty list marking a failure
	*
	**/
	std::stack<Node*> tree_search(A_Problem & problem, A_Fringe & fringe);

	/**
	* Inserts the initial Node, created by the starting condition given by problem
	* 
	*@param[in]		initial_node		Node to insert, created by make_node
	*@param[in]		fringe				data structure to insert into
	* 
	**/
	void insert(Node * initial_node, A_Fringe & fringe);

	/**
	* Removes the node from fringe that is next in line for analysis
	* 
	*@param[in]		fringe				Data structure to remove node from
	*@return		Node*				Node that was removed
	* 
	**/
	Node * remove_front(A_Fringe & fringe);

	/**
	* Takes a queue of nodes produced by expand and inserts them in the fringe data structure
	*
	*@param[in]		expanded			queue of nodes
	*@param[in]		fringe				Data structure to add nodes to 
	* 
	**/
	void insert_all(std::queue<Node*> expanded, A_Fringe & fringe);

	/**
	* Creates a queue of successor nodes expanded from the given node
	*
	*@param[in]		node				Node to expand from
	*@param[in]		problem				gives instructions for how to create successor nodes
	*@return		queue				List of successor nodes generated
	* 
	**/
	std::queue<Node*> expand(Node* node, A_Problem & problem);

	//checks for duplicate states stored in tested_, returns true if duplicate found
	bool check_dupes(std::array<int, 9> state);

	//compares two arrays, returns true if they are the same
	bool check_copies(std::array<int, 9> x, std::array<int, 9> y);

private:

	//Concrete objects of Problem and Fringe
	A_Fringe * fringe_;
	A_Problem * problem_;
	//vector of tested values to prevent duplicate states
	std::vector<std::array<int, 9>> * tested_;

};

#endif  // !defined _CLIENT_H_