/* Name: Tolga Han Arslan
ID: 22003061
Section: 1
*/
#include <iostream>
using namespace std;
#include "AlgebraicExpression.h"
int main () {
    cout << infix2postfix("(3+5)-8*4") << endl ;        //these must be global functions
    cout << evaluatePostfix("653-8*+2/") << endl ;
    cout << infix2postfix("") << endl;
    cout << infix2postfix("1") << endl;
    cout << evaluatePostfix("876*543*2**-1+9+") << endl;
    cout << infix2postfix("( 3+5)- 8*4") << endl;
    cout << evaluatePostfix("6 5 3-8 *+2 /") << endl;
    cout << infix2postfix("(1+2) +(3 - (3*4)) ") << endl;
    cout << infix2postfix("3^4") << endl;
    cout << infix2postfix("34*32") << endl;
    return 0;
}
