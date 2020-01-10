
#ifndef SNAP_H
#define SNAP_H
#include "Student.h"

class Snap : public Student
{
private:
	string studentName;
	string studentAddress;
	string studentPhone;

public:
	Snap(string stuId, string stuName, string stuAddress, string  stuPhone) : Student(stuId), studentName(stuName), studentAddress(stuAddress), studentPhone(stuPhone) {}
	~Snap() {}
	
	string toString();
	friend ostream& operator<< (ostream& os, Snap& d);
	
	string getStudentId();
	string getStudentName();
	string getStudentAddress();
	string getPhone();
};
#endif

