/*
    Write a program that reads input a word at a time until a lone q is entered.The
    program should then report the number of words that began with vowels, the number
    that began with consonants, and the number that fit neither of those categories.
    One approach is to use isalpha() to discriminate between words beginning with
    letters and those that don¡¯t and then use an if or switch statement to further identify
    those passing the isalpha() test that begin with vowels.A sample run might
    look like this:

    Enter words (q to quit):
    The 12 awesome oxen ambled
    quietly across 15 meters of lawn. q
    5 words beginning with vowels
    4 words beginning with consonants
    2 others
*/
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

int main() {

    using namespace std;
    /* variables defined */
    string temp;
    int num_vo, num_co, num_other;
    num_vo = num_co = num_other = 0;

    /* input and count */
    cout << "Enter wors (q to quit):" << endl;
    while (cin >> temp && temp != "q") {
        if (!isalpha(temp[0]))
            num_other++;
        else if (strchr("aeiouAEIOU", temp[0]) == NULL)
            num_co++;
        else
            num_vo++;
    }

    /* result displayed */
    cout << num_vo << " words beginning with vowels" << endl;
    cout << num_co << " words beginning with consonants" << endl;
    cout << num_other << " others";

    return 0;
}
