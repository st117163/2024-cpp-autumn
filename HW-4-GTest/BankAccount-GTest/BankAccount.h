#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include<iostream>

class BankAccount
{
public:
    BankAccount();
	BankAccount(std::string accNum, double balance, std::string accHolder);
    ~BankAccount();

	int Deposit(double amount);
	int Withdraw(double amount);
	double GetBalance();
	std::string GetAccountHolder();
	std::string GetAccountNumber();
	void PrintAccountInfo();

private:
	std::string accountNumber;
	double balance;
	std::string accountHolder;
};

#endif