#include<iostream>
#include<string.h>

struct datetime
{
    int day;
    int month;
    int year;
};
struct transaction
{
    datetime date;
    int accountNumber;
    char type[15];
    double balance;
};

