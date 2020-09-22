
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
//#include "testsim.c"

int main(int argc, char* argv[])
{
	int opt;
	int pr_limit;
	int pr_count = 0;
	pid_t childpid = 0;
	int i;


	if(argc < 2) {
		fprintf(stderr, "There must be at least 2 arguments\n");
		return -1;
	}

	while ((opt = getopt(argc, argv, "hn:")) != -1) {
		switch(opt) {
			case 'h':
				printf("%s: Usage: ./proc_fan -n x, where x is some int\n", argv[0]);
				return -1;
			case 'n':
				pr_limit = atoi(optarg);
				break;
			default:
				printf("Usage: ./proc_fan -n x, where x is some int\n");
				return -1;
		}
	}

	for(i = 1; i < pr_limit; i++) {
		if((childpid = fork()) <= 0) {
			break;
		}
		if(pr_limit == pr_count) {
			wait(NULL);
			pr_count--;
		}
	}
	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
		i, (long) getpid(), (long)getppid(), (long) childpid);
	
	return 0;
}
