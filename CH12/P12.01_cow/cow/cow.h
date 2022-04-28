#ifndef COW_H_INCLUDED
#define COW_H_INCLUDED
using std::cout;
using std::endl;

class Cow {
    private:
        char name[20];
        char * hobby;
        double weight;
    public:
        Cow();
        Cow(const char * name_, const char * hobby_, double weight);
        Cow(const Cow & c);
        ~Cow();
        Cow & operator=(const Cow & c);
        void ShowCow() const; // display all cow data
};

#endif // COW_H_INCLUDED
