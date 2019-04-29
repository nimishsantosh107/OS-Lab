#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include<stdlib.h>

int main(){
	pid_t proid;
	sem_t *sem;
	sem = sem_open("sem" , O_CREAT | O_EXCL, 0666 , 1);
	sem_unlink("sem");

	int id = shmget(101,10,IPC_CREAT | 0666);
	int *a = shmat(id, NULL , 0);
	//shmdt(a);
	//shmctl(id,IPC_RMID,NULL);

	proid = fork();
	
	if(proid>0){
		while(1){
			sleep(1);
			sem_wait(sem);
			*a = (rand()%10)+1;
			printf("PRODUCED: %d\n",*a);
			sem_post(sem);
		}
	}
	else if(proid==0){
		sleep(1);
		while(1){
			sleep(1);
			sem_wait(sem);
			printf("CONSUMED: %d\n",*a);
			*a = 0;
			sem_post(sem);
		}
	}
}