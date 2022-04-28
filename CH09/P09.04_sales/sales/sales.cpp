/* a source code file that extends the namespace to provide definitions for
the three prototyped functions */

#inlcude <iostream>
#include "sales.h"

using namespace SALES;
using namespace std;

void setSales(Sales & s, const double ar[], int n) {
    int num = (n < 4?) n : 4;
    double total = 0;

    /* data copyng and average calculation */
    for (int i = 0; i < num; i++) {
        s.sales[i] = ar[i];
        total += ar[i];
    }
    s.average = total / num;
    /* data copyng and average calculation */
    s.max = s.min = s.sales[0];   // initialied as the first sale
    for (int i = 1; i < num ; i++) {
        if s.max < s.sales[i]
            s.max = s.sales[i];
        if s.min > s.sales[i]
            s.min = s.sales[i];
    }
}

void setSales (Sales & s) {
    double temp;
    double ar[QUARTERS];
    int index = 0;
    /* interactively enter 4 quarters */
    cout << "Enter 1st quarter(q to quit): ";
    while (index < QUARTERS) {
        // abandon invalid input
        while (!(cin >> temp)) {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Invalid input. Please enter again: ";
        }
        // data reading
        ar[i] = temp;
        cout << "Enter next value: "
        index++;
    }
    /* computer and store the data in struct Sales */
    setSales(s, ar, QUARTERS);
}

void showSales(const Sales & s) {
    cout << "The sales are: ";
    for (int i = 0; i < QUARTERS; i++)
        cout << s.sales[i] << " ";
    cout << "\nThe average is: " << s.average << endl;
    cout << "The max of sales is: " << s.max << endl;
    cout << "The min of sales is: " << s.min << endl;
}
