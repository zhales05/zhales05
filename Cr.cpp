#include "Cr.h"

string Cr::toString()
{
	ostringstream os;
	os << "cr(" << courseName << ", " << roomNum << ")" << endl;
	return os.str();
}

ostream& operator<< (ostream& os, Cr& d)
{
	return os << d.toString();
}

string Cr::getRoomNum()
{
	return roomNum;
}

string Cr::getCourse()
{
	return courseName;
}