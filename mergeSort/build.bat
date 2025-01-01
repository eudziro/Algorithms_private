@echo off
rem run this only from msvc-enabled console

cl.exe /c .\source\mergeSort.c /Fo .\obj\mergeSort.obj
cl.exe /c .\examples\example.c /Fo .\obj\example.obj
cl.exe /c .\tests\test.c /Fo .\obj\test.obj

cl.exe .\obj\mergeSort.obj .\obj\example.obj /OUT:example
cl.exe .\obj\mergeSort.obj .\obj\test.obj /OUT:test


