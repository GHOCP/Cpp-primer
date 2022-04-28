/*
    Write a program that asks the user to enter up to 10 golf scores, which are to be
    stored in an array.You should provide a means for the user to terminate input prior
    to entering 10 scores.The program should display all the scores on one line and
    report the average score. Handle input, display, and the average calculation with
    three separate array-processing functions.
*/

#include <iostream>
#define MAX 10
/* function prototypes */
int input(double []);
void display(double [], int);
double ave_cal(double [], int);

/* main function */
int main() {
    using namespace std;
    double my_array[MAX];
    int num;

    num = input(my_array);
    display(my_array, num);
    cout << "The average score is: " << ave_cal(my_array, num);

    return 0;
}

/* function definitions */
// read in the data, return the number of input scores
int input(double arr[]) {
    using namespace std;
    int num_of_scores = 0;
    double temp;

    cout << "Please enter golf scores one by one\n"
         << "(negative to quit, invalid data will terminate the input in advance):\n";
    for (int i = 0; i < MAX; i++) {
        cout << "#" << i + 1 << ": ";
        cin >> temp;
        if (temp < 0 || !cin)   // negative or invalid data terminates the input
            break;
        else {
            arr[i] = temp;
            num_of_scores++;
        }
    }
    return num_of_scores;
}
// display the input data
void display(double arr[], int n) {
    using namespace std;
    cout << "Display all the scores in one line: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// calculate the average score
double ave_cal(double arr[], int n) {
    using namespace std;
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + arr[i];
    return sum / n;
}
