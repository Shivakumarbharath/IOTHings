CC = gcc 
CFLAGS = -I . 

hellomake: hellomake.o hellofunc.o 
	$(CC) -o hellomake hellomake.o hellofunc.o $(CFLAGS)

hellomake.o: hellomake.c 
	$(CC) -c hellomake.c $(CFLAGS)

hellofunc.o : hellofunc.c 
	$(CC) -c hellofunc.c $(CFLAGS)
