FLAGS := -std=c99

all: prog
prog: main.o geometry.o parser.o
	gcc -Wall -Wextra main.o geometry.o parser.o -o main -lm $(FLAGS)
main.o: main.c
	gcc -Wall -Wextra -c main.c -o main.o $(FLAGS)
geometry.o: geometry.c
		gcc -Wall -Wextra -c geometry.c -o geometry.o -lm $(FLAGS)
parser.o: parser.c
		gcc -Wall -Wextra -c parser.c -o parser.o $(FLAGS)

clean:
	rm -f *.o
	rm -f main
