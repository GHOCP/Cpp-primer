#include <iostream>
#include <string>
#include "banckAccount.h"

int main() {
    using std::cout;
    bankAccount myAccount1; // default constructor;
    bankAccount myAccount2 = bankAccount("OCP", "198964", 100); // my construtor
    bankAccount myAccount3("OCPP", "199964", 150); // my construtor

    /* display account info */
    cout << "============= Displaying the info of accounts =============\n";
    myAccount1.show();
    myAccount2.show();
    myAccount3.show();
    /* deposit and withdraw */
    cout << "============= deposit and withdraw =============\n";
    double dep = 50;
    double wid = 200;
    // deposit $50 to accout 2
    cout << "ACCOUNT 2 after depositing " << dep << " :\n";
    myAccount2.deposit(dep);
    myAccount2.show();
    // withdraw $200 from accout 3
    cout << "ACCOUNT 3 after withdrawing " << wid << " :\n";
    myAccount3.withdraw(wid);
    myAccount3.show();

    return 0;
}
