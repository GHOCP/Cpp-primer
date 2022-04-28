/*
    Testing the complex class I made.
    Here is a sample run of the program:

    Enter a complex number (q to quit):
    real: 10
    imaginary: 12
    c is (10,12i)
    complex conjugate is (10,-12i)
    a is (3,4i)
    a + c is (13,16i)
    a - c is (-7,-8i)
    a * c is (-18,76i)
    2 * c is (20,24i)
    Enter a complex number (q to quit):
    real: q
    Done!
 */
#include <iostream>
using namespace std;
#include "complex0.h" // to avoid confusion with complex.h
int main() {
    complex_my a(3.0, 4.0); // initialize to (3,4i)
    complex_my c;
    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c) {
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";
    return 0;
}
