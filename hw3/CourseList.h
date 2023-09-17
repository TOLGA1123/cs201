/* Name: Tolga Han Arslan
   ID: 22003061
   Section: 1
*/
#ifndef COURSELIST_H
#define COURSELIST_H
#include "Course.h"
using namespace std;
//sorted linear singly linked list with no dummy head node
class CourseList{
    public:
        CourseList();
        //CourseList(const CourseList& aList);
        ~CourseList();
        bool isEmpty() const;
        int getLength() const;
        bool findCourse(int position, Course& course);
        bool insert(int position ,const Course aCourse);
        bool remove(int position);
        void clear();
        Course& getCourse(const int courseId, bool& courseExists);
        CourseList& operator=(const CourseList& rhs);
    private:
        struct CourseNode{
        Course course;
        CourseNode* next;
        };
        int size;
        CourseNode* head;
        CourseNode* getNodeAt(int position) const;
        Course emptyCourse = Course();
};

#endif // COURSELIST_H
