/* Name: Tolga Han Arslan
   ID: 22003061
   Section: 1
*/
#include "RegistrationSystem.h"
int main (){
    RegistrationSystem rs;
    /*rs.addStudent(900, "Ahmet" ,"K");
    rs.addCourse(900, 100, "MATH123");
    rs.showCourse(100);
    rs.deleteStudent(900);
    rs.showCourse(100);                     //this course should be deleted
    */
    /*rs.showAllStudents();
    cout << endl ;
    rs.addStudent(2000 , "Kemal", "Ak");
    rs.addStudent(1000 , "Nuri", "Yazici");
    rs.addStudent(4000 , "Cengiz", "Erdem");
    rs.addStudent(3000 , "Osman", "Top");
    rs.addStudent(4000 , "Can", "Gezici");
    rs.addStudent(6000 , "Can", "Gezici");
    rs.addStudent(5000 , "Ali", "Akdere");
    rs.addStudent(7000 , "Burcin", "Temiz");
    cout << endl ;
    rs.showAllStudents();
    cout << endl ;
    rs.addCourse(321312432, 510, "CS510");
    rs.addCourse(2000 , 555 , "CS555");
    rs.addCourse(2000 , 540 , "CS540");
    rs.addCourse(2000 , 513 , "CS513");
    rs.addCourse(2000 , 524 , "CS524");
    rs.addCourse(3000 , 524 , "CS524");
    rs.addCourse(6000, 524, "CS124123124");         //second precheck
    rs.addCourse(3000 , 540 , "CS540");
    rs.addCourse(1000 , 540 , "CS540");
    rs.addCourse(1000 , 524 , "CS524");
    rs.addCourse(4000 , 524 , "CS524");
    rs.addCourse(4000 , 510 , "CS510");
    rs.addCourse(4000 , 540 , "CS540");
    rs.addCourse(4000 , 513 , "CS513");
    rs.addCourse(5000 , 510 , "CS510");
    rs.addCourse(5000 , 513 , "CS513");
    rs.addCourse(5000 , 540 , "CS540");
    rs.addCourse(6000 , 540 , "CS540");
    rs.addCourse(7000 , 510 , "CS510");
    rs.addCourse(7000 , 513 , "CS513");
    rs.addCourse(7000 , 540 , "CS540");
    rs.addCourse(3000 , 524 , "CS524");             //third precheck
    cout << endl ;
    rs.deleteStudent(5000) ;
    rs.deleteStudent(5000) ;
    cout << endl ;
    rs.showStudent(1000) ;
    rs.showStudent(3000) ;
    rs.showStudent(5000) ;
    cout << endl ;
    rs.showAllStudents();
    cout << endl ;
    rs.showStudent(3000);
    rs.withdrawCourse(3000 , 524) ;
    rs.withdrawCourse(2000 , 555) ;
    rs.withdrawCourse(2000 , 550) ;
    rs.withdrawCourse(3000, 21321);
    rs.withdrawCourse(10000 , 510) ;
    rs.showStudent(3000);
    cout << endl ;
    rs.cancelCourse(540) ;
    rs.cancelCourse(201) ;
    cout << endl ;
    rs.showAllStudents();
    rs.showCourse(524) ;
    rs.showCourse(540) ;
    rs.showStudent(7000) ;
    cout << endl ;
    rs.deleteStudent(7000) ;
    cout << endl ;
    rs.showStudent(3000) ;
    cout << endl ;
    rs.showAllStudents();
    cout << endl ; */

    //test1
    /*rs.addStudent(2000, "Kemal", "Ak");
    rs.addStudent(1000, "Nuri", "Yazici");
    rs.addStudent(4000, "Cengiz", "Erdem");
    rs.deleteStudent(4000);
    rs.deleteStudent(2000);
    rs.deleteStudent(2000);
    rs.deleteStudent(1000);
    rs.addStudent(2000, "Kemal", "Ak");
    rs.addStudent(1000, "Nuri", "Yazici");
    rs.addStudent(4000, "Cengiz", "Erdem");
    rs.addStudent(2000, "Kemal", "Ak");
    rs.addStudent(1000, "Nuri", "Yazici");
    rs.addStudent(4000, "Cengiz", "Erdem");
    */

    //test2
    /*rs.addStudent(1000, "Kemal", "Ak");
    rs.addCourse(1000, 555, "CS555");
    rs.addCourse(1000, 540, "CS540");
    rs.addCourse(1000, 540, "CS540");
    rs.addCourse(1000, 513, "CS513");
    rs.withdrawCourse(1000, 540);
    rs.withdrawCourse(1000, 513);
    rs.withdrawCourse(1000, 513);
    rs.withdrawCourse(1000, 555);
    rs.addCourse(1000, 555, "CS555");
    rs.addCourse(1000, 540, "CS540");
    rs.addCourse(1000, 513, "CS513");
    rs.addCourse(1000, 555, "CS555");
    rs.addCourse(1000, 540, "CS540");
    rs.addCourse(1000, 513, "CS513");
    rs.withdrawCourse(1000, 540);
    rs.withdrawCourse(1000, 513);
    rs.withdrawCourse(1000, 555);
    rs.withdrawCourse(1000, 540);
    rs.withdrawCourse(1000, 513);
    rs.withdrawCourse(1000, 555);
    */

    //test3
    /*rs.addStudent(2000, "Kemal", "Ak");
    rs.addStudent(1000, "Nuri", "Yazici");
    rs.addStudent(4000, "Cengiz", "Erdem");

    rs.addCourse(2000, 555, "CS555");
    rs.addCourse(2000, 555, "CS555");
    rs.addCourse(2000, 540, "CS540");

    rs.addCourse(1000, 555, "CS555");
    rs.addCourse(1000, 520, "CS520");
    rs.addCourse(1000, 540, "CS540");

    rs.addCourse(4000, 540, "CSS540");
    rs.addCourse(4000, 540, "CS540");

    rs.withdrawCourse(4000, 520);
    rs.withdrawCourse(1000, 520);
    rs.cancelCourse(520);
    rs.withdrawCourse(2000, 540);
    rs.withdrawCourse(1000, 540);
    rs.withdrawCourse(4000, 540);

    rs.addCourse(6000, 540, "CS540");
    rs.addCourse(4000, 540, "CSS540");
    rs.addCourse(4000, 540, "CS540");
    rs.addCourse(1000, 540, "CSS540");

    rs.cancelCourse(540);
    rs.withdrawCourse(1000, 540);
    rs.withdrawCourse(1000, 520);
    rs.withdrawCourse(1000, 555);
    */

    //test4
    /*rs.showAllStudents();

    rs.showStudent(2000);
    rs.addStudent(2000, "Kemal", "Ak");
    rs.showStudent(2000);

    rs.addStudent(1000, "Nuri", "Yazici");
    rs.addStudent(4000, "Cengiz", "Erdem");

    rs.showAllStudents();

    rs.showCourse(555);
    rs.addCourse(2000, 555, "CS555");
    rs.addCourse(2000, 540, "CS540");
    rs.showCourse(555);

    rs.showAllStudents();

    rs.addCourse(1000, 555, "CS555");
    rs.addCourse(1000, 540, "CS540");
    rs.withdrawCourse(1000, 510);
    rs.withdrawCourse(1000, 540);
    rs.showCourse(540);
    rs.showStudent(1000);

    rs.cancelCourse(540);
    rs.showCourse(540);

    rs.showAllStudents();
    */

    //test5
    /*rs.addStudent(1, "f1", "s1");
    rs.addStudent(2, "f2", "s2");
    rs.addStudent(3, "f3", "s3");
    rs.addStudent(4, "f4", "s4");
    rs.deleteStudent(1);
    rs.deleteStudent(2);
    rs.deleteStudent(3);
    rs.deleteStudent(4);

    rs.addStudent(1, "f1", "s1");
    rs.addStudent(2, "f2", "s2");
    rs.addStudent(3, "f3", "s3");
    rs.addStudent(4, "f4", "s4");
    rs.deleteStudent(4);
    rs.deleteStudent(4);
    rs.deleteStudent(3);
    rs.deleteStudent(3);
    rs.deleteStudent(2);
    rs.deleteStudent(2);
    rs.deleteStudent(1);
    rs.deleteStudent(1);

    rs.addStudent(4, "f4", "s4");
    rs.addStudent(3, "f3", "s3");
    rs.addStudent(2, "f2", "s2");
    rs.addStudent(1, "f1", "s1");

    rs.deleteStudent(2);
    rs.deleteStudent(4);
    rs.deleteStudent(1);
    rs.deleteStudent(3);

    rs.addStudent(1, "f1", "s1");
    rs.addStudent(2, "f2", "s2");
    rs.addStudent(3, "f3", "s3");
    rs.addStudent(4, "f4", "s4");
    rs.addCourse(1, 1, "1");
    rs.addCourse(2, 1, "1");
    rs.addCourse(3, 1, "1");
    rs.addCourse(4, 1, "1");
    rs.addCourse(1, 1, "1");
    rs.addCourse(2, 1, "1");
    rs.addCourse(3, 1, "1");
    rs.addCourse(4, 1, "1");
    rs.showAllStudents();
    rs.deleteStudent(1);
    rs.deleteStudent(2);
    rs.deleteStudent(3);
    rs.deleteStudent(4);
    rs.showAllStudents();

    rs.addStudent(1, "f1", "s1");
    rs.addStudent(2, "f2", "s2");
    rs.addStudent(3, "f3", "s3");
    rs.addStudent(4, "f4", "s4");
    rs.showAllStudents();
    rs.addCourse(1, 1, "1");
    rs.addCourse(2, 1, "1");
    rs.addCourse(3, 1, "1");
    rs.addCourse(4, 1, "1");
    rs.addCourse(1, 1, "2");
    rs.addCourse(2, 1, "2");
    rs.addCourse(3, 1, "2");
    rs.addCourse(4, 1, "2");
    rs.showAllStudents();
    rs.cancelCourse(1);
    rs.showAllStudents();
    rs.deleteStudent(1);
    rs.deleteStudent(2);
    rs.deleteStudent(3);
    rs.deleteStudent(4);
    */

    //test6
    /*rs.addStudent(1, "f1", "s1");
    rs.addCourse(1, 1, "c1");
    rs.addCourse(1, 2, "c2");
    rs.addCourse(1, 3, "c3");
    rs.addCourse(1, 4, "c4");
    rs.cancelCourse(1);
    rs.cancelCourse(2);
    rs.cancelCourse(3);
    rs.cancelCourse(4);

    rs.addCourse(1, 1, "c1");
    rs.addCourse(1, 2, "c2");
    rs.addCourse(1, 3, "c3");
    rs.addCourse(1, 4, "c4");
    rs.addCourse(1, 1, "c1");
    rs.addCourse(1, 2, "c2");
    rs.addCourse(1, 3, "c3");
    rs.addCourse(1, 4, "c4");
    rs.showCourse(1);
    rs.showCourse(2);
    rs.showCourse(3);
    rs.showCourse(4);
    rs.cancelCourse(4);
    rs.cancelCourse(4);
    rs.cancelCourse(3);
    rs.cancelCourse(3);
    rs.cancelCourse(2);
    rs.cancelCourse(2);
    rs.cancelCourse(1);
    rs.cancelCourse(1);

    rs.addStudent(1, "f1", "s1");
    rs.addStudent(2, "f2", "s2");
    rs.addCourse(1, 1, "c1");
    rs.addCourse(1, 2, "c2");
    rs.addCourse(1, 3, "c3");
    rs.addCourse(1, 4, "c4");
    rs.addCourse(1, 1, "c1");
    rs.addCourse(1, 2, "c2");
    rs.addCourse(1, 3, "c3");
    rs.addCourse(1, 4, "c4");

    rs.addCourse(2, 1, "c1");
    rs.addCourse(2, 2, "c2");
    rs.addCourse(2, 3, "c3");
    rs.addCourse(2, 4, "c4");
    rs.addCourse(2, 1, "c1");
    rs.addCourse(2, 2, "c2");
    rs.addCourse(2, 3, "c3");
    rs.addCourse(2, 4, "c4");
    rs.showAllStudents();
    rs.deleteStudent(2);
    rs.showAllStudents();
    rs.cancelCourse(1);
    rs.cancelCourse(2);
    rs.cancelCourse(3);
    rs.cancelCourse(4);
    rs.showAllStudents();
    */

    //test7
    /*rs.addStudent(1, "f1", "s1");
    rs.addCourse(1,1,"c1");
    rs.addCourse(1,2,"c2");
    rs.addCourse(1,3,"c3");
    rs.addCourse(1,4,"c4");
    rs.withdrawCourse(1, 4);
    rs.withdrawCourse(1, 4);
    rs.withdrawCourse(1, 3);
    rs.withdrawCourse(1, 3);
    rs.withdrawCourse(1, 2);
    rs.withdrawCourse(1, 2);
    rs.withdrawCourse(1, 1);
    rs.withdrawCourse(1, 1);
    rs.addCourse(1,1,"c1");
    rs.withdrawCourse(1, 1);
    rs.addCourse(20,1,"c1");

    rs.deleteStudent(1);
    rs.addCourse(1,1,"c1");
    rs.addCourse(1,1,"c1");
    rs.addStudent(1, "f1", "s1");
    rs.addCourse(1,1,"c1");
    rs.cancelCourse(1);
    rs.addCourse(1,1,"c1");
    rs.addCourse(1,1,"c1");
    rs.addCourse(1,1,"c11");
    rs.showCourse(1);
    rs.cancelCourse(1);
    rs.deleteStudent(1);

    rs.addCourse(1,1,"c1");
    rs.addCourse(1,2,"c2");
    rs.addCourse(1,3,"c3");
    rs.addStudent(1, "f1", "s1");
    rs.addStudent(2, "f2", "s2");
    rs.addStudent(3, "f3", "s3");

    rs.addCourse(1,1,"c1");
    rs.addCourse(1,2,"c2");
    rs.addCourse(1,3,"c3");
    rs.addCourse(2,1,"c1");
    rs.addCourse(2,2,"c2");
    rs.addCourse(2,3,"c3");
    rs.addCourse(3,1,"c1");
    rs.addCourse(3,2,"c2");
    rs.addCourse(3,3,"c3");
    rs.cancelCourse(1);
    rs.deleteStudent(2);

    rs.withdrawCourse(1, 1);
    rs.withdrawCourse(1, 2);
    rs.withdrawCourse(1, 3);
    rs.withdrawCourse(2, 1);
    rs.withdrawCourse(2, 2);
    rs.withdrawCourse(2, 3);
    rs.withdrawCourse(3, 1);
    rs.withdrawCourse(3, 2);
    rs.withdrawCourse(3, 3);
    */

    //test8
    /*rs.showAllStudents();
    rs.addStudent(1, "f1", "s1");
    rs.addStudent(2, "f2", "s2");
    rs.addStudent(3, "f3", "s3");
    rs.addStudent(4, "f4", "s4");
    rs.addCourse(1, 1, "c1");
    rs.addCourse(1, 2, "c2");
    rs.addCourse(1, 3, "c3");
    rs.addCourse(1, 4, "c4");
    rs.showCourse(1);
    rs.showCourse(2);
    rs.showCourse(3);
    rs.showCourse(4);
    rs.showStudent(1);
    rs.showStudent(2);
    rs.showStudent(3);
    rs.showStudent(4);

    rs.addCourse(2, 1, "c1");
    rs.addCourse(2, 2, "c2");
    rs.addCourse(2, 3, "c3");
    rs.addCourse(2, 4, "c4");

    rs.addCourse(3, 1, "c1");
    rs.addCourse(3, 2, "c2");
    rs.addCourse(3, 3, "c3");
    rs.addCourse(3, 4, "c4");

    rs.addCourse(4, 1, "c1");
    rs.addCourse(4, 2, "c2");
    rs.addCourse(4, 3, "c3");
    rs.addCourse(4, 4, "c4");

    rs.showAllStudents();
    rs.showCourse(1);
    rs.showCourse(2);
    rs.showCourse(3);
    rs.showCourse(4);
    rs.showStudent(1);
    rs.showStudent(2);
    rs.showStudent(3);
    rs.showStudent(4);

    rs.withdrawCourse(1, 1);
    rs.withdrawCourse(2, 2);
    rs.withdrawCourse(3, 3);
    rs.withdrawCourse(4, 4);

    rs.showAllStudents();
    rs.deleteStudent(1);
    rs.cancelCourse(1);
    rs.showAllStudents();
    rs.deleteStudent(2);
    rs.cancelCourse(2);
    rs.showAllStudents();

    rs.addCourse(1, 1, "c1");
    rs.addCourse(1, 2, "c2");
    rs.addCourse(1, 3, "c3");
    rs.addCourse(1, 4, "c4");

    rs.addCourse(2, 1, "c1");
    rs.addCourse(2, 2, "c2");
    rs.addCourse(2, 3, "c3");
    rs.addCourse(2, 4, "c4");

    rs.addCourse(3, 1, "c1");
    rs.addCourse(3, 2, "c2");
    rs.addCourse(3, 3, "c3");
    rs.addCourse(3, 4, "c4");

    rs.addCourse(4, 1, "c1");
    rs.addCourse(4, 2, "c2");
    rs.addCourse(4, 3, "c3");
    rs.addCourse(4, 4, "c4");

    rs.showCourse(1);
    rs.showCourse(2);
    rs.showCourse(3);
    rs.showCourse(4);
    rs.showStudent(1);
    rs.showStudent(2);
    rs.showStudent(3);
    rs.showStudent(4);
    rs.showAllStudents();
    rs.withdrawCourse(1, 1);
    rs.withdrawCourse(2, 1);
    rs.withdrawCourse(3, 1);
    rs.withdrawCourse(4, 1);
    rs.withdrawCourse(1, 2);
    rs.withdrawCourse(2, 2);
    rs.withdrawCourse(3, 2);
    rs.withdrawCourse(4, 2);
    rs.withdrawCourse(1, 3);
    rs.withdrawCourse(2, 3);
    rs.withdrawCourse(3, 3);
    rs.withdrawCourse(4, 3);
    rs.withdrawCourse(1, 4);
    rs.withdrawCourse(2, 4);
    rs.withdrawCourse(3, 4);
    rs.withdrawCourse(4, 4);
    rs.withdrawCourse(1, 5);
    rs.withdrawCourse(2, 5);
    rs.withdrawCourse(3, 5);
    rs.withdrawCourse(4, 5);

    rs.showCourse(1);
    rs.showCourse(2);
    rs.showCourse(3);
    rs.showCourse(4);
    rs.showStudent(1);
    rs.showStudent(2);
    rs.showStudent(3);
    rs.showStudent(4);
    rs.showAllStudents();
    */

    //test9
    for (int i = 1; i < 2000; i++){
            rs.addStudent(i, "f"+to_string(i), "s"+to_string(i));

    }
    for (int i = 1; i < 2000; i++){
            rs.addCourse(i, i, "c"+to_string(i));

    }

    return 0;
}
