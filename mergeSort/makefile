obj_example: ./examples/example.c
	gcc -c ./examples/example.c -o ./obj/example.o
	

obj_test: ./tests/test.c
	gcc -c ./tests/test.c -o ./obj/test.o


obj_qsort: ./source/mergeSort.c
	gcc -c ./source/mergeSort.c -o ./obj/mergeSort.o

test: obj_qsort obj_test
	gcc ./obj/mergeSort.o ./obj/test.o -o test

example: obj_qsort obj_example
	gcc ./obj/mergeSort.o ./obj/example.o -o example

clear: 
	rm ./obj/*.o example test

