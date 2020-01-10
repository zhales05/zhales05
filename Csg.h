#ifndef CSG_H
#define CSG_H

#include "Student.h"
#include "Course.h"
class Csg : public Student, public Course
{
private:
	string studentGrade;
public:
	Csg() {};
	~Csg() {};

	Csg(string cN, string sI, string sG) : Course(cN), Student(sI), studentGrade(sG) {};

	string toString();
	friend ostream& operator<< (ostream& os, Csg& d);

	string getStuId();
	string getCourse();
	string getGrade();
	
};
#endif