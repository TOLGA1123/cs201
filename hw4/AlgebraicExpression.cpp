/* Name: Tolga Han Arslan
ID: 22003061
Section: 1
*/
#include "AlgebraicExpression.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;


    //function that converts infix expression to postfix, implemented with pseudocode algorithm in slides
    string infix2postfix (const string exp){
       string postfix = "";
       stack <char> operatorStack;
       char ch;
       if(exp.empty()){
        return postfix;
       }
       for(unsigned int i = 0; i < exp.length(); i++){
            ch = exp[i];
            if(isOperand(ch)){                      //assumption is only 1-9 single digit operands, other inputs might crash idk
                postfix += ch;
            }
            else if(ch == '('){
                operatorStack.push(ch);
            }
            else if(ch == ')'){
                while(operatorStack.top() != '('){
                        postfix += operatorStack.top();
                        operatorStack.pop();        //pop stack until matching '('
                      }
                operatorStack.pop();                //remove the open parenthesis
            }
            else if(ch == ' '){                     //if space
                continue;
            }
            else{                                   //isOperator(ch)
                while(!operatorStack.empty() && operatorStack.top() != '(' && (precedence(ch) <= precedence(operatorStack.top()))){
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(ch);
                }
            }
             while(!operatorStack.empty()){
                postfix += operatorStack.top();
                operatorStack.pop();
            }
       return postfix;
    }
    //function that evaluates postfix expressions, implemented with pseudocode algorithm in slides
    double evaluatePostfix (const string exp){
        string result;
        stack<string> operandStack;         //this stack is string not char since it can exceed one digit like 4*5 = 20
        string str;
        if(exp.empty()){
            return -1;
        }
        for(unsigned int i = 0; i < exp.length(); i++){
            str = exp[i];
            if(isOperand(str)){
                operandStack.push(str);
            }
            else if(str == " "){        //if space
                continue;
            }
            else{
                string value2 = operandStack.top();
                operandStack.pop();
                string value1 = operandStack.top();             // pop reverse order from the stack like in slide
                operandStack.pop();
                result = evaluate(value1, value2, str);
                operandStack.push(result);
            }
        }
        result = operandStack.top();
        return std::stod(result);
    }
    //operators are only +-*/ by assumption
    bool isOperator(const char ch){
        return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/');
    }
    //operands are single digits 1-9 by assumption
    bool isOperand(const char ch){         //here compare with chars not integers
        return (ch > '0' && ch <= '9');
    }
    //operands are single digits 1-9 by assumption
    bool isOperand(const string ch){         //here compare with chars not integers
        return (ch > "0" && ch <= "9");                            // operands are single digits 1-9, dont need to check exceeded values since check is only for fetching operands first
    }
    int precedence(const char ch){
        if(isOperator(ch)){
            if(ch == '+' || ch == '-'){ return 1; }
            else if(ch == '*' || ch == '/'){ return 2; }
            else {return -1; }
        }
        return -1;
    }
    //cast strings to double, evaluate the expression, return string
    string evaluate(string& str1, string& str2, string op){
        double value1 = std::stod(str1);
        double value2 = std::stod(str2);
        double result;
        if(op == "+"){
            result = value1 + value2;
        }
        else if(op == "-"){
            result = value1 - value2;
        }
        else if(op == "*"){
            result = value1 * value2;
        }
        else if(op == "/"){
            result = value1 / value2;
        }
        else{
            result = -1;
        }
        return std::to_string(result);
    }
