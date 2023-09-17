/* Name: Tolga Han Arslan
    ID: 22003061
    section: 1
*/
#include "Account.h"
#include <iostream>
using namespace std;
    Account:: Account(){
        ID = 0;
        amount = 0;
    }
    Account:: Account(int id, double amount){
        this->ID = id;
        this->amount = amount;
    }
    /*Account::~Account(){
    */
    int Account::getAccountID(){
        return ID;
    }
    double Account::getAccountAmount(){
        return amount;
    }
