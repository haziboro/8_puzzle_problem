#include "../node/Node.h"

#ifndef _A_FRINGE_H_
#define _A_FRINGE_H_

//interface for defining Fringe data structures
class A_Fringe
{
public:

	virtual void add(Node*) = 0;

	virtual Node* remove() = 0;

	virtual bool is_empty() = 0;

private:
	//prevent default construction, copy-contruction, and assignment outside of subclasses
	//A_Fringe() {};
	//A_Fringe(const A_Fringe&) {};
	//const A_Fringe& operator = (const A_Fringe&) {};
};

#endif  // !defined _A_FRINGE_H_