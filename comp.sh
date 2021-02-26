#!/bin/sh

g++ -Wall -Wextra $1 -o executable
cat input.txt | ./executable >> output.txt
cmp --silent output.txt solution.txt && echo '### SUCCESS ###' || echo '!!! FAILED !!!'
rm output.txt