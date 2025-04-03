#include "Bank.h"

Bank::Bank(): accounts() {}
Bank::~Bank() {}

void Bank::AddAccount(BankAccount* account)
{
    accounts.push_back(account);
    std::cout << "Account added succesfully." << std::endl;
}
double Bank::GetTotalBalance()
{
    double tmp = 0;
    for (int i = 0; i < accounts.size(); ++i)
	{
		tmp += accounts[i] -> GetBalance();
	}
	return tmp;
}
void Bank::PrintAllAccounts()
{
    std::cout << "Bank Accounts infprmation:" << std::endl;
    for (int i = 0; i < accounts.size(); ++i)
	{
        std::cout << "_____________________________" << std::endl;
		accounts[i] -> PrintAccountInfo();
	}
}