/*
    Write a template function maxn() that takes as its arguments an array of items of
    type T and an integer representing the number of elements in the array and that
    returns the largest item in the array.Test it in a program that uses the function template
    with an array of six int value and an array of four double values.The program
    should also include a specialization that takes an array of pointers-to-char as
    an argument and the number of pointers as a second argument and that returns the
    address of the longest string. If multiple strings are tied for having the longest
    length, the function should return the address of the first one tied for longest.Test
    the specialization with an array of five string pointers.
*/

#include <iostream>
#include <cstring>  // for strlen
using namespace std;

/* The template and its specialization */
template <typename T>
T maxn(T [], int );

template <> char * maxn<char *>(char * [], int );

/* The main function */
int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6};
    double arr2[] = {1.2, 0.2, 3.5, 6.8};
    char * arr3[] = {
        "Separate compilation of programs",
        "Storage duration, scope, and linkage",
        "Placement new"
    };


    cout << "The result of integer array: " << maxn(arr1, 6) << endl;
    cout << "The result of double array: " << maxn(arr2, 4) << endl;

    char * pc = maxn(arr3, 3);
    cout << "The result of string array: " << pc << endl;
    delete pc;

    return 0;
}

/* Function defintions */
template <typename T>
T maxn(T arr[], int n) {
    T largest = arr[0];
    for (int i = 0; i < n; i++)
        if (arr[i] > largest)
            largest = arr[i];
    return  largest;
}

template <> char * maxn<char *>(char * arr[], int n) {
    char * pc = new char;
    pc = arr[0];
    for (int i = 0; i < n; i++)
        if (strlen(arr[i]) > strlen(pc))
            pc = arr[i];
    return pc;
}
