#include <stdio.h>
#include "account.h"
#include "accountImpl.c"

int main()
{

    struct Account *mine = create_Account(1111, 20000, 300);

    printf("Balance [300]: %f\n", get_balancee(mine));
    status_e str = deposit(mine, 200);
    printf("status: %s\n", getStatus(str));
    printf("Balance [500]: %f\n", get_balancee(mine));

    str = withdraw(mine, 100);
    printf("status: %s\n", getStatus(str));
    printf("Balance [400]: %f\n", get_balancee(mine));

    str = withdraw(mine, 500);
    printf("status: %s\n", getStatus(str));
    printf("Balance [400]: %f\n", get_balancee(mine));

    return 0;
}