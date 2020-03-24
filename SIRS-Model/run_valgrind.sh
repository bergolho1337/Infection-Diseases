#!/bin/bash
PNAME="./bin/SIR"
CONFIG_FILE="inputs/simple-infection.ini"

if [ ! -f $PNAME ]; then
	./recompile_project.sh
fi

valgrind --leak-check=full --show-leak-kinds=all ./$PNAME $CONFIG_FILE
