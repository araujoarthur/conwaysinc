# Makefile for Conways Game of Life

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Werror

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Source files
MAIN = $(SRC_DIR)/main.c
CORE = $(SRC_DIR)/conwaysCore.c
SURROUNDS = $(SRC_DIR)/conwaysSurrounds.c
INTERFACE = $(SRC_DIR)/conwaysInterface.c

# Object files
MAIN_OBJ = $(BUILD_DIR)/main.o
CORE_OBJ = $(BUILD_DIR)/conwaysCore.o
SURROUNDS_OBJ = $(BUILD_DIR)/conwaysSurrounds.o
INTERFACE_OBJ = $(BUILD_DIR)/conwaysInterface.o

# Output binary
OUTPUT = $(BIN_DIR)/conways

all: $(OUTPUT)

$(OUTPUT): $(MAIN_OBJ) $(CORE_OBJ) $(SURROUNDS_OBJ) $(INTERFACE_OBJ)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(MAIN_OBJ) $(CORE_OBJ) $(SURROUNDS_OBJ) $(INTERFACE_OBJ)

$(MAIN_OBJ): $(MAIN)
	$(CC) $(CFLAGS) -c $(MAIN) -o $(MAIN_OBJ)

$(CORE_OBJ): $(CORE)
	$(CC) $(CFLAGS) -c $(CORE) -o $(CORE_OBJ)

$(SURROUNDS_OBJ): $(SURROUNDS)
	$(CC) $(CFLAGS) -c $(SURROUNDS) -o $(SURROUNDS_OBJ)

$(INTERFACE_OBJ): $(INTERFACE)
	$(CC) $(CFLAGS) -c $(INTERFACE) -o $(INTERFACE_OBJ)

clean:
	rm -f $(BUILD_DIR)/*.o $(OUTPUT)

.PHONY: clean all
