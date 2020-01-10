#include "Snap.h"

string Snap::toString()
{
	ostringstream os;
	os << "snap(" << studentId << ", " << studentName << ", " << studentAddress << ", " << studentPhone << ")" << endl;
	return os.str();
}

ostream& operator<< (ostream& os, Snap& d)
{
	return os << d.toString();
}

string Snap::getStudentId()
{
	return studentId;
}

string Snap::getStudentName()
{
	return studentName;
}

string Snap::getStudentAddress()
{
	return studentAddress;
}

string Snap::getPhone()
{
	return studentPhone;
}