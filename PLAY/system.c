#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<pthread.h>

int main(int argc, char const *argv[])
{
	char f[30]="hi";
	printf("%s\n", f);
	strcpy(f,"b");
	printf("%s\n", f);


	// int status = remove("lol.txt");
	// if (status == 0)
	// 	printf("SUCCESS\n");
	// else
	// 	printf("FAIL\n");

	// char* p;
	// char f[20]="sdk";
	// char c[20] = "";
	// char a='k';
	// char b= 'l';
	// char t[2];
	// printf("%s\n", c);
	// t[0]=a;
	// t[1]='\0';
	// strcat(c,t);
	// printf("%s\n", c);
	// t[0]=b;
	// t[1]='\0';
	// strcat(c,t);
	// printf("%s\n", c);
	// p = strstr(f,c);
	// if(p)
	// 	printf("%s\n", p);
	// else
	// 	printf("NO\n");
}