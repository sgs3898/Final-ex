#include<stdio.h>
#include<unistd.h>

int main(void){
	int i;
	printf("start sleeping\n");
	
	for(i=0;i<100;i++){
		printf("sleeping\n");

	sleep(1);
	}


	return(0);
}
