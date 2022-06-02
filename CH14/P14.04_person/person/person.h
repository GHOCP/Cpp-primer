#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <string>
#inlcude <ctime>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::srand;
using std::rand;
using std::time;

class Person {
    private:
        string first_n;
        string last_n;
    protected:
        virtual void Data() const;
        virtual void Get();
    public:
        Person() : first_n("NULL"), last_n("NULL") {}
        Person(const string & s1, const string & s2)
            : first_n(s1), last_n(s2) {}
        virtual ~Person() = 0;  // pure virtual function
        virtual void Set() = 0;
        virtual void Show() const = 0;
};

class Gunslinger : virtual public Person {
    private:
        double draw_time;
        int num_of_notch;
    protected:
        void Data() const;
        void Get();
    public:
        // constructors
        Gunslinger()
            : Person(), draw_time(0), num_of_notch(0) {}
        Gunslinger(const string & s1, const string & s2, double dt, int n)
            : Person(s1, s2), draw_time(dt), num_of_notch(n) {}
        Gunslinger(const Person & p, double dt, int n)
            : Person(p), draw_time(dt), num_of_notch(n) {}
        // other public methods
        void Set();     // setting all the info of a Gunslinger
        void Show() const;
        double Draw() const;
};

class Card {
    protected:
        enum suits_enum {hearts, clubs, diamonds, spades};
        enum {num = 7};
    private:
        static char * suits[num];    // strings equivs of suits
        int face;
        int suit;
    public:
        Card(int f = 0, int s = 0) : face(f), suit(s);
        Card();
        int show_face() const {
            return face;
        }
        int show_suit() const {
            return suit;
        }
};

class PokerPlayer : virtual public Person {
    protected:
        Card Draw() const;
        void Data() const;
        void Get();
    private:
        Card card;
    public:
        PokerPlayer()
            : Person() {}
        PokerPlayer(const string & s1, const string & s2)
            : Person(s1, s2) {}
        PokerPlayer(const Person & p)
            : Person(p) {}
        void Set();
        void Show() const;
};

class BadDude : public Gunslinger, public PokerPlayer {
    protected:
        void Data() const;
        void Get();
    public:
        BadDude()
            : Gunslinger(), PokerPlayer() {}
        BadDude(const string & s1, const string & s2, double dt, int n)
            : Person(s1, s2), Gunslinger(s1, s2, dt, n), PokerPlayer(s1, s2) {}
        BadDude(const Person & p, double dt, int n)
            : Person(p), Gunslinger(p, dt, n), PokerPlayer(p) {}
        void Set();
        void Show() const;
        double Gdraw() const;
        Card Cdraw() const;
};

#endif // PERSON_H_INCLUDED
