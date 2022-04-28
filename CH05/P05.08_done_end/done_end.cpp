/*
    Write a program that uses an array of char and a loop to read one word at a time
    until the word done is entered.The program should then report the number of
    words entered (not counting done).A sample run could look like this:

    Enter words (to stop, type the word done):
    anteater birthday category dumpster
    envy finagle geometry done for sure
    You entered a total of 7 words.

    You should include the cstring header file and use the strcmp() function to
    make the comparison test.
*/

#include <iostream>
#include <cstring>
#define SIZE 20

int main() {

    using namespace std;
    int num = 0;
    char arr[SIZE];

    cout << "Enter words (to stop, type the word done):" << endl;
    while (cin >> arr && strcmp(arr, "done") != 0)
        num++;
    cout << "You entered a totoal of " << num << " words.";
    return 0;
}
