#include "Csg.h"

string Csg::toString()
{
	ostringstream os;
	os << "csg(" << courseName << ", " << studentId << ", " << studentGrade << ")" << endl;
	return os.str();
}

ostream& operator<< (ostream& os, Csg& d)
{
	return os << d.toString();
}

string Csg::getStuId()
{
	return studentId;
}

string Csg::getCourse()
{
	return courseName;
}

string Csg::getGrade()
{
	return studentGrade;
}