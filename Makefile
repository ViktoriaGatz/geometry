FLAGS := -std=c99
SRC_DIR := ./src
BIN_DIR := ./bin
OBJ_DIR := ./build

all: $(BIN_DIR)/geometry


$(BIN_DIR)/geometry:  $(OBJ_DIR)/main.o  $(OBJ_DIR)/geometry.o  $(OBJ_DIR)/parser.o
	gcc -Wall -Wextra  $(OBJ_DIR)/main.o  $(OBJ_DIR)/geometry.o  $(OBJ_DIR)/parser.o -o $(BIN_DIR)/geometry -lm $(FLAGS)


$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/main.c -o  $(OBJ_DIR)/main.o $(FLAGS)


$(OBJ_DIR)/geometry.o: $(SRC_DIR)/geometry.c
		gcc -Wall -Wextra -c  $(SRC_DIR)/geometry.c -o  $(OBJ_DIR)/geometry.o -lm $(FLAGS)


$(OBJ_DIR)/parser.o: $(SRC_DIR)/parser.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/parser.c -o  $(OBJ_DIR)/parser.o $(FLAGS)

clean:
	find -name "*.o" -exec rm -rf {} +
	rm -rf ./bin/geometry

install:
	sudo cp ./bin/geometry /usr/bin/geometry

uninstall:
	sudo rm -f /usr/bin/geometry
