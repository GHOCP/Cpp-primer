/* demonstrate all the features of the prototyped functions. */

#include <iostream>
#include "golf.h"
#define NUM 5
using namespace std;
static golf My_golf[NUM];

int main () {
    int flag = 1;
    int num_of_entered = 0;

    for (int i = 0; i < NUM; i++) {
        cout << "Enter info #" << i + 1 << "**********" << endl;
        flag = setgolf(My_golf[i]);
        if (flag == 1)
            num_of_entered++;
        else
            break;
    }
    cout << "Total valid enterings: " << num_of_entered << endl;
    for (int i = 0; i < num_of_entered; i++)
        showgolf(My_golf[i]);
    return 0;
}
