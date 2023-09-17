/* Name: Tolga Han Arslan
   ID: 22003061
   Section: 1
*/
#include "Student.h"
#include <iostream>
#include <string>
#include "CourseList.h"
using namespace std;
    Student::Student(){
        this->studentId = 0;
        this->firstName = "";
        this->lastName = "";
        courses = CourseList();
    }
    Student::Student(int studentId, string firstName, string lastName){
        this->studentId = studentId;
        this->firstName = firstName;
        this->lastName = lastName;
        courses = CourseList();
    }
    Student::~Student(){
    }
    int Student::getStudentId(){
        return studentId;
    }
    string Student::getFirstName(){
        return firstName;
    }
    string Student::getLastName(){
        return lastName;
    }
    CourseList& Student::getCourses(){
        return courses;
    }
