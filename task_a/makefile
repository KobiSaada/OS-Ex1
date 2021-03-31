CC = gcc
FLAGS = -Wall -g

all:main1_1 main1_2 main1_3

main1_1: main1_1.o hello_Ariel.o
	$(CC) $(FLAGS) -o $@ main1_1.o hello_Ariel.o

main1_2: main1_2.o lib.so
	$(CC) $(FLAGS) -o $@ main1_2.o -L. ./lib.so

main1_3: main1_3.o
	$(CC) $(FLAGS) -o $@ main1_3.o -ldl

main1_1.o: main1_1.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_1.c 

main1_2.o:main1_2.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_2.c 

main1_3.o:main1_3.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_3.c 

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) $(FLAGS) -c hello_Ariel.c 

lib.so: hello_Ariel.o hello_Ariel.h
	$(CC) -shared -o lib.so hello_Ariel.o

.PHONY: clean all

clean:
	rm -f *.o *.a *.so main1_1 main1_2 main1_3
