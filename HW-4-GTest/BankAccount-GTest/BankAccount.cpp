#include "BankAccount.h"

BankAccount::BankAccount(): accountNumber("none"), balance(0), accountHolder("none") {}

BankAccount::BankAccount(std::string accNum, double amount, std::string owner):
accountNumber(accNum), balance(amount), accountHolder(owner) {}

BankAccount::~BankAccount() {}

int BankAccount::Deposit(double amount)
{
    if (amount <= 0)
    {
        std::cout << "Error: Amount must be > 0 " << std::endl;
        return 1;
    }

    balance += amount;
    return 0;
}

int BankAccount::Withdraw(double amount)
{
    if (amount > balance)
    {
        std::cout << "Error:  Not enough funds." << std::endl;
        return 1;
    }

    balance -= amount;
    return 0;
}

double BankAccount::GetBalance()
{
    return balance;
}

std::string BankAccount::GetAccountNumber()
{
    return accountNumber;
}

std::string BankAccount::GetAccountHolder()
{
    return accountHolder;
}

void BankAccount::PrintAccountInfo()
{
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Owner: " << accountHolder << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}