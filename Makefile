all: work12.o
	gcc -o work12.out work12.o

work12.o: work12.c
	gcc -c work12.c


run: all
	./work12.out

clean:
	rm -f ./work12.out
	rm -f ./work12.o
