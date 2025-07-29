#include <iostream>
#include "student.h"

using namespace std;

//implement destructor

//construct and point
student::student(string student_id, string first_name, string last_name, string email, int age,  int course_days[], DegreeProgram degree_program)
{
	this->student_id = student_id;
	this->first_name = first_name;
	this->last_name = last_name;
	this->email = email;
	this->age = age;
	this->course_days[0] = course_days[0];
	this->course_days[1] = course_days[1];
	this->course_days[2] = course_days[2];
	this->degree_program = degree_program;
	

}

//setters and getters
string student::getstudent_id()
{
	return student_id;
}

void student::setstudent_id(string student_id)
{
	this->student_id = student_id;
}

string student::getfirst_name()
{
	return first_name;
}

void student::setfirst_name(string first_name)
{
	this->first_name = first_name;
}

string student::getlast_name()
{
	return last_name;
}

void student::setlast_name(string last_name)
{
	this->last_name = last_name;
}


string student::get_email()
{
	return email;
}

void student::set_email(string email)
{
	this->email = email;
}


int student::get_age()
{
	return age;
}

void student::set_age(int age)
{
	this->age = age;
}

DegreeProgram student::get_degreeprogram()
{
	return degree_program;
}

void student::set_degreeprogram(DegreeProgram degree_program)
{
	this->degree_program = degree_program;
}

int* student::get_coursedays()
{
	return course_days;
}

//need to change method input to each individual element?
void student::set_coursedays(int course_days[])
{
	for (int index = 0; index < 3; index++)
	{
		this->course_days[index] = course_days[index];
	}
}

//function to calculate average course days
float student::coursedays_average()
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < (sizeof(course_days) / sizeof(course_days[0])); i++) {
		sum = sum + course_days[i];
	}
	return sum / (sizeof(course_days) / sizeof(course_days[0]));
}

//printing
void student::print()
{
	cout << student_id << "\t";
	cout << "First name: " << first_name << "\t";
	cout << "Last name: " << last_name << "\t";
	cout << "Age: " << age << "\t";
	cout << "Days in Course: {";
	cout << course_days[0] << ", ";
	cout << course_days[1] << ", ";
	cout << course_days[2] << "} \t";
	cout << "Degree Program: ";
	switch (degree_program)
	{
	case DegreeProgram::SOFTWARE:
		cout << "Software";
		break;
	case DegreeProgram::NETWORK:
		cout << "Network";
		break;
	case DegreeProgram::SECURITY:
		cout << "Security";
		break;
	}
	cout << endl;
}

student::~student()
{
}