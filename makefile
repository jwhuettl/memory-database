# makefile for memory-database
# Jackson Huettl || 2019

# compiler is gcc
CC = gcc

# main make command
dbmake: main.c functions.c
	$(CC) main.c functions.c -o db -g 

# cleaning up
clean: 
	$(RM) db db.txt *.o *.~

# NOTE: .txt file will be deleted on clean