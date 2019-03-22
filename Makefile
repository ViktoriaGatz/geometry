FLAGS := -std=c99
SRC_DIR := ./src

all: $(SRC_DIR)prog
$(SRC_DIR)prog:  $(SRC_DIR)/main.o  $(SRC_DIR)/geometry.o  $(SRC_DIR)/parser.o
	gcc -Wall -Wextra  $(SRC_DIR)/main.o  $(SRC_DIR)/geometry.o  $(SRC_DIR)/parser.o -o main -lm $(FLAGS)
$(SRC_DIR)main.o: $(SRC_DIR)main.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/main.c -o  $(SRC_DIR)/main.o $(FLAGS)
$(SRC_DIR)geometry.o: $(SRC_DIR)geometry.c
		gcc -Wall -Wextra -c  $(SRC_DIR)/geometry.c -o  $(SRC_DIR)/geometry.o -lm $(FLAGS)
$(SRC_DIR)parser.o: $(SRC_DIR)parser.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/parser.c -o  $(SRC_DIR)/parser.o $(FLAGS)

clean:
	rm -f *.o
	rm -f main
