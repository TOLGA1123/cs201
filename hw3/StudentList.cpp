/* Name: Tolga Han Arslan
   ID: 22003061
   Section: 1
*/
#include "StudentList.h"
#include "Student.h"
    StudentList::StudentList(){
        this->size = 0;
        this->head = nullptr;
    }
    /*StudentList::StudentList(const StudentList& aList){
        this->size = aList.size;
        this->head = nullptr;
        //Copy each node
        StudentNode* curPtr = aList.head;
        while(curPtr != nullptr){
            //Create a new node
            StudentNode* newChainPtr = new StudentNode;
            newChainPtr->student = curPtr->student;
            //Add the new node to the end of the list
            if(this->head == nullptr){
                //first node
                this->head = newChainPtr;
                newChainPtr->prev = nullptr;
            }
            else{
                //Link the new node to previous node
                newChainPtr->prev = curPtr->prev;
                curPtr->prev->next = newChainPtr;
            }
                //Link the new node to next node
            if(curPtr->next == nullptr){
                //last node
                newChainPtr->next = nullptr;
            }
            else{
                newChainPtr->next = new StudentNode;
                newChainPtr->next->prev = newChainPtr;
            }
            //Move to the next node in aList
            curPtr = curPtr->next;
        }
    }*/
    StudentList::~StudentList(){
        clear();        //implement remove and clear in slides
    }
    StudentList& StudentList::operator=(const StudentList& rhs) {
    if (this != &rhs) { // check for self-assignment
        // Clear existing list
        clear();

        // Copy size
        size = rhs.size;

        // Copy nodes
        if (rhs.head != nullptr) {
            // Copy the first node
            head = new StudentNode;
            head->student = rhs.head->student;

            // Copy remaining nodes
            StudentNode* newChainPtr = head;
            StudentNode* origPtr = rhs.head->next;
            while (origPtr != nullptr) {
                newChainPtr->next = new StudentNode;
                newChainPtr = newChainPtr->next;
                newChainPtr->student = origPtr->student;
                origPtr = origPtr->next;
            }
            newChainPtr->next = nullptr;
        }
    }
    return *this;
}

    bool StudentList::isEmpty() const{
        return size == 0;
    }
    int StudentList::getLength() const{
        return size;
    }
    StudentList::StudentNode* StudentList::getNodeAt(int position) const{
        if(position < 1 || position > this->getLength()){
            return nullptr;
        }
        else{
            StudentNode* curPtr = head;
            for(int skip = 1; skip < position; skip++){
                curPtr = curPtr->next;
            }
            return curPtr;
        }
    }
    bool StudentList::findStudent(int position, Student& student){
        if(position < 1 || position > this->getLength()){
            return false;
        }
        StudentNode* curPtr = this->getNodeAt(position);
        student = curPtr->student;
        return true;
    }
    bool StudentList::insert(int position, const Student aStudent){                                                                 //change insert and remove maybe????????
        if(position < 1 || position > this->getLength() + 1){     //+1 because of inserting new node to the last
            return false;
        }
        StudentNode* newNodePtr = new StudentNode;
        this->size++;
        newNodePtr->student = aStudent;
        if(position == 1){
                if(this->getLength() == 1){     //if it is first item
                    head = newNodePtr;
                    newNodePtr->next = nullptr;
                    newNodePtr->prev = nullptr;
                    return true;
                }
            head->prev = newNodePtr;
            newNodePtr->next = head;
            newNodePtr->prev = nullptr;
            head = newNodePtr;
        }
        else{
            StudentNode* prevPtr = getNodeAt(position - 1);                 //maybe change something here later
            newNodePtr->next = prevPtr->next;
            newNodePtr->prev = prevPtr;
            if(prevPtr->next != nullptr){
                prevPtr->next->prev = newNodePtr;
            }
            newNodePtr->prev->next = newNodePtr;
        }
        return true;
    }
    bool StudentList::remove(int position){
        if(position < 1 || position > this->getLength()){
            return false;
        }
        StudentNode* curPtr = nullptr;
        if(position == 1 && this->getLength() == 1){                      //if node to remove is first node and list contains 1 node
            curPtr = head;
            head = nullptr;
        }
        else if(position == 1 && this->getLength() > 1){                   //if node to remove is first node and list contains more than 1 node
            curPtr = head;
            head->next->prev = nullptr;
            head = head->next;
        }
        else if(position == this->getLength()){                             //if node to remove is last node
            curPtr = getNodeAt(position);
            curPtr->prev->next = nullptr;
        }
        else{
            curPtr = getNodeAt(position);
            curPtr->prev->next = curPtr->next;
            curPtr->next->prev = curPtr->prev;
        }
        this->size--;                               //changed this one's order memory issue solved somehow?
        curPtr->next = nullptr;
        curPtr->prev = nullptr;
        delete curPtr;
        curPtr = nullptr;
        return true;
    }
    void StudentList::clear(){
        while(!isEmpty()){
            this->remove(1);
        }
    }
    Student& StudentList::getStudent(const int studentId, bool& studentExists){
        studentExists = false;
        StudentNode* curPtr = head;
        while(curPtr != nullptr){
            if(curPtr->student.getStudentId() == studentId){
                studentExists = true;
                return curPtr->student;
            }
            curPtr = curPtr->next;
        }
        return emptyStudent;
    }

