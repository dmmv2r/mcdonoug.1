//Author: Donovan McDonough
//Date: 9/22/2020

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int opt;
	int pr_limit;
	int pr_count = 0;
	pid_t childpid = 0;
	const int MAX_CANON = 50;
	char read[MAX_CANON];
	FILE *testd;
	
	//checks for a valid number of arguments
	if(argc < 2) {
		fprintf(stderr, "There must be at least 2 arguments\n");
		return -1;
	}

	while ((opt = getopt(argc, argv, "hn:")) != -1) {
		switch(opt) {
			case 'h': //outputs help message
				printf("%s: Usage: %s -n x, where x is some int\n", argv[0], argv[0]);
				return -1;
			case 'n': //detects proper command line arguments
				pr_limit = atoi(optarg);
				break;
			default: //detects improper command line arguments
				printf("Usage: %s -n x, where x is some int\n", argv[0]);
				return -1;
		}
	}
	
	//opens test.data file for reading
	testd = fopen("test.data", "r");

	while(fgets(read, MAX_CANON, testd)) {

	//for(i = 1; i < pr_limit; i++) {
		if((childpid = fork()) <= 0) {
			perror("Error: child failed");
			return -1;
		}
		if(pr_limit == pr_count) { //checks if max number of processes has been reached
			wait(NULL);
			pr_count--;
		}
		pr_count++;

		strcat("./", read);
		system(read); //calls testsim with arguments from test.data
	}

	fclose(testd); //closes test.data
	
	return 0;
}
