#include "person.h"
#include <iostream>

/* =============== worker methods =============== */
Person::~Person() {}

void Person::Data() const {
    cout << "NAME: "
         << first_n << ", " << last_n << endl;
}

void Person::Get() {
    cout << "Enter first name: ";
    getline(cin, first_n);
    cout << "Enter last name: ";
    getline(cin, last_n);
}

/* =============== Gunslinger methods =============== */
void Gunslinger::Data() const {
    cout << "DRAW TIME: " << draw_time << endl;
    cout << "NUMBER OF NOTCHES: " << num_of_notch << endl;
}

void Gunslinger::Get() {
    cout << "Enter the draw time: ";
    while (!(cin >> draw_time)) {
        cout << "Invalid input. Enter again: ";
        while (cin.get() != '\n')
            continue;
    }
    while (cin.get() != '\n')
        continue;
    cout << "Enter the number of notches: ";
    while (!(cin >> num_of_notch)) {
        cout << "Invalid input. Enter again: ";
        while (cin.get() != '\n')
            continue;
    }
    while (cin.get() != '\n')
        continue;
}

void Gunslinger::Set() {
    cout << "Enter the gunslinger's fullname:\n";
    Person::Get();
    Get();
}

double Gunslinger::Draw() const {
    return draw_time;
}

void Gunslinger::Show() {
    Person::Data();
    Data();
}

/* =============== Card methods =============== */
char * Card::suits[Card::num] = {
    "hearts", "clubs", "diamonds", "spades"
};

/* =============== PokerPlayer methods =============== */
Card PokerPlayer::Draw() const {
    srand(time(0));
    int face = rand() % 52 + 1; // get 1 ~ 52
    int suit = rand() % 4;  // get 0 ~ 3
    return Card(face, suit);
}

void PokerPlayer::Data() const {
    Card my_card = Draw();
    cout << "The Card is: "
         << my_card.show_face << ", "
         << Card::suits[my_card.show_suit] << endl;
}

void PokerPlayer::Get() {

}

void PokerPlayer::Set() {
    cout << "Enter the pokerplayer's fullname:\n";
    Person::Get();
    Get();
}

void PokerPlayer::Show() {
    Person::Data();
    Data();
}

/* =============== BadDude methods =============== */
void BadDude::Data() const {
    Gunslinger::Data();
    PokerPlayer::Data();
}

void BadDude::Get() {
    Gunslinger::Get();
    PokerPlayer::Get();
}

void BadDude::Set() {
    cout << "Enter the bad dude's fullname:\n";
    Person::Get();
    Get();
}

double BadDude::Gdraw() const {
    return Gunslinger::Draw();
}

Card BadDude::Cdraw const {
    return PokerPlayer::Draw();
}

void Show() const {
    Person::Data();
    Data();
}

