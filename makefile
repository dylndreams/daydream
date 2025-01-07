
msg ?= $(shell bash -c 'read -p "COMMITMSG:" msg; echo $$msg')

all: build

build:
	gcc src/main.c -w -lSDL2 -lm -o build.out -std=c99 -Os -s
	./build.out

commit:
	git add .
	git commit -m $(msg)
	git push -u origin main
