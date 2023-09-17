/* Name: Tolga Han Arslan
    ID: 22003061
    section: 1
*/
#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include <string>
using namespace std;
class Account{
    public:
    Account();
    Account(int id, double amount);
    //~Account();
    int getAccountID();
    double getAccountAmount();
    private:
    int ID;
    double amount;
};
#endif
