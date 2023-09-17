/* Name: Tolga Han Arslan
ID: 22003061
Section: 1
*/
#ifndef ALGEBRAICEXPRESSION_H
#define ALGEBRAICEXPRESSION_H
using namespace std;
#include <string>       //these must be global functions according to pdf,       dont write class AlgebraicExpression public, they must be used in main directly
            // It converts an infix expression exp to its equivalent postfix form .
            string infix2postfix(const string exp);
            // It evaluates a postfix expression .
            double evaluatePostfix(const string exp);
            bool isOperator(const char ch);
            bool isOperand(const char ch);
            int precedence(const char ch);
            bool isOperand(const string ch);
            string evaluate(string& str1, string& str2, string op);
#endif // ALGEBRAICEXPRESSION_H
