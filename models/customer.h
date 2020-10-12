#include<iostream>
#include<string.h>
#include"transaction.h"
struct customer{
    int accountNumber;
    char name[45];
    double balance;
    transaction totalTrans[100];
};