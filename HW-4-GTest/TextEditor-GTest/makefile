test: main.o TextEditor.o
	g++ main.o TextEditor.o -o test -lgtest -pthread
main.o: main.cpp
	g++ -c 	main.cpp -lgtest -pthread
TextEditor.o: TextEditor.cpp
	g++ -c 	TextEditor.cpp
clean:
	del -f test.exe *.o