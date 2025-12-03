CC = gcc
OBJECTS = entry.o
FLAGS = -Wall -Werror -g
EXEC = journal linkedList

journal: entry.o
	$(CC) entry.o -o $(EXEC)

linkedList: entry.o
	$(CC) entry.o -o $(EXEC)

entry.o: entry.c entry.h
	$(CC) $(FLAGS) -c entry.c

clean: 
	rm -f $(OBJECTS) $(EXEC)