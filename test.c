#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
	exit(0);
}

	// //ARG LEN CHECK
	// if(argc < 2)
	// 	exit(1);

	// //ARG CHECK
	// if(strcmp(argv[1],"-a")==0)
	// 	_a();
	// else if (strcmp(argv[1],"-1")==0)
	// 	_1();
	// else if (strcmp(argv[1],"-l")==0)
	// 	_l();

	// //SRC CHECK
	// int src = open(argv[2],O_RDONLY);
	// if(src==-1)
	// 	exit(1);

	// //DIR CHECK
	// DIR *p;
	// struct dirent *d;

	// if((p = opendir(".")) == NULL)exit(1);

	// while((d = readdir(p))!=NULL)
	// 	printf("%s\n",d->d_name);

	// char a;
	// int src = open("file.txt",O_RDONLY);
	// int fd = open("new.txt",O_WRONLY | O_TRUNC);
	// int fd2 = creat("s.txt" , O_CREAT | 0666);
	// while(read(src , &a , 1))
	// 	write(fd2 , &a , 1);
	// close(src);
	// close(fd);