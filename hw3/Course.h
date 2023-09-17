/* Name: Tolga Han Arslan
   ID: 22003061
   Section: 1
*/
#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;
class Course{
    public:
        Course();
        Course(int courseId, string courseName);
        ~Course();
        int getCourseId();
        string getCourseName();

    private:
        int courseId;
        string courseName;
    };










#endif // COURSE_H
