CC=g++
CPPFLAGS= -O2

SRC=src
BUILD=build

.PHONY: always all build 

all: always build

build:
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp -o $(BUILD)/Shogi++


always:
	mkdir -p build

.PHONY: clean

clean:
	rm -rf build
