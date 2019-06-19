#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void(*old_fun)(int);

void sigint_handler(int signo){
	printf("Ctr + C !!\n");
	printf("한번더 누르면 종료\n");
	signal(SIGINT, old_fun); // or signal(SIGINT, SIG_DFL);
}
int main(void){
	old_fun = signal(SIGINT, sigint_handler);

	while(1){
		printf("signal handler registered!\n");
		sleep(1);
	}

	return(0);
}
