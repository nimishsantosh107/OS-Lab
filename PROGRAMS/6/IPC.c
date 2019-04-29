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
	sleep(5);
	printf("%d\n", *a);
	shmdt(a);
	shmctl(id , IPC_RMID , NULL);
	return(0);
}


//  pid_t proid;
// 	int id = shmget(101 , 10 , IPC_CREAT | 00666);
// 	proid = fork();
// 	if(proid==0){
// 		int *a;
// 		a = shmat(id,NULL,0);
// 		sleep(2);
// 		*a = 5;
// 		shmdt(a);
// 		printf("CHILD\n");
// 	}
// 	if(proid > 0){
// 		int *b;
// 		b = shmat(id,NULL,0);
// 		wait(0);
// 		printf("%d\n", *b);
// 		shmdt(b);
// 		printf("PARENT\n");
// 	}
// 	shmctl(id , IPC_RMID , NULL);