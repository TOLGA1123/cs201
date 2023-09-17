/* Name: Tolga Han Arslan
    ID: 22003061
    section: 1
*/
#ifndef _BRANCH_H
#define _BRANCH_H
#include <string>
#include "Account.h"
using namespace std;
class Branch{
    public:
    Branch();
    Branch(int ID, string name);
    ~Branch();
    int getBranchID();
    string getBranchName();
    Account* branchAccounts;
    int branchAccountsSize;
    private:
    int branchID;
    string branchName;
};
#endif
