@echo off
rem run this only from msvc-enabled console

cl.exe /c .\source\quickSort.c /Fo .\obj\quickSort.obj
cl.exe /c .\examples\example.c /Fo .\obj\example.obj
cl.exe /c .\tests\test.c /Fo .\obj\test.obj

cl.exe .\obj\quickSort.obj .\obj\example.obj /OUT:example
cl.exe .\obj\quickSort.obj .\obj\test.obj /OUT:test


