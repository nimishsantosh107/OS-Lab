#include<stdio.h>

int main(){
	int pfault=0;
	int rfstr = 20;
	int refstr[20] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
	int fsize = 3;
	int frames[3]={-1};
	int j=0;

	for (int i = 0; i < rfstr; i++){
		int avail = 0;
		for(int k=0;k<fsize;k++)
			if(refstr[i]==frames[k])
				avail=1;
		if(avail==0){
			pfault++;
			frames[j]=refstr[i];
			j=(j+1)%fsize;
		}
	}
	printf("%d\n", pfault);
	return 0;
}