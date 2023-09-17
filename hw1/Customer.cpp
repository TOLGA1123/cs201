/* Name: Tolga Han Arslan
    ID: 22003061
    section: 1
*/
#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;
    Customer:: Customer(){
        customerID = 0;
        customerName = "";
        customerAccountsSize = 0;
        customerAccounts = nullptr;
    }
    Customer:: Customer(int customerID, string customerName){
        this->customerID = customerID;
        this->customerName = customerName;
        this->customerAccounts = nullptr;
        this->customerAccountsSize = 0;
    }
    Customer:: ~Customer(){             //customerAccountsSize > 0 crashes the program          individually calling addAccount and deleteAccount --> memory leak
        if(customerAccounts != nullptr && customerAccountsSize == 0){           // customerAccounts deleted with deleteAccount function, this destructor should delete empty array
            delete [] this->customerAccounts;       //not included --> memory leak but solves memory errors       //memory leak since account deleted by deleteAccount function in deleteCustomer
            customerAccounts = nullptr;
        }
        customerAccountsSize =0;
        customerAccounts = nullptr;
    }
    int Customer:: getCustomerID(){
        return customerID;
    }
    string Customer:: getCustomerName(){
        return customerName;
    }
