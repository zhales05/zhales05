#ifndef CDH_H
#define CDH_H
#include "Course.h"

class Cdh : public Course
{
private:
	string day;
	string time;

public:
	Cdh() {};
	~Cdh() {};

	Cdh(string cN, string d, string w) : Course(cN), day(d), time(w) {};

	string toString();
	friend ostream& operator<< (ostream& os, Cdh& d);
	string getCourseName();
	string getCourseDay();
	string getCourseTime();
};

#endif