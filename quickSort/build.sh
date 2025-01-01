#!/bin/bash

echo "Building from source...";
if [ $1 == test ] 
then make test && ./test | echo "Running tests"
else make example && ./example
fi

