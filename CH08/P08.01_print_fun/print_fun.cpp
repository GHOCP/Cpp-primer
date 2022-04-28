/*
    Write a function that normally takes one argument, the address of a string, and
    prints that string once. However, if a second, type int, argument is provided and is
    nonzero, the function should print the string a number of times equal to the number
    of times that function has been called at that point. (Note that the number of
    times the string is printed is not equal to the value of the second argument; it is
    equal to the number of times the function has been called.) Yes, this is a silly function,
    but it makes you use some of the techniques discussed in this chapter. Use the
    function in a simple program that demonstrates how the function works.
*/
#include <iostream>

int prifun(char *, int n = 1);
using namespace std;

int main() {
    char my_array[] = "This is a string.";
    int times_of_print; // record the number of times of function calling

    times_of_print = prifun(my_array);
    times_of_print = prifun(my_array, times_of_print);
    times_of_print = prifun(my_array, times_of_print);
    times_of_print = prifun(my_array, times_of_print);
    times_of_print = prifun(my_array, times_of_print);
    times_of_print = prifun(my_array, times_of_print);

    return 0;
}


int prifun(char * pc, int n) {
    cout << "Calling String Printing **********:\n";
    for (int i = 0; i < n; i++)
        cout << pc << endl;
    return n + 1;
}
