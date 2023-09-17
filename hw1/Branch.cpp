/* Name: Tolga Han Arslan
    ID: 22003061
    section: 1
*/
#include "Branch.h"
#include <iostream>
#include <string>
using namespace std;
    Branch:: Branch(){
        branchID = 0;
        branchName = "";
        branchAccountsSize = 0;
        branchAccounts = nullptr;
    }
    Branch:: Branch(int ID, string name){
        this->branchID = ID;
        this->branchName = name;
        this->branchAccountsSize = 0;
        this->branchAccounts = nullptr;   //heap corruption if not added
    }
    Branch:: ~Branch(){                     //customerAccountsSize > 0 crashes the program          individually calling addAccount and deleteAccount --> memory leak
        if(branchAccounts != nullptr && branchAccountsSize == 0){               //// branchAccounts deleted with deleteAccount function, this destructor should delete empty array
            delete [] this->branchAccounts;         //not included --> memory leak but solves memory errors       //memory leak since account deleted by deleteAccount function in deleteBranch
            branchAccounts = nullptr;
        }
        branchAccountsSize = 0;
        branchAccounts = nullptr;
    }
    int Branch::getBranchID(){
        return branchID;
    }
    string Branch::getBranchName(){
        return branchName;
    }
