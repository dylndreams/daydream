CC = gcc
SRCS = src/main.c src/cmixer.c
LDFLAGS = -Llibs/z8lua -llua -lSDL2 -lm -lc -g
CFLAGS = -std=c99 -Oz -s -g

msg ?= $(shell bash -c 'read -p "COMMITMSG:" msg; echo $$msg')

all: run

run: build
	@./build.out

build: $(SRCS)
	@$(CC) $< src/cmixer.c $(LDFLAGS) $(CFLAGS) -o build.out

commit:
	@git add .
	@git commit -m $(msg)
	@git push -u origin main

clean:
	rm -f build.out $(OBJS)

