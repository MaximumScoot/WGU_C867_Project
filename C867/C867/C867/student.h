#pragma once
#include "degree.h"
#include <string>
#include <array>
using namespace std;

//declaring student class 


class student
{
private:
	string student_id;
	string first_name;
	string last_name;
	string email;
	int age;
	int course_days[3];
	DegreeProgram degree_program;
	
	

public:
	//construct
	student(string student_id, string first_name, string last_name, string email, int age, int course_days[], DegreeProgram degree_program);

	//getters and setters

	string getstudent_id();
	void setstudent_id(string student_id);

	string getfirst_name();
	void setfirst_name(string first_name);

	string getlast_name();
	void setlast_name(string last_name);

	string get_email();
	void set_email(string email);

	int get_age();
	void set_age(int age);

	DegreeProgram get_degreeprogram();
	void set_degreeprogram(DegreeProgram degree_program);

	int* get_coursedays();

	void set_coursedays(int input[]);

	float coursedays_average();

	//printing
	void print();

	//destructor
	~student();

};