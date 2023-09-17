/* Name: Tolga Han Arslan
    ID: 22003061
    section: 1
*/
#ifndef _BANKINGSYSTEM_H
#define _BANKINGSYSTEM_H
#include "Branch.h"
#include <string>
#include <iostream>
#include "Customer.h"  //customer class have access to account
class BankingSystem {
public :
    BankingSystem ();
    ~ BankingSystem ();

    void addBranch ( const int branchId , const string branchName );
    void deleteBranch ( const int branchId );

    void addCustomer ( const int customerId , const string customerName );
    void deleteCustomer ( const int customerId );

    int addAccount ( const int branchId , const int customerId , const double
    amount );
    void deleteAccount ( const int accountId );

    void showAllAccounts ();
    void showBranch ( const int branchId );
    void showCustomer ( const int customerId );
    int findBranchForAccount(const int accountId);        //returns branch index in branches for particular account
    int findCustomerForAccount(const int accountId);      //returns customer index in customers for particular account
private:
    Branch* branches;
    int numberOfBranches;
    Customer* customers;
    int numberOfCustomers;
    int accountIDcounter;        //unique id's for accounts
    int numberOfAccounts;          //total number of accounts on the system
    bool directDelete;           //flag to indicate deleteAccount called directly in main deleteBranch and deleteCustomer should not print "Account ... has been deleted"
};
#endif
