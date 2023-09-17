/* Name: Tolga Han Arslan
    ID: 22003061
    section: 1
*/
#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <string>
using namespace std;
#include "Account.h"
class Customer{
    public:
    Customer();
    Customer(int ID, string name);
    ~Customer();
    int getCustomerID();
    string getCustomerName();
    Account* customerAccounts;      //customer's accounts array
    int customerAccountsSize;
    private:
    int customerID;
    string customerName;
};
#endif
