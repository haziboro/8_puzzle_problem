//See Client.h for implementation details
#include "Client.h"

//Client
Client::Client(A_Fringe* fringe, A_Problem* problem)
	:fringe_(fringe),
	problem_(problem),
	tested_(new std::vector<std::array<int, 9>>)
{
	
}

void Client::run() 
{
	std::cout << "running..." << std::endl;
	std::stack<Node*> solution = tree_search(*problem_, *fringe_);

	if (solution.empty() == true) {
		std::cout << "Failure";
	}//end if
	else {
		int action;
		for (int i = 0;i < solution.size(); i++) {
			action = solution.top()->action();
			if (action == 0) {
				std::cout << "right, ";
			}
			else if (action == 1) {
				std::cout << "left, ";
			}
			else if (action == 2) {
				std::cout << "up, ";
			}
			else if (action == 3) {
				std::cout << "down, ";
			}
			solution.pop();
		}//end for
		std::cout << std::endl;
	}//end else
}

//tree_search
std::stack<Node*> Client::tree_search(A_Problem& problem, A_Fringe& fringe)
{
	insert(problem.make_node(problem.initial_state()),fringe); //insert initial node
	Node* cur_node;  //Node being worked on
	while (bool keepGoing = true){
		if(fringe.is_empty()){
			std::stack<Node*> emptyStack; //returns if search is failure
			return emptyStack;
			keepGoing = false;
		}//end if
		cur_node = remove_front(fringe); //pulls next node to analyze
		if (problem.goal_test(cur_node->state()) == true) { //returns if search is successful
			return problem.solution(cur_node);
			keepGoing = false;
		}//end if
		else {
			insert_all(expand(cur_node, problem), fringe); //expand node if it wasn't the solution, add successors to fringe
		}
	}//end while
	std::stack<Node*> emptyStack; //returns if search is failure
	return emptyStack;
}

//insert
void Client::insert(Node* initial_node, A_Fringe& fringe)
{
	fringe.add(initial_node);
	tested_->push_back(initial_node->state());
}

//remove_front
Node* Client::remove_front(A_Fringe& fringe)
{
	return fringe.remove();
}

//insert_all
void Client::insert_all(std::queue<Node*> expanded, A_Fringe& fringe)
{
	Node* node;
	while (expanded.empty() == false) {
		node = expanded.front();
		if (check_dupes(node->state()) == false) {
			fringe.add(node);
			tested_->push_back(node->state());
		}
		expanded.pop();
	}//end while
}

//expand
std::queue<Node*> Client::expand(Node* node, A_Problem& problem)
{
	std::queue<Node*> s; //queue of successors
	Node* new_node; //placeholder for new nodes

	//list of possible nodes to be created
	std::list<std::array<int,10>> ar_list = problem.successor_fn(node->state());

	//prevents the previous movement from being undone
	int banned_move;
	if (node->parent() == NULL) {
		banned_move = 9; //placeholder for first value
	}//end if
	else {
		banned_move = node->action();
		if (banned_move == 0){
			banned_move = 1;
		}
		else if (banned_move == 1) {
			banned_move = 0;
		}
		else if (banned_move == 2) {
			banned_move = 3;
		}
		else if (banned_move == 3) {
			banned_move = 2;
		}
	}//end if/else

	//placeholders for pulled state
	std::array<int, 9> state;
	std::array<int,10> pulled;
	int size = ar_list.size();
	for (int i = 0; i < size; i++) {
		pulled = ar_list.front();
		if (pulled[9] != banned_move) {
			for (int i = 0;i < 9;i++) {
				state[i] = pulled[i];
			}//end for
			//push created node to queue
			new_node = problem.make_node(node, pulled[9], state);
			problem.step_cost(node,pulled[9],new_node);
			s.push(new_node);
		}//end if
		ar_list.pop_front();
	}//end for
	return s;
}

//check_dupes
bool Client::check_dupes(std::array<int, 9> state)
{
	if (tested_->empty() == true) {
		return false;
	}
	std::array<int, 9> dupe_val;
	int size = tested_->size();
	for (int i = 0; i < size; i++) {
		for (std::vector<std::array<int, 9>>::size_type i = 0; i < tested_->size(); i++){
			dupe_val = tested_->at(i);
			if (check_copies(state, dupe_val) == true) {
				return true;
			}
		}
	}
	return false;
}

//check_copies
bool Client::check_copies(std::array<int, 9> x, std::array<int, 9> y)
{
	int yt;
	for (int i = 0;i < 9;i++) {
		yt = y[i];
		if (x[i] != y[i]) {
			return false;
		}
	}
	return true;
}