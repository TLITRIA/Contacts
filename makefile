test01:test01.o doubleLinkListQueue.o doubleLinkList.o balanceBinarySearchTree.o
	gcc test01.o doubleLinkListQueue.o doubleLinkList.o balanceBinarySearchTree.o -o test01

test01.o:test01.c
	gcc -c test01.c -o test01.o

doubleLinkListQueue.o:doubleLinkListQueue.c
	gcc -c doubleLinkListQueue.c -o doubleLinkListQueue.o

doubleLinkList.o:doubleLinkList.c
	gcc -c doubleLinkList.c -o doubleLinkList.o

balanceBinarySearchTree.o:balanceBinarySearchTree.c
	gcc -c balanceBinarySearchTree.c -o balanceBinarySearchTree.o


clean:
	@rm -rf *.o test01