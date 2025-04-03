test: main.o Bank.o BankAccount.o
	g++ main.o Bank.o BankAccount.o -o test -lgtest -pthread
main.o: main.cpp
	g++ -c 	main.cpp -lgtest -pthread
Bank.o: Bank.cpp
	g++ -c 	Bank.cpp
BankAccount.o: BankAccount.cpp
	g++ -c 	BankAccount.cpp
clean:
	del -f test.exe *.o