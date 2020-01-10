#include "Cdh.h"
string Cdh::toString()
{
	ostringstream os;
	os << "cdh(" << courseName << ", " << day << ", " << time << ")" << endl;
	return os.str();
}

ostream& operator<< (ostream& os, Cdh& d)
{
	return os << d.toString();
}

string Cdh::getCourseName()
{
	return courseName;
}
string Cdh::getCourseDay()
{
	return day;
}

string Cdh::getCourseTime()
{
	return time;
}