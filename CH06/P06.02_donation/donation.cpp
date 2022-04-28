/*
    Write a program that reads up to 10 donation values into an array of double. (Or, if
    you prefer, use an array template object.) The program should terminate input on
    non-numeric input. It should report the average of the numbers and also report
    how many numbers in the array are larger than the average.
*/

#include <iostream>
#include <array>
#define MAX 10
int main() {

    using namespace std;

    array<double, MAX> donation;
    double temp;
    int num = 0;
    double sum = 0;

    cout << "Please enter donations(up to 10 values, q to quit)" << endl ;
    cout << "DON #" << num + 1 << ":" ;
    while (cin >> temp && num < MAX) {  // nonnumeric input to quit
        donation[num] = temp;
        cout << "DON #" << ++num + 1 << ": " ;
    }
    /* when no input */
    if (num == 0)
        cout << "No input." ;
    /* display the info */
    else {
        for (int i = 0; i < num; i++)
            sum = sum + donation[i];
        cout << "The average is: " << sum / num ;
    }

    return 0;
}
