test: binaryTree.o test.o
	gcc -o test binaryTree.o test.o

binaryTree.o: binaryTree.c
	gcc -c binaryTree.c

test.o: test.c
	gcc -c test.c

.PHONY: test binaryTree.o test.o
