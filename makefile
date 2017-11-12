all: heated.c
	gcc -o heated heated.c
run: all
	./heated
