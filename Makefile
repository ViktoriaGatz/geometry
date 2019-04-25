FLAGS := -std=c99
FLAG := -std=c11
SRC_DIR := ./src
BIN_DIR := ./bin
OBJ_DIR := ./build
OBJ_TEST_DIR := ./build/test
TEST_DIR := ./test
.PHONY: clean install uninstall all run

all: $(BIN_DIR)/geometry $(BIN_DIR)/testing


$(BIN_DIR)/geometry:  $(OBJ_DIR)/main.o  $(OBJ_DIR)/geometry.o  $(OBJ_DIR)/parser.o
	gcc -Wall -Wextra  $(OBJ_DIR)/main.o  $(OBJ_DIR)/geometry.o  $(OBJ_DIR)/parser.o -o $(BIN_DIR)/geometry -lm $(FLAGS)


$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/main.c -o  $(OBJ_DIR)/main.o $(FLAGS)


$(OBJ_DIR)/geometry.o: $(SRC_DIR)/geometry.c
		gcc -Wall -Wextra -c  $(SRC_DIR)/geometry.c -o  $(OBJ_DIR)/geometry.o -lm $(FLAGS)


$(OBJ_DIR)/parser.o: $(SRC_DIR)/parser.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/parser.c -o  $(OBJ_DIR)/parser.o $(FLAGS)

#gcc ./test/*.c ./src/geometry.c -lm -std=c11

$(BIN_DIR)/testing: $(OBJ_TEST_DIR)/main.o $(OBJ_TEST_DIR)/parser.o $(OBJ_TEST_DIR)/geometry.o $(OBJ_DIR)/geometry.o
	gcc $(OBJ_TEST_DIR)/main.o  $(OBJ_TEST_DIR)/geometry.o  $(OBJ_TEST_DIR)/parser.o $(OBJ_DIR)/geometry.o -o $(BIN_DIR)/testing -lm $(FLAG)


$(OBJ_TEST_DIR)/main.o: $(TEST_DIR)/main.c
	gcc -c $(TEST_DIR)/main.c -o  $(OBJ_TEST_DIR)/main.o $(FLAG)


$(OBJ_TEST_DIR)/geometry.o: $(TEST_DIR)/geometry.c
	gcc -c $(TEST_DIR)/geometry.c -o  $(OBJ_TEST_DIR)/geometry.o -lm $(FLAG)


$(OBJ_TEST_DIR)/parser.o: $(TEST_DIR)/parser.c
	gcc -c $(TEST_DIR)/parser.c -o  $(OBJ_TEST_DIR)/parser.o $(FLAG)

clean:
	find -name "*.o" -exec rm -rf {} +
	rm -rf ./bin/geometry


run: all
	$(BIN_DIR)/geometry
	$(BIN_DIR)/testing

install:
	sudo cp ./bin/geometry /usr/bin/geometry

uninstall:
	sudo rm -f /usr/bin/geometry
