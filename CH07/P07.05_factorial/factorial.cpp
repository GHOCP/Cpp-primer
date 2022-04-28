/*
    Define a recursive function that takes an integer argument and returns the factorial
    of that argument. Recall that 3 factorial, written 3!, equals 3 ¡Á 2!, and so on, with 0!
    defined as 1. In general, if n is greater than zero, n! = n * (n - 1)!.Test your function
    in a program that uses a loop to allow the user to enter various values for which the
    program reports the factorial.
*/

#include <iostream>

int factorial (int);

int main() {
    using namespace std;
    int n;
    cout << "Enter a positive integer and I will return teh factorial of it: ";
    while (cin >> n && n >= 0) {
        cout << "factorial of " << n << " is: " << factorial(n) << endl;
        cout << "Enter next integer(negative value to quit): ";
    }

    return 0;
}

int factorial (int n) {
    if (n > 1)
        return n * factorial(n-1);
    else
        return 1;   // when it is 1 or n == 0
}
