#!/bin/sh

trap 'echo "Got signal"' USR1

./program &
wait

echo "script end"