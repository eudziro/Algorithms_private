SOURCE_DIR=./source/
TESTS_DIR=./tests/
EXAMPLE_DIR=./examples/
OBJ_DIR=./obj/


obj_example: $(EXAMPLE_DIR)example.c
	gcc -c $(EXAMPLE_DIR)example.c -o ./obj/example.o
	

obj_test: $(TESTS_DIR)test.c
	gcc -c $(TESTS_DIR)test.c -o ./obj/test.o


obj_msort: $(SOURCE_DIR)mergeSort.c
	gcc -c $(SOURCE_DIR)mergeSort.c -o $(OBJ_DIR)mergeSort.o

test: obj_msort obj_test
	gcc $(OBJ_DIR)mergeSort.o $(OBJ_DIR)test.o -o test

example: obj_msort obj_example
	gcc $(OBJ_DIR)mergeSort.o $(OBJ_DIR)example.o -o example

clear: 
	rm $(OBJ_DIR)*.o example test
