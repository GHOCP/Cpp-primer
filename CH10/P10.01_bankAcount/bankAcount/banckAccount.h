/*
    Define a class to represent a bank account. Data members should include the
    depositor¡¯s name, the account number (use a string), and the balance. Member functions
    should allow the following:

    - Creating an object and initializing it.
    - Displaying the depositor¡¯s name, account number, and balance
    - Depositing an amount of money given by an argument
    - Withdrawing an amount of money given by an argument
*/
#ifndef BANCKACCOUNT_H_INCLUDED
#define BANCKACCOUNT_H_INCLUDED

#include <string>

class bankAccount {
    private:
        std::string name;
        std::string number;
        double balance;
    public:
        bankAccount();
        bankAccount(std::string name_, std::string number_,
                    double balance_);
        ~bankAccount();
        void show() const;
        void deposit(double dep);
        void withdraw(double wid);
};

#endif // BANCKACCOUNT_H_INCLUDED
