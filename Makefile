FLAGS := -std=c99

all: main.o geometry.o
	gcc main.o geometry.o -o main $(FLAGS)
main.o: main.c
	gcc -c main.c -o main.o $(FLAGS)
IntVector.o: IntVector.c
	gcc -c geometry.c -o geometry.o $(FLAGS)

clean:
	rm -f *.o
	rm -f main
