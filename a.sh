#!/bin/bash

make re

TEST_INPUT=$(seq 0 100 | shuf | tr '\n' ' ')
MOVEMENTS=$(./push_swap $TEST_INPUT | wc -l)
RESULT=$(./push_swap $TEST_INPUT | ./checker_linux $TEST_INPUT)

echo "moviventos: $MOVEMENTS"
echo "resultado: $RESULT"

# ./push_swap $TEST_INPUT
# echo "$TEST_INPUT"