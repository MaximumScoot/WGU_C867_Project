#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

int main()
{
    //output my info and class info
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Language Used: C++" << endl;
    cout << "Student ID: 011287611" << endl;
    cout << "Student Name: Maxim Scott" << endl;
    cout << "\t" << endl;

    //array of all students
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Maxim,Scott,msco659@wgu.edu,27,25,30,35,SOFTWARE"
    };

    roster classRoster; 

    //parses and then adds studentData to classRoster
    for (int i = 0; i < 5; i++) {
        classRoster.parse(studentData[i]);

    }

    //calling all the functions from roster (all the printing to cout is inline to function)
    classRoster.printAll();

    classRoster.printInvalidEmails();

    classRoster.printAverageDaysInCourse("A1");

    classRoster.printAverageDaysInCourse("A2");

    classRoster.printAverageDaysInCourse("A3");

    classRoster.printAverageDaysInCourse("A4");

    classRoster.printAverageDaysInCourse("A5");

    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE); 

    classRoster.remove("A3");
    
    classRoster.printAll();

    classRoster.remove("A3");
}

