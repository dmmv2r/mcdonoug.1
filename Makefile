all: runsim testsim

mcdonoug.1: runsim.o
	gcc -Wall -g runsim.o -o proc_fan

runsim.o: runsim.c
	gcc -Wall -g -c runsim.c

mcdonoug.1: testsim.o
	gcc -Wall -g testsim.o -o testsim

testsim.o: testsim.c
	gcc -Wall -g -c testsim.c

clean:
	rm -rf *o mcdonoug.1 proc_fan
