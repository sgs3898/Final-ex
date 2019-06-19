#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sigint_handler(int signo){
	int ndx;

	printf("Ctr + C 누르셨죠?\n");
	printf("10초간 대기하겠습니다. 이때 Ctr + Z를 눌러 주세요.\n");

	for(ndx = 10; 0 < ndx; ndx--){
		printf("%d초 남았습니다.\n", ndx);
		sleep(1);
	}
}

int main(void){
	struct sigaction act;

	act.sa_handler = sigint_handler;
	sigfillset(&act.sa_mask);

	sigaction(SIGINT, &act, NULL);

	while(1){
		printf("signal handler registered SIGINT\n");
		sleep(1);
	}
}
