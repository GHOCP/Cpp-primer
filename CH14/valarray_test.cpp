#include <iostream>
#include <valarray>
#include <cstdlib>

using namespace std;
typedef valarray<double> DA;

DA & test(DA & arr);

int main() {
    DA myArr(10, 8);
    DA newArr;
    double d1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // newArr = test(myArr);
    DA tempArr(d1, 8);
    newArr = tempArr;
    for (int i = 0; i < 8; i++)
        cout << newArr[i] << " ";
    return 0;
}

DA & test(DA & arr) {
    return arr;
}
