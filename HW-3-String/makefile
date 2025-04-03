MyProg: main.o string.o
	g++ main.o string.o -o MyProg
main.o: main.cpp
	g++ -c 	main.cpp
TextEditor.o: string.cpp
	g++ -c 	string.cpp
clean:
	del -f MyProg.exe *.o