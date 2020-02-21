#include "client/Client.h"
#include "fringe/Fringe_Queue.h"
#include "fringe/Fringe_A_Star.h"
#include "problem/Problem.h"
#include "fringe/PriorityNode.h"
#include <random>
#include <ctime>
#include <chrono>

int main()
{
	//intial values
	std::array<int, 9> goal = { 1,2,3,4,5,6,7,8,0 };
	std::array<int, 9> initial;
	std::vector<int> numbers;
	unsigned seed;

	//runs 3 randomly generated puzzles
	for (int i = 0; i < 3; i++) {
		//generates random numbers for initial puzzle
		std::vector<int> numbers;
		seed = std::chrono::system_clock::now().time_since_epoch().count();
		for (int i = 0; i < 9; i++) {
			numbers.push_back(i);
		}//end for
		std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));
		for (int i = 0; i < 9; i++) {
			initial[i] = numbers[i];
		}//end for

		//print initial puzzle
		std::cout << "initial puzzle: ";
		for (int i = 0; i < 9; i++) {
			std::cout << initial[i];
		}//end for 
		std::cout << std::endl;

		Problem problem(initial, goal);
		if (problem.solvable(problem.initial_state()) == false) {
			std::cout << "unsolvable" << std::endl;
		}//end if
		else {

			//create new fringe
			std::priority_queue<PriorityNode,
				std::vector<PriorityNode>,
				std::greater<PriorityNode>> queue;
			Fringe_A_Star fringe(queue);

			//generate new client
			Client client(&fringe, &problem);
			client.run();
		}//end else
	}//end for


}

