@echo off
rem run this only from msvc-enabled console

cl.exe /c .\source\binarySearch.c /Fo .\obj\binarySearch.obj
cl.exe /c .\examples\example.c /Fo .\obj\example.obj
cl.exe /c .\tests\test.c /Fo .\obj\test.obj

cl.exe .\obj\binarySearch.obj .\obj\example.obj /OUT:example
cl.exe .\obj\binarySearch.obj .\obj\test.obj /OUT:test


