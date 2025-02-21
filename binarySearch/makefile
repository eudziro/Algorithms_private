SOURCE_DIR=./source/
TESTS_DIR=./tests/
EXAMPLE_DIR=./examples/
OBJ_DIR=./obj/
LIB_OBJ_DIR=../lib/obj/

LIB_DIR=../lib/


obj_example: $(EXAMPLE_DIR)example.c
	gcc -c $(EXAMPLE_DIR)example.c -o ./obj/example.o
	

obj_test: $(TESTS_DIR)test.c
	gcc -c $(TESTS_DIR)test.c -o ./obj/test.o


test: ../lib/algorithms.so obj_test
	gcc  $(OBJ_DIR)test.o ../lib/algorithms.so -o test

example: ../lib/algorithms.so obj_example
	gcc ../lib/algorithms.so $(OBJ_DIR)example.o -o example

clear: 
	rm $(OBJ_DIR)*.o example test
