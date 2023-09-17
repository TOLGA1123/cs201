/* Name: Tolga Han Arslan
   ID: 22003061
   Section: 1
*/
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;
    Course::Course(){
        this->courseId = 0;
        this->courseName = "";
    }
    Course::Course(int courseId, string courseName){
        this->courseId = courseId;
        this->courseName = courseName;
    }
    Course::~Course(){
    }
    int Course::getCourseId(){
        return courseId;
    }
    string Course::getCourseName(){
        return courseName;
    }
