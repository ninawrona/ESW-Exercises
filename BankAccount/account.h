#include "AccountStatus.h"

typedef struct Account *account_t;

account_t create_Account(int accountNo, double creditLim, double balance);
status_e withdraw(account_t myAcc, double amount);
status_e deposit(account_t myAcc, double amount);
double get_balancee(account_t myAcc);
double get_breditLimit(account_t myAcc);
int get_accountNumber(account_t myAcc);