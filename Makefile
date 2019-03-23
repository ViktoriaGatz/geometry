SRC_DIR := ./src
BIN_DIR := ./bin
OBJ_DIR := ./obj

all: $(SRC_DIR)/prog


$(SRC_DIR)/prog:  $(OBJ_DIR)/main.o  $(OBJ_DIR)/geometry.o  $(OBJ_DIR)/parser.o
	gcc -Wall -Wextra  $(OBJ_DIR)/main.o  $(OBJ_DIR)/geometry.o  $(OBJ_DIR)/parser.o -o $(BIN_DIR)/main -lm


$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/main.c -o  $(OBJ_DIR)/main.o


$(OBJ_DIR)/geometry.o: $(SRC_DIR)/geometry.c
		gcc -Wall -Wextra -c  $(SRC_DIR)/geometry.c -o  $(OBJ_DIR)/geometry.o -lm


$(OBJ_DIR)/parser.o: $(SRC_DIR)/parser.c
	gcc -Wall -Wextra -c  $(SRC_DIR)/parser.c -o  $(OBJ_DIR)/parser.o

clean:
	rm -f *.o
	rm -f main
