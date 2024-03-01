#!/bin/sh

handle_signal() {
    echo "got signal run program2"
    ./program2 &
}

trap handle_signal USR1
./program &
wait

echo "script end"