/* Name: Tolga Han Arslan
    ID: 22003061
    section: 1
*/
/* Have memory leaks that I couldn't solve because of bad design */ //deleteBranch and deleteCustomer should have different methods for deleting their accounts to solve memory leaks
#include "BankingSystem.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
    BankingSystem::BankingSystem()
    {
        numberOfBranches = 0;
        branches = nullptr;         //branches array
        numberOfCustomers = 0;
        customers = nullptr;        //customers array
        accountIDcounter = 1;       //to give account id's      total number of accounts in the system  if deleted -->> dont change it
        //customerAccountsSize, branchAccountsSize
        numberOfAccounts = 0;
        directDelete = true;
    }

    BankingSystem::~BankingSystem()
    {
            if(this->branches != nullptr && numberOfBranches >0){
                delete [] this->branches;
                numberOfBranches = 0;
            }
            if(this->customers != nullptr && numberOfCustomers > 0){
                delete [] this->customers;
                numberOfCustomers = 0;
            }
            numberOfAccounts = 0;
            accountIDcounter = 1;
    }

    void BankingSystem::addBranch(const int branchId, const string branchName)
    {
        bool branchExist = false;
        for(int i = 0; i < numberOfBranches; i++){
            if(branches[i].getBranchID() == branchId){
                branchExist = true;
            }
        }
        if(branchExist){
            cout<< "Branch " << branchId << " already exists" << endl;
            return;
        }

            Branch* newBranches = new Branch[numberOfBranches + 1];
            for(int i = 0; i<numberOfBranches; i++){
                newBranches[i] = branches[i];
            }
            newBranches[numberOfBranches] = Branch(branchId, branchName);
            this->numberOfBranches++;
            delete [] branches;
            this->branches = newBranches;

        cout<< "Branch " <<branchId << " has been added" <<endl;
    }
    void BankingSystem::deleteBranch ( const int branchId ){
        bool branchExists = false;
        for(int i = 0; i<numberOfBranches; i++){
            if(branches[i].getBranchID() == branchId){
                branchExists = true;
            }
        }
        if(!branchExists){
            cout << "Branch " <<branchId << " does not exist" <<endl;
            return;
        }

            for(int i = 0; i < numberOfBranches; i++){
            if(branches[i].getBranchID() == branchId){
                for(int x = 0; x < branches[i].branchAccountsSize; x++){        //after calling deleteAccount once branchAccountsSize -1 and last account could not be deleted here. // no problem 3 loop occur
                    directDelete = false;
                    deleteAccount(branches[i].branchAccounts[x].getAccountID());
                    directDelete = true;
                    x--;                        // make sure that all accounts are deleted
                }
                //branches[i].branchAccounts = nullptr;
                //branches[i].branchAccountsSize = 0;
            }
        }

        Branch* newBranches = new Branch[numberOfBranches -1];
        int j = 0;
        for(int i = 0; i<numberOfBranches; i++){
            if(branches[i].getBranchID() != branchId){
                newBranches[j] = branches[i];
                j++;
            }
        }
        this->numberOfBranches--;
        delete [] branches;   //causes invalid memory read + invalid free() ///////////////////////////////////
        this->branches = newBranches;
        cout<< "Branch " << branchId << " has been deleted" <<endl;
        }
        void BankingSystem::addCustomer ( const int customerId , const string customerName ){
            bool customerExist = false;
            for(int i = 0; i < numberOfCustomers; i++){
                if(customers[i].getCustomerID() == customerId){
                    customerExist = true;
                }
            }
            if(customerExist){
                cout<< "Customer " << customerId << " already exists" <<endl;
                return;
            }
            Customer* newCustomers = new Customer[numberOfCustomers + 1];
            for(int i = 0; i < numberOfCustomers; i++){
                newCustomers[i] = customers[i];
            }
            newCustomers[numberOfCustomers] = Customer(customerId, customerName);
            delete [] customers;
            this-> customers = newCustomers;
            this-> numberOfCustomers++;
            cout<< "Customer " << customerId << " has been added" << endl;
        }
        void BankingSystem::deleteCustomer ( const int customerId ){
            bool customerExists = false;
            for(int i = 0; i < numberOfCustomers; i++){
                if(customers[i].getCustomerID() == customerId){
                    customerExists = true;
                }
            }
            if(!customerExists){
                cout<< "Customer " << customerId << " does not exist" << endl;
                return;
            }
            //deleting customer accounts for particular customer
            for(int i = 0; i < numberOfCustomers; i++){
                if(customers[i].getCustomerID() == customerId){
                    for(int x = 0; x < customers[i].customerAccountsSize; x++){
                        directDelete = false;
                        deleteAccount(customers[i].customerAccounts[x].getAccountID());
                        directDelete = true;
                        x--;                        // make sure that all accounts are deleted
                    }
                    //customers[i].customerAccounts = nullptr;
                    //customers[i].customerAccountsSize = 0;
                }
            }
            Customer* newCustomers = new Customer[numberOfCustomers -1];
            int j = 0;
            for(int i = 0; i < numberOfCustomers; i++){
                if(customers[i].getCustomerID() != customerId){
                    newCustomers[j] = customers[i];
                    j++;
                }
            }
            this-> numberOfCustomers--;
            delete [] customers;
            this-> customers = newCustomers;
            cout << "Customer " << customerId << " has been deleted" << endl;
        }
        //customer's account arrays in customer class //branch's account arrays in branch class    add both
        int BankingSystem::addAccount ( const int branchId , const int customerId , const double amount ){
            bool branchExists = false;
            bool customerExists = false;
            int branchIndex;
            int customerIndex;
            for(int i = 0; i < numberOfBranches; i++){
                if(branches[i].getBranchID() == branchId){
                    branchExists = true;
                    branchIndex = i;
                }
            }
            for(int i = 0; i < numberOfCustomers; i++){
                if(customers[i].getCustomerID() == customerId){
                    customerExists = true;
                    customerIndex = i;
                }
            }
            if(!branchExists){
                cout << "Branch " << branchId << " does not exist" << endl;
                return -1;
            }
            if(!customerExists){
                cout<< "Customer " << customerId << " does not exist" << endl;              //Customer[i].branchAccountsSize change etc which customers array
                return -1;
            }
            //if both branch and customer exist
            Account* newBranchAccountsAfterAdd = new Account[branches[branchIndex].branchAccountsSize + 1];       //account added for a branch
            Account* newCustomerAccountsAfterAdd = new Account[customers[customerIndex].customerAccountsSize + 1];  //account added for a customer
            for(int i = 0; i < numberOfBranches; i++){
                if(branches[i].getBranchID() == branchId){
                    for(int j = 0; j < branches[branchIndex].branchAccountsSize; j++){
                        newBranchAccountsAfterAdd[j] = branches[branchIndex].branchAccounts[j];
                    }
                }
            }
            newBranchAccountsAfterAdd[branches[branchIndex].branchAccountsSize] = Account(accountIDcounter, amount);
            for(int i = 0; i < numberOfCustomers; i++){
                if(customers[i].getCustomerID() == customerId){
                    for(int j = 0; j < customers[customerIndex].customerAccountsSize; j++){
                        newCustomerAccountsAfterAdd[j] = customers[customerIndex].customerAccounts[j];
                    }
                }
            }
            newCustomerAccountsAfterAdd[customers[customerIndex].customerAccountsSize] = Account(accountIDcounter, amount);
            delete [] branches[branchIndex].branchAccounts;
            delete [] customers[customerIndex].customerAccounts;
            this -> branches[branchIndex].branchAccounts = newBranchAccountsAfterAdd;
            this-> customers[customerIndex].customerAccounts = newCustomerAccountsAfterAdd;
            this->branches[branchIndex].branchAccountsSize++;
            this->customers[customerIndex].customerAccountsSize++;
            cout<< "Account " << accountIDcounter << " added for customer " << customerId << " at branch " << branchId << endl;
            this->accountIDcounter++;
            this->numberOfAccounts++;
            return accountIDcounter -1;
        }
            //delete from both branchAccounts and customerAccounts array //  numberOfAccounts --; dont decrement accountIDcounter
            void BankingSystem::deleteAccount ( const int accountId ){
                bool accountExists = false;
                int branchIndex;            //which branch
                int customerIndex;          //which customer
                for(int i = 0; i < numberOfBranches; i++ ){
                    for(int j = 0; j < branches[i].branchAccountsSize; j++){
                        if(branches[i].branchAccounts[j].getAccountID() == accountId){
                            accountExists = true;
                            branchIndex = i;
                        }
                    }
                }       //already checked for all branches -->> all accounts , check below is unnecessary
                for(int i = 0; i < numberOfCustomers; i++){
                    for(int j = 0; j < customers[i].customerAccountsSize; j++){
                        if(customers[i].customerAccounts[j].getAccountID() == accountId){
                            accountExists = true;
                            customerIndex = i;
                        }
                    }
                }
                if(!accountExists){
                    cout<< "Account " << accountId <<  " does not exist" <<endl;
                    return;
                }
                Account* newBranchAccountsAfterDelete = new Account[branches[branchIndex].branchAccountsSize -1];
                Account* newCustomerAccountsAfterDelete = new Account[customers[customerIndex].customerAccountsSize -1];
                int k = 0;
                for(int i = 0; i < numberOfBranches; i++){
                    if(branches[i].getBranchID() == branches[branchIndex].getBranchID()){
                        for(int j = 0; j < branches[i].branchAccountsSize; j++){
                            if(branches[i].branchAccounts[j].getAccountID() != accountId){
                                newBranchAccountsAfterDelete[k] = branches[i].branchAccounts[j];
                                k++;
                            }
                        }
                        delete [] branches[i].branchAccounts;
                        this-> branches[i].branchAccountsSize--;
                        this-> branches[i].branchAccounts = newBranchAccountsAfterDelete;
                    }
                }
                int l = 0;
                for(int i = 0; i < numberOfCustomers; i++){
                    if(customers[i].getCustomerID() == customers[customerIndex].getCustomerID()){
                        for(int j = 0; j < customers[i].customerAccountsSize; j++){
                            if(customers[i].customerAccounts[j].getAccountID() != accountId){
                                newCustomerAccountsAfterDelete[l] = customers[i].customerAccounts[j];
                                l++;
                            }
                        }
                        delete [] customers[i].customerAccounts;
                        this-> customers[i].customerAccountsSize--;
                        this-> customers[i].customerAccounts = newCustomerAccountsAfterDelete;
                    }
                }
                this-> numberOfAccounts--;
                if(directDelete){
                cout<< "Account " << accountId << " has been deleted" <<endl;    //test 4 fail           //this will only prints when deleteAccount called //not deleteBranch or deleteCustomer --> indirectly
            }}
            int BankingSystem::findBranchForAccount(const int accountId){
                int branchIndex = -1;
                for(int i = 0; i < numberOfBranches; i++){
                    for(int j = 0; j < branches[i].branchAccountsSize; j++){
                        if(accountId == branches[i].branchAccounts[j].getAccountID()){
                            branchIndex = i;
                        }
                    }
                }
                return branchIndex;
            }
            int BankingSystem::findCustomerForAccount(const int accountId){
                int customerIndex = -1;
                for(int i = 0; i < numberOfCustomers; i++){
                    for(int j = 0; j < customers[i].customerAccountsSize; j++){
                        if(accountId == customers[i].customerAccounts[j].getAccountID()){
                            customerIndex = i;
                        }
                    }
                }
                return customerIndex;
            }

            void BankingSystem::showAllAccounts (){
                cout<< "Account id " << "Branch id " << "Branch name " << "Customer id " << "Customer name " << "Balance" << endl;
                Account* allAccounts = new Account[numberOfAccounts];                                               //problem might be here look later
                int k = 0;          //copy all accounts to a new array doesnt matter from customers or branches
                for(int i = 0; i < numberOfBranches; i++){
                    for(int j = 0; j < branches[i].branchAccountsSize; j++){
                        allAccounts[k++] = branches[i].branchAccounts[j];
                    }
                }       //sort the array based on account IDs.
                for(int i = 0; i < numberOfAccounts - 1; i++){
                    for(int j = 0; j < numberOfAccounts - i -1; j++){
                        if(allAccounts[j].getAccountID() > allAccounts[j+1].getAccountID()){
                            Account temp = allAccounts[j];
                            allAccounts[j] = allAccounts[j+1];
                            allAccounts[j+1] = temp;
                        }
                    }
                }


                for(int i = 0; i < numberOfAccounts; i++){
                    int customerID = findCustomerForAccount(allAccounts[i].getAccountID()) ;
                    int branchID = findBranchForAccount(allAccounts[i].getAccountID()) ;
                    cout.precision(2);
                    cout<< allAccounts[i].getAccountID() << " "<< branches[branchID].getBranchID() << " " << branches[branchID].getBranchName() << " " << customers[customerID].getCustomerID()
                    << " " << customers[customerID].getCustomerName() << " " << fixed << allAccounts[i].getAccountAmount() << endl; //heapcorruption sometimes idk why??
                }
                delete [] allAccounts;
            }
            void BankingSystem:: showBranch(const int branchId){
                bool branchExists = false;
                for(int i = 0; i < numberOfBranches; i++){
                    if(branches[i].getBranchID() == branchId){
                        branchExists = true;
                    }
                }
                if(!branchExists){
                    cout<< "Branch " << branchId << " does not exist" <<endl;
                    return;
                }
                for(int i = 0; i < numberOfBranches; i++){
                    if(branches[i].getBranchID() == branchId){
                        cout<< "Branch id: " << branches[i].getBranchID() << " Branch name: " << branches[i].getBranchName() << " Number of accounts: " << branches[i].branchAccountsSize << endl;
                        if(branches[i].branchAccountsSize != 0){
                        cout<< "Accounts at this branch:" << endl;
                        cout<< "Account id " << "Customer id " << "Customer name " << "Balance" << endl;
                        }
                        for(int j = 0; j < branches[i].branchAccountsSize; j++){
                                int CustomerIndex = findCustomerForAccount(branches[i].branchAccounts[j].getAccountID());
                                if(CustomerIndex >= 0){     //customer found
                        cout.precision(2);
                            cout<< branches[i].branchAccounts[j].getAccountID() << " " << customers[CustomerIndex].getCustomerID() << " " << customers[CustomerIndex].getCustomerName() << " "
                            << fixed << branches[i].branchAccounts[j].getAccountAmount() << endl;
                                }
                        }
                    }
                }
            }
            void BankingSystem::showCustomer ( const int customerId ){
                bool customerExists = false;
                for(int i = 0; i < numberOfCustomers; i++){
                    if(customers[i].getCustomerID() == customerId){
                        customerExists = true;
                    }
                }
                if(!customerExists){
                    cout<< "Customer " << customerId << " does not exist" << endl;
                    return;
                }
                for(int i = 0; i < numberOfCustomers; i++){
                    if(customers[i].getCustomerID() == customerId){
                        cout<< "Customer id: " << customers[i].getCustomerID() << " Customer name: " << customers[i].getCustomerName() << " Number of accounts: " << customers[i].customerAccountsSize << endl;
                        if(customers[i].customerAccountsSize != 0){
                            cout<< "Accounts of this customer:" << endl;
                            cout<< "Account id " << "Branch id " << "Branch name " << "Balance" << endl;
                        }
                        for(int j = 0; j < customers[i].customerAccountsSize; j++){
                            int BranchIndex = findBranchForAccount(customers[i].customerAccounts[j].getAccountID());
                            if(BranchIndex >= 0 ){       //branch found
                            cout.precision(2);
                            cout<< customers[i].customerAccounts[j].getAccountID() << " " << branches[BranchIndex].getBranchID() << " " << branches[BranchIndex].getBranchName() << " "
                            << fixed << customers[i].customerAccounts[j].getAccountAmount() << endl;
                            }
                        }
                    }
                }
            }
