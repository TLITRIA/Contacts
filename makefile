test01:test01.o
	gcc test01.o -o test01

test01.o:test01.c
	gcc -c test01.c -o test01.o

clean:
	@rm -rf *.o test01