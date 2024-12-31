SOURCE_DIR=./source/
TESTS_DIR=./tests/
EXAMPLE_DIR=./examples/
OBJ_DIR=./obj/


obj_example: $(EXAMPLE_DIR)exaple.c
	gcc -c $(EXAMPLE_DIR)example.c -o ./obj/example.o
	

obj_test: $(TESTS_DIR)test.c
	gcc -c $(TESTS_DIR)test.c -o ./obj/test.o


obj_binSearch: $(SOURCE_DIR)binarySearch.c
	gcc -c $(SOURCE_DIR)binarySearch.c -o $(OBJ_DIR)binarySearch.o

test: obj_binSearch obj_test
	gcc $(OBJ_DIR)binarySearch.o $(OBJ_DIR)test.o -o test

example: obj_binSearch obj_example
	gcc $(OBJ_DIR)binarySearch.o $(OBJ_DIR)example.o -o example

clear: 
	rm $(OBJ_DIR)*.o example test
