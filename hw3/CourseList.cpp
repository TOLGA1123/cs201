/* Name: Tolga Han Arslan
   ID: 22003061
   Section: 1
*/
#include "CourseList.h"
#include "Course.h"
    CourseList::CourseList(){
        this->size = 0;
        this->head = nullptr;
    }
    /*CourseList::CourseList(const CourseList& aList){
        this->size = aList.size;
        //if the original list is empty so is copy
        if(aList.head == nullptr){
            this->head = nullptr;
        }
        else{
            //copy the first node
            this->head = new CourseNode;
            this->head->course = aList.head->course;
            //Copy remaining nodes
            CourseNode* newChainPtr = head;
            for(CourseNode* origPtr = aList.head->next; origPtr != nullptr; origPtr = origPtr->next){
                newChainPtr->next = new CourseNode;
                newChainPtr = newChainPtr->next;
                newChainPtr->next = origPtr->next;
                }
            newChainPtr->next = nullptr;
            }
        } */
    CourseList::~CourseList(){
        clear();            //implement remove and clear in slides
    }
    CourseList& CourseList::operator=(const CourseList& rhs) {
    if (this != &rhs) { // check for self-assignment
        // Clear existing list
        clear();

        // Copy size
        size = rhs.size;

        // Copy nodes
        if (rhs.head != nullptr) {
            // Copy the first node
            head = new CourseNode;
            head->course = rhs.head->course;

            // Copy remaining nodes
            CourseNode* newChainPtr = head;
            CourseNode* origPtr = rhs.head->next;
            while (origPtr != nullptr) {
                newChainPtr->next = new CourseNode;
                newChainPtr = newChainPtr->next;
                newChainPtr->course = origPtr->course;
                origPtr = origPtr->next;
            }
            newChainPtr->next = nullptr;
        }
    }
    return *this;
}

    bool CourseList::isEmpty() const{
        return (size == 0);
    }
    int CourseList::getLength() const{
        return size;
    }
    CourseList::CourseNode* CourseList::getNodeAt(int position) const{
        if(position < 1 || position > this->getLength()){
           return nullptr;
           }
        else{
            CourseNode* curPtr = head;
            for(int skip = 1; skip < position; skip++){
                curPtr = curPtr->next;
            }
            return curPtr;
        }
    }
    bool CourseList::findCourse(int position, Course& course){
        if(position < 1 || position > this->getLength()){
            return false;
        }
        CourseNode* curPtr = this->getNodeAt(position);
        course = curPtr->course;
        return true;
    }
    bool CourseList::insert(int position, Course aCourse){
        if(position < 1 || position > getLength() + 1){         //+1 since adding end
            return false;
        }
        CourseNode* newNodePtr = new CourseNode;
        this->size++;
        newNodePtr->course = aCourse;
        if(position == 1){
            newNodePtr->next = head;
            head = newNodePtr;
        }
        else{
            CourseNode* prevPtr = getNodeAt(position - 1);
            newNodePtr->next = prevPtr->next;
            prevPtr->next = newNodePtr;
        }
        return true;
    }
    bool CourseList::remove(int position){
        if(position < 1 || position > getLength()){
            return false;
        }
        CourseNode* curPtr = nullptr;
        this->size--;
        if(position == 1){
            curPtr = head;
            head = head->next;
        }
        else{
            CourseNode* prevPtr = getNodeAt(position - 1);
            curPtr = prevPtr->next;
            prevPtr->next = curPtr->next;
        }
        curPtr->next = nullptr;
        delete curPtr;
        curPtr = nullptr;
        return true;
    }
    void CourseList::clear(){
        while(!isEmpty()){
            this->remove(1);
        }
    }
    Course& CourseList::getCourse(const int courseId, bool& courseExists){
        courseExists = false;
        CourseNode* curPtr = head;
        while(curPtr != nullptr){
            if(curPtr->course.getCourseId() == courseId){
                courseExists = true;
                return curPtr->course;
            }
            curPtr = curPtr->next;
        }
        return emptyCourse;
    }


