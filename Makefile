SOURCE_DIRECTORY = ./src
BUILD_DIRECTORY = ./build

.PHONY: clean conways


conways:
	cc $(SOURCE_DIRECTORY)/main.c -o $(BUILD_DIRECTORY)/conways

clean:
	rm -rf $(BUILD_DIRECTORY)
	mkdir $(BUILD_DIRECTORY)