
#pragma once

typedef enum AccountStatus
{
    OK,
    OVER_MAX_CREDIT_LIMIT,
    ACCOUNT_NOT_INITIATED
} status_e;

const char *getStatus(status_e status)
{
    switch (status)
    {
    case OK:
        return "OK";
        break;
    case OVER_MAX_CREDIT_LIMIT:
        return "OVER_MAX_CREDIT_LIMIT";
        break;
    case ACCOUNT_NOT_INITIATED:
        return "ACCOUNT_NOT_INITIATED";
        break;
    default:
        return "ERROR";
        break;
    }
}