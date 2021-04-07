CC = gcc
FLAGS = -Wall -g


all: main2_1 main2_2 main2_3 main2_4

 main2_1:  main2_1.o
	$(CC) $(FLAGS) -o  main2_1  main2_1.o

main2_2: main2_2.o
	$(CC) $(FLAGS) -o main2_2 main2_2.o

main2_3: main2_3.o
	$(CC) $(FLAGS) -o main2_3 main2_3.o

main2_4:main2_4.o main2_1 main2_2 main2_3
	$(CC) $(FLAGS) -o main2_4 main2_4.o

main2_4.o: main2_4.c  main2_1.o main2_2.o main2_3.o
	$(CC) $(FLAGS) -c main2_4.c

main2_3.o: main2_3.c
	$(CC) $(FLAGS) -c main2_3.c	

main2_2.o: main2_2.c
	$(CC) $(FLAGS) -c main2_2.c

 main2_1.o: main2_1.c 
	$(CC) $(FLAGS) -c  main2_1.c

.PHONY: clean all

clean:
	rm -f *.o  main2_1 main2_3 main2_3 main2_4
