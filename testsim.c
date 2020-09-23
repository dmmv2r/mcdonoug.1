//Author: Donovan McDonough
//Date: 9/22/2020

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) 
{
	int i;
	int count;
	int time;

	//checks valid number of arguments are passed in
	if(argc != 3) {
		printf("Invalid number of arguments in testsim\n");
		return -1;
	}

	count = atoi(argv[2]); //allocates number of times process should be performed
	time = atoi(argv[1]); //allocates amount of time program should sleep

	//loops a number of "count" times and outputs the processes pid
	for(i = 0; i < count; i++) {
		sleep(time);
		fprintf(stderr, "pid: %ld\n", (long)getpid());
	}
	
	return 0;
}
