#pragma once
#include <array>
#include <sstream>
#include "student.h"
#include "degree.h"

using namespace std;

//making the roster signatures
class roster
{
public:

	roster();

	~roster();

	student* classRosterArray[5];
	int roster_size;

	void add(string student_id, string first_name, string last_name, string email,
		int age, int course_days1, int course_days2, int course_days3, DegreeProgram degree_program);

	void parse(string studentData);

	void remove(string student_id);

	void printAll();

	void printAverageDaysInCourse(string student_id);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degree_program);

	

};
