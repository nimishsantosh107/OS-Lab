#include<stdio.h>
#define MAX 5

int frames[MAX] = {2,4,6,8,10};

void printlist(){
	printf("MEMBLOCK:   ");
	for (int i = 0; i < 5; ++i)
		printf("%d   ",frames[i]);
	printf("\n");
}

int maxx(){
	int max=0;
	for (int i = 1; i < 5; i++){
		if(frames[i]>=frames[max])
			max=i;
	}
	// printf("MAX: %d\n", frames[max]);
	return max;
}

void firstfit(int p){
	for (int i = 0; i < 5; ++i){
		if(frames[i]>=p){
			frames[i]-=p;
			printlist();
			return;
		}
	}
}

void worstfit(int p){
	int m = maxx();
	if(frames[m]>=p){
		frames[m]-=p;
		printlist();
		return;
	}
	else{
		printf("CANNOT ALLOC\n");;
		return;
	}
}

void bestfit(int p){
	int minind,minval=10000;
	int found=0;
	for (int i = 0; i < 5; ++i){
		if (frames[i]>=p){
			found = 1;
			if((frames[i]-p)<minval){
				minval=frames[i]-p;
				minind=i;
			}
		}
	}
	if(found==0){printf("NOT ALLOC\n");}
	else{
		frames[minind]-=p;
	}
	printlist();
}

int main(){
	//firstfit(7);
	//worstfit(3);
	//bestfit(6);
	return 0;
}
