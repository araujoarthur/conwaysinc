# Define variables
SOURCE_DIRECTORY = src
BUILD_DIRECTORY = build
CC = gcc
CFLAGS = -Wall -Werror

# Define the list of source files
SOURCES = $(wildcard $(SOURCE_DIRECTORY)/*.c)
OBJECTS = $(patsubst $(SOURCE_DIRECTORY)/%.c, $(BUILD_DIRECTORY)/%.o, $(SOURCES))

# Define the build rules
conways: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BUILD_DIRECTORY)/$@ $^

$(BUILD_DIRECTORY)/%.o: $(SOURCE_DIRECTORY)/%.c $(SOURCE_DIRECTORY)/conways.h | $(BUILD_DIRECTORY)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIRECTORY):
	mkdir -p $@

# Define the clean rule
clean:
	rm -rf $(BUILD_DIRECTORY)

.PHONY: clean
