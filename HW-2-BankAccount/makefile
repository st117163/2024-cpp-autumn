MyProg: main.o Bank.o BankAccount.o
	g++ main.o Bank.o BankAccount.o -o MyProg
main.o: main.cpp
	g++ -c 	main.cpp
Bank.o: Bank.cpp
	g++ -c 	Bank.cpp
BankAccount.o: BankAccount.cpp
	g++ -c 	BankAccount.cpp
clean:
	del -f MyProg.exe *.o