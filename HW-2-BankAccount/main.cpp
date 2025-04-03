#include "Bank.h"

int main(int argc, char* argv[])
{
	BankAccount MyAcc("000226", -0.57, "Shvets Vladimir");
	BankAccount OtherAcc("123456", 999999.7, "Oleg Tinkov");
	
	Bank MyBank;
	MyBank.AddAccount(&MyAcc);
	MyBank.AddAccount(&OtherAcc);

	MyAcc.Deposit(-3200);
	MyAcc.Withdraw(3200);
	OtherAcc.Withdraw(999900.57);
	MyAcc.Deposit(999900.57);

	MyBank.PrintAllAccounts();
	MyAcc.Withdraw(999000);
	std::cout <<"My Bank Total Balance: " << MyBank.GetTotalBalance() << std::endl; 

	return EXIT_SUCCESS;
}