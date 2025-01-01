#!/bin/bash 

echo "Building from source...";

if [[ $@ == test ]] 
then
make test && echo -e "Running tests...\n" && ./test  
elif [[ $@ == example ]] 
then 
make example && echo -e "Running examples...\n" && ./example
else echo "Bad argument, exiting..."
fi
