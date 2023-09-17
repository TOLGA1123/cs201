/* Name: Tolga Han Arslan
   ID: 22003061
   Section: 1
*/
#ifndef REGISTRATIONSYSTEM_H
#define REGISTRATIONSYSTEM_H
#include <iostream>
#include "StudentList.h"
#include "Student.h"
#include "Course.h"
#include "CourseList.h"
using namespace std;
    class RegistrationSystem{
    public:
        RegistrationSystem();
        ~RegistrationSystem();

        void addStudent(const int studentId, const string firstName, const string lastName);
        void deleteStudent(const int studentId);
        void addCourse(const int studentId, const int courseId, const string courseName);
        void withdrawCourse(const int studentId, const int courseId);
        void cancelCourse(const int courseId);
        void showStudent(const int studentId);
        void showCourse(const int courseId);
        void showAllStudents();

    private:
        StudentList students;
        CourseList coursesInSystem;     //all courses in the system, students have their own courseLists sorted (this one is not sorted)
    };












#endif // REGISTRATIONSYSTEM_H
