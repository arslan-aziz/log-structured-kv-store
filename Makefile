CC=gcc
CFLAGS=-I. -Wall

all: lskv lskv_test
	
lskv: main.o hashmap.o
	$(CC) $(CFLAGS) -o lskv main.o hashmap.o

lskv_test: hashmap_test.o hashmap.o munit.o
	$(CC) $(CFLAGS) -o lskv_test hashmap_test.o munit.o hashmap.o

main.o: src/main.c
	$(CC) -c src/main.c

hashmap.o: src/ds/hashmap.c
	$(CC) -c src/ds/hashmap.c

hashmap_test.o: test/ds/hashmap.c
	$(CC) -o hashmap_test.o -c test/ds/hashmap.c

munit.o: munit/munit.c
	$(CC) -c munit/munit.c

clean:
	rm -rf *o lskv