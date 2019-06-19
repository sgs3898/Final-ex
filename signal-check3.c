#include<stdio.h>
#include<signal.h>

int main(void)
{
	sigset_t set;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGSYS);

	switch(sigismember(&set, SIGINT)){
		case 1 : printf("SIGINT는 포함됨.\n");
				 break;
		case 0 : printf("SIGINT는 없다.\n");
				 break;
		default : printf("sigismember() 호출에 실패.\n");
	}
	sigdelset(&set, SIGINT);

	switch(sigismember(&set, SIGSYS)){
		case 1 : printf("SIGSYS는 포함됨.\n");
				 break;
		case 0 : printf("SIGSYS는 없다.\n");
				 break;
		default : printf("sigismember() 호출에 실패.\n");
	}
	return 0;
}
