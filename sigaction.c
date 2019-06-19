
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

struct sigaction act_new;
struct sigaction act_old;

void sigint_handler(int signo){
	printf("Ctr + C\n");
	printf("또하면 종료\n");
	sigaction(SIGINT, &act_old, NULL);

}
int main(void){

	act_new.sa_handler = sigint_handler;
	sigemptyset(&act_new.sa_mssk);


	sigaction(SIGINT, &act_new, &act_old);

	while(1)
	{
		printf("sigaction\n");
		sleep(1);
	}
	return 0;
}
