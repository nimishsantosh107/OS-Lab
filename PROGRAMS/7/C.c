#include<stdio.h>
#include<unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>

int main(){
	int id = shmget(101 , 10 , IPC_CREAT | 00666);
	int *a;
	a = shmat(id,NULL,0);
	printf("ENTER VAL: ");
	scanf("%d",a);
	shmdt(a);
	return 0;
}
