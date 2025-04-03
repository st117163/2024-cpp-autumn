MyProg: main.o TextEditor.o
	g++ main.o TextEditor.o -o MyProg
main.o: main.cpp
	g++ -c 	main.cpp
TextEditor.o: TextEditor.cpp
	g++ -c 	TextEditor.cpp
clean:
	del -f MyProg.exe *.o