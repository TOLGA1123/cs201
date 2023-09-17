/* Name: Tolga Han Arslan
   ID: 22003061
   Section: 1
*/
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "CourseList.h"
using namespace std;
class Student{

    public:
        Student();
        Student(int studentId, string firstName, string lastName);
        ~Student();
        int getStudentId();
        string getFirstName();
        string getLastName();
        CourseList& getCourses();
    private:
        int studentId;
        string firstName;
        string lastName;
        CourseList courses;
};
#endif // STUDENT_H
