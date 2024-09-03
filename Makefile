CC=g++
CPPFLAGS= -Wall -Wextra -O2 -I src

SRC=src
BUILD=build

.PHONY: always all build 

all: always build

build:
	$(CC) $(CPPFLAGS) $(SRC)/shogi.cpp $(SRC)/main.cpp -o $(BUILD)/Shogi++


always:
	mkdir -p build

.PHONY: clean

clean:
	rm -rf build
