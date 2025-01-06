


all: build

build:
	gcc main.c -w -lSDL2 -lm -o build.out -std=c99 -Wall -Os -s
	./build.out
