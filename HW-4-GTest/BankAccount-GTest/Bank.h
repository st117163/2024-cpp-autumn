#ifndef BANK_H
#define BANK_H

#include "BankAccount.h"
#include <vector>

class Bank
{
public:
    Bank();
    ~Bank();

	void AddAccount(BankAccount* account);
    double GetTotalBalance();
    void PrintAllAccounts();

private:
	std::vector<BankAccount*> accounts;
};

#endif