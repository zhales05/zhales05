#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Student.h"
#include "Snap.h"
#include "Course.h"
#include "Csg.h"
#include "Cr.h"
#include "Cdh.h"

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

using namespace std;

int main(int argc, char* argv[])
{

	VS_MEM_CHECK               // enable memory leak check
	// Your program...

	if (argc < 3)
	{
		cerr << "Please provide name of input and output files";
		return 1;
	}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	cout << "Output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}

	string line;
	string line1;
	int left;
	int right;
	int comma;
	string resolve;
	string extract;

	string idString;
	string studentName;
	string studentAddress;
	string studentPhone;

	string courseName;
	string studentGrade;

	string day;
	string time;
	string room;
	
	vector<Snap*> snapVec;
	vector<Csg*> csgVec;
	vector<Cr*> crVec;
	vector<Cdh*> cdhVec;

	
	
	out << "Input Strings:" << endl;

	while (getline(in, line))  
	{
	
		left = line.find("(");
		right = line.find(")");
		
		resolve = line.substr(0,5);
		extract = line.substr((left + 1), (right - 1));

		try {

			if (resolve == "snap(")
			{
				out << line << endl;
				comma = extract.find(",");
				idString = extract.substr(0, comma);
								extract = extract.substr(comma + 1);

				comma = extract.find(",");
				studentName = extract.substr(0, comma);
				extract = extract.substr(comma + 1);

				comma = extract.find(",");
				studentAddress = extract.substr(0, comma);
				extract = extract.substr(comma + 1);

				comma = extract.find(")");
				studentPhone = extract.substr(0, comma);

				snapVec.push_back(new Snap(idString, studentName, studentAddress, studentPhone));
				
			}
			else if (resolve.substr(0, 4) == "csg(")
			{
				out << line << endl;
				comma = extract.find(",");
				courseName = extract.substr(0, comma);
				extract = extract.substr(comma + 1);

				comma = extract.find(",");
				idString = extract.substr(0, comma);
				extract = extract.substr(comma + 1);

				comma = extract.find(")");
				studentGrade = extract.substr(0, comma);

				csgVec.push_back(new Csg(courseName, idString, studentGrade));
				
			}

			else if (resolve.substr(0, 4) == "cdh(")
			{
				out << line << endl;
				comma = extract.find(",");
				courseName = extract.substr(0, comma);
				extract = extract.substr(comma + 1);

				comma = extract.find(",");
				day = extract.substr(0, comma);
				extract = extract.substr(comma + 1);

				comma = extract.find(")");
				time = extract.substr(0, comma);

				cdhVec.push_back(new Cdh(courseName, day, time));
				
				
			}
			else if (resolve.substr(0, 3) == "cr(")
			{
				out << line << endl;
				comma = extract.find(",");
				courseName = extract.substr(0, comma);
				extract = extract.substr(comma + 1);

				comma = extract.find(")");
				room = extract.substr(0, comma);

				crVec.push_back(new Cr(courseName, room));

			}

			else
			{
				throw line;
			}
		}

		catch (string e)
		{
			out << "**Error: " << e << endl;
		}

	}

	out << endl << "Vectors:" << endl;

	for (int i = 0; i < snapVec.size(); i++)
	{
		out << snapVec[i]->toString();
	}

	for (int i = 0; i < csgVec.size(); i++)
	{
		out << csgVec[i]->toString();

	}

	for (int i = 0; i < cdhVec.size(); i++)
	{
		out << cdhVec[i]->toString();
	}

	for (int i = 0; i < crVec.size(); i++)
	{
		out << crVec[i]->toString();
	}

	out << endl << "Course Grades: " << endl;

	string csgID;
	string snapID;
	string snapName;
	string csgCourse;
	string csgGrade;
	string csgName;
	string cdhName;
	string daySched;

	for (int k = 0; k < csgVec.size(); k++)
	{
		csgID = csgVec.at(k)->getStuId();

		for (int i = 0; i < snapVec.size(); i++)
		{
			snapID = snapVec.at(i)->getStudentId();

			if (csgID == snapID)
			{
				csgCourse = csgVec.at(k)->getCourse();
				csgGrade = csgVec.at(k)->getGrade();
				snapName = snapVec.at(i)->getStudentName();
			}
		}
		out << csgCourse << "," << snapName << "," << csgGrade << endl;
	}
	out << endl;
	out << "Student Schedules: " << endl;

	string snapAddress = "";
	string snapPhone = "";
	string cdhDay = "";
	string cdhTime = "";
	string cdhCourse = "";
	string crCourse = "";
	string crRoom = "";

	for (int i = 0; i < snapVec.size(); i++)
	{
		snapID = snapVec.at(i)->getStudentId();
		snapName = snapVec.at(i)->getStudentName();
		snapAddress = snapVec.at(i)->getStudentAddress();
		snapPhone = snapVec.at(i)->getPhone();

		out << snapName << ", " << snapID << ", " << snapAddress << ", " << snapPhone << endl;

		for (int k = 0; k < csgVec.size(); k++)
		{
			csgID = csgVec.at(k)->getStuId();
			if (csgID == snapID)
			{
				csgCourse = csgVec.at(k)->getCourse();
				for (int l = 0; l < cdhVec.size(); l++)
				{
					cdhCourse = cdhVec.at(l)->getCourseName();
					if (csgCourse == cdhCourse)
					{
						cdhDay = cdhDay + cdhVec.at(l)->getCourseDay();
						cdhTime = cdhVec.at(l)->getCourseTime();

					}
				}
				for (int j = 0; j < crVec.size(); j++)
				{
					crCourse = crVec.at(j)->getCourse();
					if (csgCourse == crCourse)
					{
						crRoom = crVec.at(j)->getRoomNum();

					}
				}
				out << csgCourse << " " << cdhDay << " " << cdhTime << ", " << crRoom << endl;
				cdhDay = "";
			}
		}

		out << endl;

	}


	for (int i = 0; i < snapVec.size(); ++i)
	{
		delete snapVec[i];
	}

	for (int i = 0; i < csgVec.size(); ++i)
	{
		delete csgVec[i];
	}

	for (int i = 0; i < crVec.size(); ++i)
	{
		delete crVec[i];
	}

	for (int i = 0; i < cdhVec.size(); ++i)
	{
		delete cdhVec[i];
	}

	return 0;
}