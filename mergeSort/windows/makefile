!include <win32.mak>
SOURCE_DIR=../source/
TESTS_DIR=../tests/
EXAMPLE_DIR=../examples/
OBJ_DIR=../obj/


all: $(SOURCE_DIR)example.exe $(TESTS_DIR)test.exe

example.exe: $(OBJ_DIR)mergeSort.obj $(OBJ_DIR)example.obj
	$(link) -out:example.exe $(OBJ_DIR)mergeSort.obj $(OBJ_DIR)example.obj 

test.exe: $(OBJ_DIR)mergeSort.obj $(OBJ_DIR)test.obj
	$(link) -out:test.exe $(OBJ_DIR)mergeSort.obj $(OBJ_DIR)test.obj

mergeSort.obj: $(SOURCE_DIR)mergeSort.c
	$(cc) -c $(SOURCE_DIR)mergeSort.c

example.obj: $(EXAMPLE_DIR)example.c
	$(cc) -c $(EXAMPLE_DIR)example.c

test.obj: $(TESTS_DIR)test.c
	$(cc) -c $(TEST_DIR)test.c
