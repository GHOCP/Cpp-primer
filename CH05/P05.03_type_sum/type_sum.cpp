/*
    Write a program that asks the user to type in numbers.After each entry, the program
    should report the cumulative sum of the entries to date.The program should
    terminate when the user enters 0.
*/

#include <iostream>

int main () {
    using namespace std;
    long sum;
    int temp;

    sum = 0;
    cout << "Please type in some numbers(0 to quit): ";
    while (cin >> temp && temp != 0)
        sum = sum + temp;
    cout << "The sum is:" << sum;

    return 0;
}
