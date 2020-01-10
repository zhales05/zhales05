#ifndef CR_H
#define CR_H
#include "Course.h"

class Cr: public Course
{
private:
	string roomNum;
public:
	Cr() {};
	~Cr() {};

	Cr(string cN, string room) : Course(cN), roomNum(room){};

	string toString();
	friend ostream& operator<< (ostream& os, Cr& d);
	string getRoomNum();
	string getCourse();
};
#endif
