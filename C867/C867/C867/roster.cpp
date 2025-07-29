#include <iostream>
#include <array>
#include <string>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"

//put some underlines to make it pretty
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"


using namespace std;

//CONSTRUCT!!!!!
roster::roster() : roster_size(0)
{

}


//add function takes inputs from parse and converts to appropriate args and
//creates new student object and adds to classRosterArray

void roster::add(
	string student_id,
	string first_name,
	string last_name,
	string email,
	int age,
	int course_days1,
	int course_days2,
	int course_days3,
	DegreeProgram degree_program)
{
	
	if (roster_size < 5) {

		int course_days[3] = {course_days1, course_days2, course_days3};

		classRosterArray[roster_size] = new student(student_id, first_name, last_name, email, age, course_days, degree_program);
		roster_size++;
	}
	
	return;
	
}


//parsing input using stringstream and getline() delimiter of ","
void roster::parse(string studentData)
{
	stringstream ss(studentData);
	string token;
	DegreeProgram degree_program = DegreeProgram::SOFTWARE;

	getline(ss, token, ',');
	string student_id = token;

	getline(ss, token, ',');
	string first_name = token;

	getline(ss, token, ',');
	string last_name = token;

	getline(ss, token, ',');
	string email = token;

	getline(ss, token, ',');
	int age = stoi(token);

	int course_days[3];
	for (int i = 0; i < 3; i++)
	{
		getline(ss, token, ',');
		course_days[i] = stoi(token);
	}

	getline(ss, token, ',');
	string degree = token;
	
	//converts string to DegreeProgram to return to argument
	if (degree == "SECURITY")
		degree_program = DegreeProgram::SECURITY;
	else if (degree == "NETWORK")
		degree_program = DegreeProgram::NETWORK;
	else if (degree == "SOFTWARE")
		degree_program = DegreeProgram::SOFTWARE;

	//using add method to create student objects
	add(student_id, first_name, last_name, email, age, course_days[0], course_days[1], course_days[2], degree_program);
	
	return;
}

//remove by ID function
void roster::remove(string student_id)
{
	bool exist = false;
	cout << "\t" << endl;

	//if the student ID is the input we remove it and move back the pointers
	for (int i = 0; i < roster_size; i++)
		if (classRosterArray[i]->getstudent_id() == student_id) {
			cout <<UNDERLINE<< "Removing: " << student_id <<CLOSEUNDERLINE<< "\n";
			exist = true;
			delete classRosterArray[i];

			for (int j = i; j < roster_size; j++) {
				classRosterArray[j] = classRosterArray[j + 1];
			}

			roster_size--;
			cout << "ID: " << student_id << " is removed." << endl;
			break;
		}
	if (!exist) {
		cout <<UNDERLINE<< "Removing: " << student_id <<CLOSEUNDERLINE<< "\n";
		cout << "Student: " << student_id << " not found." << endl;
	}
}

//print all function
void roster::printAll()
{
	cout << "\t" << endl;
	cout <<UNDERLINE<<  "Printing All students in roster:" <<CLOSEUNDERLINE<< endl;
	//print each student object through iteration
	for (int i = 0; i < roster_size; i++) {
		classRosterArray[i]->print();
	}

	cout << "\t" << endl;
}

//search by student ID and return course day function from student.cpp
void roster::printAverageDaysInCourse(string student_id)
{
cout << "\t" << endl;
cout <<UNDERLINE<< "Printing average days of course time:" <<CLOSEUNDERLINE<< endl;

	//if the student ID is the input we print that course day average
	for (int i = 0; i < roster_size; i++) {
		if (classRosterArray[i]->getstudent_id() == student_id) {
			cout << "Printing " << classRosterArray[i]->getstudent_id() << " average days of course" << endl;
			cout << "Average Days in Course: " <<
				((classRosterArray[i]->get_coursedays()[0] +
					classRosterArray[i]->get_coursedays()[1] +
					classRosterArray[i]->get_coursedays()[2]) / 3)
				<< endl;
		}
	}

}

//print invalid emails
void roster::printInvalidEmails() 
{
	cout << "\t" << endl;
	cout <<UNDERLINE<< "Printing Invalid Emails:" <<CLOSEUNDERLINE<< endl;

	for (int i = 0; i < roster_size; i++) {
		string email_valid = classRosterArray[i]->get_email();

		if (email_valid.find('@') == string::npos) {
			cout << "Invalid Email: " << email_valid << endl;
		}
		else if (email_valid.find('.') == string::npos) {
			cout << "Invalid Email: " << email_valid << endl;
		}
		else if (email_valid.find(' ') != string::npos) {
			cout << "Invalid Email: " << email_valid << endl;
		}
	}
	
}

//print by degree program
void roster::printByDegreeProgram(DegreeProgram degree_program)
{
	cout << "\t" << endl;
	cout <<UNDERLINE<< "Printing by degree program SOFTWARE:" <<CLOSEUNDERLINE<< endl;
	for(int i = 0; i < roster_size; i++) {
		if (this->classRosterArray[i]->get_degreeprogram() == degree_program) {
			this->classRosterArray[i]->print();
		}
	}

}

//DESTRUCT!!!!
roster::~roster()
{
}