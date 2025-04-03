test: main.o Dataset.o
	g++ main.o Dataset.o -o test -lgtest -pthread
main.o: main.cpp
	g++ -c 	main.cpp -lgtest -pthread
Dataset.o: dataset.cpp
	g++ -c 	dataset.cpp
clean:
	del -f test.exe *.o