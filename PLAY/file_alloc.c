#include<stdio.h>
#include<stdlib.h>


typedef struct cont{
	int file;
} Cont;
Cont contBlock[15];

int main(){
	for (int i = 0; i < 15; ++i){
		int in = rand()%2;
		contBlock[i].file=in;
		printf("  %d",in);	
	}printf("\n");

	int size = 4;
	int startInd = -1;
	for (int i = 0; i < 15-size+1; ++i)
	{
		
	}
}