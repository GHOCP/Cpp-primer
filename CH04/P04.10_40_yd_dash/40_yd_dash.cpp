/*
    Write a program that requests the user to enter three times for the 40-yd dash (or
    40-meter, if you prefer) and then displays the times and the average. Use an array
    object to hold the data. (Use a built-in array if array is not available.)
*/

#include <iostream>
#include <array>

int main() {

    using namespace std;
    array<float, 3> arr;
    float temp;
    float ave;

    cout << "Enter your time 1: ";
    cin >> temp;
    arr[0] = temp;

    cout << "Enter your time 2: ";
    cin >> temp;
    arr[1] = temp;

    cout << "Enter your time 3: ";
    cin >> temp;
    arr[2] = temp;

    ave = (arr[0] + arr[1] + arr[2]) / 3;

    cout << "The times and average are: " << endl;
    cout << "TIME1: " << arr[0] << endl;
    cout << "TIME2: " << arr[1] << endl;
    cout << "TIME3: " << arr[2] << endl;
    cout << "EVERAGE: " << ave;

    return 0;
}
