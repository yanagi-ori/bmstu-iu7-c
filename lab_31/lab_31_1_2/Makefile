app.exe : io.o array.o main.o
	gcc -o app.exe main.o io.o array.o

io.o: io.c io.h errors.h
	gcc -std=c99 -Wall -Werror -pedantic -c io.c

array.o: array.c array.h errors.h
	gcc -std=c99 -Wall -Werror -pedantic -c array.c

main.o: main.c errors.h io.h array.h
	gcc -std=c99 -Wall -Werror -pedantic -c main.c

clean :
	rm *.o *.exe