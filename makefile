p2: main.o
	g++ main.o -o p2

main.o: main.cpp LinkedSortedList.h
	g++ -c main.cpp 

clean:
	rm -f *.o *~ *#
