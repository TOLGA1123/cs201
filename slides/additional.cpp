// Consider the following Student class definition.
class Student {
public:
    Student() {grades = new int[5]; }
    ~Student() { delete [] grades; }
    double getGPA() const 	        { return gpa; 	}
    int getId() const 			{ return id; 	}
    void setGPA( const double g ) 	{ gpa = g; 	}
    void setId( const int i ) 		{ id = i;       }

private:
    int id;
    double gpa;
    int* grades;
};



// Write a global function that returns an array of Students with gpa >= 3.0.
// Your function returns this list together with its size.
Student* honorList( const Student* arr, const int arrSize, int& hsize) {
    hsize = 0;

    // empty input array?
    if ( arrSize == 0)
	return nullptr;

    for (int i = 0; i < arrSize; i++)
	if (arr[i].getGPA() >= 3.0)
	    hsize++;

    // non-empty array, but no Student with gpa >= 3.0
    if (hsize == 0)
	return nullptr;

    // Student hlist[hsize];   // DON'T DO IT!
    Student* hlist = new Student[hsize];        //   any member function call?  default const hsize times called
    for (int i = 0, j = 0; i < arrSize; i++)
	if (arr[i].getGPA() >= 3.0)
	    hlist[ j++ ] = arr[i];   //  assignment op called

    return hlist;
}

/*
   Consider different alternatives. Implement them as an exercise. How to call these functions?

   void honorList_2( const Student* arr, const int arrSize, Student** hl, int* hlSize);
   void honorList_3( const Student* arr, const int arrSize, Student*& hl, int& hlSize);
*/


// Write a global function that deletes the student with a given index from an existing student array.
// Assume array is non-empty and sindex is a valid index: 0 <= sindex <= (arrSize-1)
void deleteStudent(Student** arr, int* arrSize, const int sindex) {

    // delete (*arr)[sindex];    // very wrong

    // 1-item will be removed => input array will be empty
    if (*arrSize == 1) {
	delete [] *arr;
	*arr = nullptr;
	*arrSize = 0;
    }
    else {
	Student* oldArray = *arr;
	*arr = new Student[*arrSize - 1];
	for (int i = 0; i < sindex; i++)
	    (*arr)[i] = oldArray[i];
	// skip the one at index sindex
	for (int i = sindex+1; i < *arrSize; i++)
	    (*arr)[i-1] = oldArray[i];
	(*arrSize)--;
	delete [] oldArray;
    }
}

void deleteStudent2(Student** arr, int* arrSize, const int sindex) {

    // delete (*arr)[sindex];    // very wrong

    // 1-item will be removed => input array will be empty
    if (*arrSize == 1) {
	delete [] *arr;
	*arr = nullptr;
	*arrSize = 0;
    }
    else {
	Student* newArray = new Student[*arrSize-1];
	for (int i = 0; i < sindex; i++)
	    newArray[i] = *arr[i];
	// skip the one at index sindex, copy the rest
	for (int i = sindex+1; i < *arrSize; i++)
	    newArray[i-1] = *arr[i];

	(*arrSize)--;

	// update *arr
	delete [] *arr;    // order of this and the next statment is important!  first delete *arr to release old array then use it to point to new array
	*arr = newArray;
    }
}


// Consider the following School class definition.
class School{
public:
    School(){
	stuNo = 0;
	stu = nullptr;
    }
    ~School(){
	delete [] stu;
    }

    void addStudent( const int newId, const double newGPA );

private:
    int stuNo;
    Student* stu;
};

// Write a member function for this class that adds a new student to the end of its student array.
void School::addStudent( const int newId, const double newGPA ) {

    Student* temp = stu;

    stu = new Student [ stuNo + 1];     // new array created with +1 size // last item is default constructor 
    for ( int i = 0; i < stuNo; i++ )
	stu[i] = temp[i];

    stu[stuNo].setId(newId);            //modifying last element (default created)
    stu[stuNo].setGPA(newGPA);

    delete [] temp;

    stuNo++;
}



















