#ifndef STUDENT_h
#define STUDENT_h

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Student
{
protected:
	string studentId = 0;
public:
	Student() {};
	~Student() {};

	Student(string s) : studentId(s) {};
};

#endif