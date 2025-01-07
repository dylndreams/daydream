CC = gcc
OBJS = src/main.o
LDFLAGS = -Llibs/z8lua -llua -lSDL2 -lm -lc
CFLAGS = -std=c99 -Os -s

msg ?= $(shell bash -c 'read -p "COMMITMSG:" msg; echo $$msg')

all: build

build: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(CFLAGS) -o build.out
	./build.out

src/main.o: src/main.c

commit:
	git add .
	git commit -m $(msg)
	git push -u origin main


clean:
	rm -f build.out $(OBJS)

