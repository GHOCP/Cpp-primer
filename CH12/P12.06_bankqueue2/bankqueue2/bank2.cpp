// bank.cpp -- using the Queue interface
// compile with queue.cpp
/*
    ============= simulation 3 ====================
    The Bank of Heather would like to know what would happen if it added a second
    ATM. Modify the simulation in this chapter so that it has two queues.Assume that
    a customer will join the first queue if it has fewer people in it than the second
    queue and that the customer will join the second queue otherwise.Again, find a
    value for number of customers per hour that leads to an average wait time of one
    minute. (Note:This is a nonlinear problem in that doubling the number of ATMs
    doesn¡¯t double the number of customers who can be handled per hour with a oneminute
    wait maximum.)
*/
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include "queue.h"
const int MIN_PER_HR = 60;
bool newcustomer(double x); // is there a new customer?
int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

/* =============== setting things up =============== */
    std::srand(std::time(0)); // random initializing of rand()
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue1: ";
    int qs;
    cin >> qs;
    Queue line1(qs);
    cout << "Enter maximum size of queue2: ";
    cin >> qs;
    Queue line2(qs);
    cout << "Enter the number of simulation hours: ";
    int hours; // hours of simulation
    cin >> hours;

/* =============== simulation will run 1 cycle per minute =============== */
    long cyclelimit = MIN_PER_HR * hours; // # of cycles
    cout << "Enter the average number of customers per hour: ";
    double perhour; // average # of arrival per hour, here we assuming perhour <=60
    cin >> perhour;
    double min_per_cust; // average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;
    Item temp; // new customer data
    long turnaways = 0; // turned away by full queue
    long customers = 0; // joined the queue
    long served = 0; // served during the simulation
    long sum_line = 0; // cumulative line length
    int wait_time1 = 0; // time until autoteller1 is free
    int wait_time2 = 0; // time until autoteller1 is free
    long line_wait = 0; // cumulative time in line

/* =============== running the simulation =============== */
    for (int cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) { // have newcomer
            if (line1.isfull() && line2.isfull())
                turnaways++;
            else {
                customers++;
                temp.set(cycle); // cycle = time of arrival
                // add newcomer to line
                if (line1.queuecount() < line2.queuecount())
                    line1.enqueue(temp);
                else
                    line2.enqueue(temp);
            }
        }
        // for line 1
        if (wait_time1 <= 0 && !line1.isempty()) {
            line1.dequeue (temp); // attend next customer
            wait_time1 = temp.ptime(); // for wait_time minutes
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time1 > 0)
            wait_time1--;
        // for line 2
        if (wait_time2 <= 0 && !line2.isempty()) {
            line2.dequeue (temp); // attend next customer
            wait_time2 = temp.ptime(); // for wait_time minutes
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time2 > 0)
            wait_time2--;
        // sum up the sum_line
        sum_line += (line1.queuecount() + line2.queuecount());
    }

// reporting results
    if (customers > 0) {
        cout << "customers accepted: " << customers << endl;
        cout << " customers served: " << served << endl;
        cout << " turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: "
             << (double) line_wait / served << " minutes\n";
    } else
        cout << "No customers!\n";
    cout << "Done!\n";
    return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x) {
    return (std::rand() * x / RAND_MAX < 1);
}

