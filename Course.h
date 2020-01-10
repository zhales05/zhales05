#ifndef COURSE_h
#define COURSE_h

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Course
{
protected:
	string courseName;
public:
	Course() {};
	~Course() {};

	Course(string c) : courseName(c){};
	
};

#endif
