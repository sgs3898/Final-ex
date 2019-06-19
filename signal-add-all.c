#include<stdio.h>
#include<signal.h>

int main(void){
	sigset_t set;

	sigfillset(&set);

	switch(sigismember(&set, SIGINT)){
		case 1 : printf("SIGINT OK\n");
				 break;
		case 0 : printf("SIGINT NO\n");
				 break;
		default : printf("sigismember() 호출 실패.\n");
	}
	return 0;
}
