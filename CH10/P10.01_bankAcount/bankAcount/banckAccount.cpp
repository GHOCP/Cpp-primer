#include <iostream>
#include <string>
#include "banckAccount.h"

/* default constructor */
bankAccount::bankAccount() {
    name = "No name";
    number = "no number";
    balance = 0;
}

/* my constructor */
bankAccount::bankAccount(std::string name_, std::string number_,
                         double balance_) {
    name = name_;
    number = number_;
    balance = balance_;
}

/* deconstructors */
bankAccount::~bankAccount() {
}

/* other member functions */
// Displaying the depositor¡¯s name, account number, and balance
void bankAccount::show() const {
    using std::cout;
    using std::endl;
    if (name == "No name")
        cout << "Empty account." << endl;
    else
        cout << name << "(#" << number << ") "
             << "has $" << balance << " now." << endl;
}
// Depositing an amount of money given by an argument
void bankAccount::deposit(double dep) {
    balance += dep;
}
// Withdrawing an amount of money given by an argument
void bankAccount::withdraw(double wid) {
    using std::cout;
    if (wid > balance) {
        cout << "Your withdrawing exceeds your balance.\n";
        balance = 0;
    }
    else
        balance -= wid;
}
