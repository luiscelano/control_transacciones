#include<iostream>
#include<string>

using namespace std;
struct datetime
{
    int day;
    int month;
    int year;
};
struct transaction
{
    // datetime date;
    int accountNumber;
    string type;
    double balance;
};

