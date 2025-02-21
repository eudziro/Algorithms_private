#!/bin/bash

echo "Building from source...";
if [ $1 == test ] 
then make test && ./test
else make example && ./example
fi

