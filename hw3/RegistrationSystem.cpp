/* Name: Tolga Han Arslan
   ID: 22003061
   Section: 1
*/
#include <iostream>
#include "RegistrationSystem.h"
using namespace std;
    RegistrationSystem::RegistrationSystem(){
        students = StudentList();
        coursesInSystem = CourseList();
    }
    RegistrationSystem::~RegistrationSystem(){
    }
    void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName){
        //if the student with the given Id already exists
        Student student;
        for(int i = 0; i <= students.getLength(); i++){
            students.findStudent(i, student);
            if(studentId == student.getStudentId()){
                cout << "Student " << student.getStudentId() << " already exists" << endl;
                return;
            }
        }
        Student newStudent(studentId, firstName, lastName);
        //find position to be added in order to list be sorted
        int position = 1;
        for(int i = 1; i <= students.getLength(); i++){
            students.findStudent(i, student);
            if(newStudent.getStudentId() > student.getStudentId()){
                position++;
            }
        }
        students.insert(position, newStudent);
        cout << "Student " << newStudent.getStudentId() << " has been added" << endl;
    }
    void RegistrationSystem::deleteStudent(const int studentId){                //seem to work fine
        bool studentExists = false;
        Student& student = students.getStudent(studentId, studentExists);
        if(!studentExists){
            cout << "Student " << studentId << " does not exist" << endl;
            return;
        }
        int position = 0;
        for(int i = 1; i <= students.getLength(); i++){
            Student temp;
            students.findStudent(i, temp);
            if(temp.getStudentId() == studentId){
                position = i;
                break;
            }
        }
        student.getCourses().clear();       //clear students courseList     if a course with no student enrolled --> continue holding it in coursesInSystem dont delete?
        //delete the course from the system if after student deletion, a course remains with no student enrolled
        for (int i = 1; i <= coursesInSystem.getLength(); i++) {
            Course tempCourse1;
            coursesInSystem.findCourse(i, tempCourse1);
            bool courseHasEnrolledStudents = false;
            for (int j = 1; j <= students.getLength(); j++) {
                Student tempStudent1;
                students.findStudent(j, tempStudent1);
                for (int k = 1; k <= tempStudent1.getCourses().getLength(); k++) {
                    Course tempCourse2;
                    tempStudent1.getCourses().findCourse(k, tempCourse2);
                    if (tempCourse2.getCourseId() == tempCourse1.getCourseId()) {
                        courseHasEnrolledStudents = true;
                        break;
                    }
                }
                if (courseHasEnrolledStudents) {
                    break;
                }
            }
            if (!courseHasEnrolledStudents) {
                coursesInSystem.remove(i);
                i--;
            }
        }
        students.remove(position);          //show course method shouldn't show deleted student
        cout << "Student " << studentId << " has been deleted" << endl;
    }
    void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName){

    // Check if student exists
    bool studentExists = false;
    Student& student = students.getStudent(studentId, studentExists);                        //these modifies local variables lists, not the actual objects  // try using reference functions from CourseList and StudentList

    if(!studentExists){
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }
    //now student with given id present in student object
    // Check if course with given id exists with a different name
    bool courseExists = false;                                                              //this is not used
    Course& course = student.getCourses().getCourse(courseId, courseExists);
    bool courseExistsWithDifferentName = false;
    for(int i = 1; i <= coursesInSystem.getLength(); i++){
        Course temp;
        coursesInSystem.findCourse(i, temp);
        if(temp.getCourseId() == courseId && temp.getCourseName() != courseName){
            courseExistsWithDifferentName = true;
            break;
        }
    }
    if(courseExistsWithDifferentName){
        cout << "Course " << courseId << " already exists with another name" << endl;
        return;
    }
    //Check if the student has already enrolled the course with given id
    bool isEnrolled = false;
    for(int i = 1; i <= student.getCourses().getLength(); i++){
        Course enrolledCourse;
        student.getCourses().findCourse(i, enrolledCourse);
        if(enrolledCourse.getCourseId() == courseId && enrolledCourse.getCourseName() == courseName){
            isEnrolled = true;
            break;
        }
    }
    if(isEnrolled){
        cout << "Student " << studentId << " is already enrolled in course " << courseId << endl;
        return;
    }
    Course newCourse(courseId, courseName);
    int position = 1;
            for(int i = 1; i <= student.getCourses().getLength(); i++){
                Course temp;
                student.getCourses().findCourse(i, temp);
                if(courseId > temp.getCourseId()){
                    position++;
                }
            }
    student.getCourses().insert(position, newCourse);           //gives true nothing wrong in position
    //if this course has not taken by any other students, add it to the coursesInSystem
    bool coursePresentInSystem = false;
    for(int i = 1; i <= coursesInSystem.getLength(); i++){
        Course courseInSystem;
        coursesInSystem.findCourse(i, courseInSystem);
        if(courseInSystem.getCourseId() == courseId){
            coursePresentInSystem = true;
            break;
        }
    }
    if(!coursePresentInSystem){
        coursesInSystem.insert(coursesInSystem.getLength() + 1 , newCourse);           //this list dont have to be sorted it just keep track of all courses in the system
    }
    cout << "Course " << newCourse.getCourseId() << " has been added to student " << student.getStudentId() << endl;
    }

    void RegistrationSystem::withdrawCourse(const int studentId, const int courseId){       //delete course for the students courseList, course should be hold in coursesInSystem?
        bool studentExists = false;
        Student& student = students.getStudent(studentId, studentExists);
        if(!studentExists){
            cout << "Student " << studentId << " does not exist" << endl;
            return;
        }
        /*bool courseExistsForSystem = false;                                               //course not exist  this check is assumed to be same as not enrolled in pdf
        Course& someCourse = coursesInSystem.getCourse(courseId, courseExistsForSystem);    //course 550 not exist = student 2000 is not enrolled in 550
        if(!courseExistsForSystem){
            cout << "Course " << courseId << " does not exist" << endl;
            return;
        }*/
        bool courseExistsForStudent = false;
        Course& course = student.getCourses().getCourse(courseId, courseExistsForStudent);
        if(!courseExistsForStudent){
            cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
            return;
        }
        int coursePosition = 0;
        for(int i = 1; i <= student.getCourses().getLength(); i++){
            Course temp;
            student.getCourses().findCourse(i, temp);
            if(temp.getCourseId() == course.getCourseId()){
                coursePosition = i;
                break;
            }
        }
        student.getCourses().remove(coursePosition);
        cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
        //making sure that if a course has no student enrolled, delete it from the coursesInSystem too
        bool courseHasStudentsEnrolled = false;
        for(int i = 1; i <= students.getLength(); i++){
            Student tempStudent;
            students.findStudent(i, tempStudent);
            for(int j = 1; j <= tempStudent.getCourses().getLength(); j++){
                Course tempCourse;
                tempStudent.getCourses().findCourse(j, tempCourse);
                if(tempCourse.getCourseId() == courseId){
                    courseHasStudentsEnrolled = true;
                    break;
                }

            }
        }
        int positionInSystem = 0;
        if(!courseHasStudentsEnrolled){                 //delete the course from system too if no students enrolled after withdrawal
            for(int i = 1; i <= coursesInSystem.getLength(); i++){
                Course course;
                coursesInSystem.findCourse(i, course);
                if(course.getCourseId() == courseId){
                    positionInSystem = i;
                    break;
                }
            }
            coursesInSystem.remove(positionInSystem);
        }
    }
    void RegistrationSystem::cancelCourse(const int courseId){  //courseExists -> check coursesInSystem not all students CourseLists ?  may be course present in system but not any student enrolled
        bool courseExists = false;                              //seems to work fine                                                //if course has no student enrolled, it should be deleted too
        for(int i = 1; i <= coursesInSystem.getLength(); i++){                                                                      //this done in withdrawCourse
            Course temp;
            coursesInSystem.findCourse(i, temp);
            if(temp.getCourseId() == courseId){
                courseExists = true;
                break;
            }
        }
        if(!courseExists){
            cout << "Course " << courseId << " does not exist" << endl;
            return;
        }
        //delete course from enrolled students courseList and coursesInSystem
        bool studentExists = false;
        int coursePosition = 0;
        for(int i = 1; i <= students.getLength(); i++){
            Student temp;
            students.findStudent(i, temp);
            Student& student = students.getStudent(temp.getStudentId(), studentExists);
            for(int j = 1; j <= student.getCourses().getLength(); j++){
                bool studentEnrolledCourse = false;
                Course temp;
                student.getCourses().findCourse(j, temp);
                if(temp.getCourseId() == courseId){
                    coursePosition = j;
                    break;
                }
            }
            student.getCourses().remove(coursePosition);
        }
        int positionInSystem = 0;
        for(int i = 1; i <= coursesInSystem.getLength(); i++){
            Course temp;
            coursesInSystem.findCourse(i, temp);
            if(temp.getCourseId() == courseId){
                positionInSystem = i;
                break;
            }
        }
        coursesInSystem.remove(positionInSystem);
        cout << "Course " << courseId << " has been cancelled" << endl;


    }
    void RegistrationSystem::showStudent(const int studentId){
        bool studentExists = false;
        Student& student = students.getStudent(studentId, studentExists);
        if(!studentExists){
            cout << "Student " << studentId << " does not exist" << endl;
            return;
        }
        cout << "Student id" << " First name" << " Last name" << endl;
        cout << student.getStudentId() << " " << student.getFirstName() << " " << student.getLastName() << endl;
        bool hasCourses = true;
        if(student.getCourses().getLength() == 0){
            hasCourses = false;
        }
        Course course;
        if(hasCourses){
            cout << "Course id" << " Course name" << endl;                          //if student has no courses this shouldn't be printed
        }
        for(int i = 1; i <= student.getCourses().getLength(); i++){
            student.getCourses().findCourse(i, course);
            cout << course.getCourseId() << " " << course.getCourseName() << endl;
        }
    }
    void RegistrationSystem::showCourse(const int courseId){
        bool courseExists = false;
        for(int i = 1; i <= coursesInSystem.getLength(); i++){
            Course temp;
            coursesInSystem.findCourse(i, temp);
            if(temp.getCourseId() == courseId){
                courseExists = true;
                break;
            }
        }
        if(!courseExists){
            cout << "Course " << courseId << " does not exist" << endl;
            return;
        }
        //show enrolled students by ascending ids --> students is already sorted by ascending ids
        cout << "Course id " << "Course name" << endl;
        Course& course = coursesInSystem.getCourse(courseId, courseExists);     //this modifies courseExists again but condition is already checked
        cout << course.getCourseId() << " " << course.getCourseName() << endl;
        cout << "Student id " << "First name " << "Last name" << endl;          //if no student enrolled print this?
        for(int i = 1; i <= students.getLength(); i++){
            Student tempStudent;
            students.findStudent(i, tempStudent);
            for(int j = 1; j <= tempStudent.getCourses().getLength(); j++){
                Course tempCourse;
                tempStudent.getCourses().findCourse(j, tempCourse);
                if(tempCourse.getCourseId() == course.getCourseId()){
                    cout << tempStudent.getStudentId() << " " << tempStudent.getFirstName() << " " << tempStudent.getLastName() << endl;
                }
            }
        }
    }
    void RegistrationSystem::showAllStudents(){
        if(students.isEmpty()){
            cout<< "There are no students in the system" << endl;
        }
        else{
            cout << "Student id " << "First name " << "Last name" << endl;
            for(int i = 1; i <= students.getLength(); i++){
                Student student;
                students.findStudent(i, student);
                cout << student.getStudentId() << " " << student.getFirstName() << " " << student.getLastName() << endl;
                if(student.getCourses().getLength() != 0){
                    cout << "Course id " << "Course name" << endl;
                    for(int j = 1; j <= student.getCourses().getLength(); j++){
                        Course course;
                        student.getCourses().findCourse(j, course);
                        cout << course.getCourseId() << " " << course.getCourseName() << endl;
                    }
                }
            }
            /*for(int i = 1; i <= coursesInSystem.getLength(); i++){                //this is for debugging of cancelCourse etc.
                Course temp;
                coursesInSystem.findCourse(i, temp);
                cout << "Course " << temp.getCourseId() << " " << temp.getCourseName() << endl;
            }*/
    }
    }
