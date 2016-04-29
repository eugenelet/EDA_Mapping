# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-c -Wall
DFLAGS=-g

all: EDA

EDA: main.cpp cell.cpp
	$(CC) $(DFLAGS) main.cpp cell.cpp -o EDA


clean:
	rm *o EDA
