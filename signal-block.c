#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(void){
	sigset_t sigset;
	int ndx;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGINT);
	sigprocmask(SIG_BLOCK, &sigset, NULL);

	for(ndx = 10; 0 < ndx; ndx--){
		printf("카운트 다운 %d\n", ndx);
		sleep(1);
	}
	return(0);
}



