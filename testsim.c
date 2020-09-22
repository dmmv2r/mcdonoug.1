
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) 
{
	int i;
	int count;
	int time;

	if(argc != 3) {
		printf("Invalid number of arguments in testsim\n");
		return -1;
	}

	count = atoi(argv[1]);
	time = atoi(argv[2]);

	for(i = 0; i < count; i++) {
		sleep(time);
		fprintf(stderr, "pid: %d\n", (long)getpid());
	}
	
	return 0;
}
