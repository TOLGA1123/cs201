/* Name: Tolga Han Arslan
   ID: 22003061
   Section: 1
*/
#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "Student.h"
class StudentList{
    public:
        StudentList();
        //StudentList(const StudentList& aList);
        ~StudentList();
        bool isEmpty() const;
        int getLength() const;
        bool findStudent(int position, Student& student);
        bool insert(int position, const Student aStudent);
        bool remove(int position);
        void clear();
        Student& getStudent(const int studentId, bool& studentExists);
        StudentList& operator=(const StudentList& rhs);
    private:
        struct StudentNode{
            Student student;
            StudentNode* prev;
            StudentNode* next;
        };
        int size;
        StudentNode* head;

        StudentNode* getNodeAt(int position) const;
        Student emptyStudent = Student();

};




#endif // STUDENTLIST_H
