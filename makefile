all: algorithms.so

OBJ_DIR=./obj/
OBJ=./lib/obj/mergeSort.o ./lib/obj/quickSort.o ./lib/obj/binarySearch.o 

algorithms.so: obj.o 
	gcc $(OBJ) -shared -o ./lib/algorithms.so

obj.o: mergeSort.o quickSort.o binarySearch.o 


mergeSort.o: ./mergeSort/source/mergeSort.c
	gcc -c -fPIC ./mergeSort/source/mergeSort.c -o ./lib/obj/mergeSort.o

quickSort.o: ./quickSort/source/quickSort.c
	gcc -c -fPIC ./quickSort/source/quickSort.c -o ./lib/obj/quickSort.o

binarySearch.o: ./binarySearch/source/binarySearch.c
	gcc -c -fPIC ./binarySearch/source/binarySearch.c -o ./lib/obj/binarySearch.o

clear: 
	rm ./lib/algorithms.so ./lib/obj/*.o

