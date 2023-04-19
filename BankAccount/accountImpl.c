
#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "AccountStatus.h"

typedef struct Account
{
    int accountNo;
    double creditLimit;
    double balance;
} Account;

// Constructor
account_t create_Account(int accountNo, double creditLim, double balance)
{

    account_t _newAcc = calloc(1, sizeof(Account));

    if (NULL == _newAcc)
    {
        return NULL;
    }

    _newAcc->accountNo = accountNo;
    _newAcc->creditLimit = creditLim;
    _newAcc->balance = balance;

    return _newAcc;
}

status_e withdraw(account_t myAcc, double amount)
{
    if (myAcc == NULL)
    {
        return ACCOUNT_NOT_INITIATED;
    }

    if (myAcc->balance < amount)
    {
        return OVER_MAX_CREDIT_LIMIT;
    }

    myAcc->balance -= amount;
    return OK;
}

status_e deposit(account_t myAcc, double amount)
{
    if (myAcc == NULL)
    {
        return ACCOUNT_NOT_INITIATED;
    }

    myAcc->balance += amount;
    return OK;
}

double get_balancee(account_t myAcc)
{
    return myAcc->balance;
}

double get_creditLimit(account_t myAcc)
{
    return myAcc->creditLimit;
}

int get_accountNumber(account_t myAcc)
{
    return myAcc->accountNo;
}