FLAGS := -std=c99

all: main.o geometry.o
	gcc -Wall -Wextra main.o geometry.o -o main $(FLAGS)
main.o: main.c
	gcc -Wall -Wextra -c main.c -o main.o $(FLAGS)
IntVector.o: IntVector.c
	gcc -Wall -Wextra -c geometry.c -o geometry.o $(FLAGS)

clean:
	rm -f *.o
	rm -f main
