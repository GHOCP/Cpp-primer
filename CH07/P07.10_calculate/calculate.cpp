/*
    Design a function calculate() that takes two type double values and a pointer to
    a function that takes two double arguments and returns a double.The
    calculate() function should also be type double, and it should return the value
    that the pointed-to function calculates, using the double arguments to
    calculate(). For example, suppose you have this definition for the add()
    function:
    double add(double x, double y)
    {
        return x + y;
    }
    Then, the function call in the following would cause calculate() to pass the values
    2.5 and 10.4 to the add() function and then return the add() return value
    (12.9):
    double q = calculate(2.5, 10.4, add);
    Use these functions and at least one additional function in the add() mold in a
    program.The program should use a loop that allows the user to enter pairs of numbers.
    For each pair, use calculate() to invoke add() and at least one other function.
    If you are feeling adventurous, try creating an array of pointers to add()-style
    functions and use a loop to successively apply calculate() to a series of functions
    by using these pointers. Hint: Here¡¯s how to declare such an array of three pointers:
    double (*pf[3])(double, double);
    You can initialize such an array by using the usual array initialization syntax and
    function names as addresses.
*/

#include <iostream>

double calculate (double d1, double d2, double (*pf)(double, double));
double add (double, double);
double substract (double, double);
double multiply (double, double);

int main() {
    using namespace std;
    double num1, num2;
    double (*pf[3]) (double, double) =
    {add, substract, multiply};  // an array of three pointers-to-function
    double result[3];   // stores the result

    cout << "Please input two double values: ";
    while (cin >> num1 && cin >> num2) {
        // calculation
        for (int i = 0; i < 3; i++)
            result[i] = calculate(num1, num2, *pf[i]);
        // display the results
        cout << "Here are the results of calling function calculate for: "
             << num1 << " " << num2 << endl;
        cout << "ADD: " << result[0] << endl;
        cout << "SUBSTRATE: " << result[1] << endl;
        cout << "MULTIPLY: " << result[2] << endl;
        // next input pair
        cout << "Please input next two double values(q to quit): ";
    }
    return 0;
}


double calculate (double d1, double d2, double (*pf)(double, double)) {
    return (*pf)(d1, d2);
}

double add (double d1, double d2) {
    return d1 + d2;
}

double substract (double d1, double d2) {
    return d1 - d2;
}

double multiply (double d1, double d2) {
    return d1 * d2;
}
