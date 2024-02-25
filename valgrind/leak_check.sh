#!/bin/sh

gcc no_leak.c -o no_leak
gcc leak.c -o leak

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=no_leak.txt ./no_leak
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=leak.txt ./leak