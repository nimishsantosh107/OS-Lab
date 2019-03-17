#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
	//DECLARATIONS
	char buf;
	int limit,offset=0;

	//ARG LEN CHECK
	if(argc == 1)
		exit(1);
	else if(argc == 2)
		limit = 5;
	else if(argc == 3){
		limit = argv[1][1]-'0';
		offset=1;
	}
	
	//OPEN SRC
	int fd = open(argv[1+offset], O_RDONLY);
	if(fd == -1) exit(1);

	//PRINT TO SCREEN
	int instances = 0;
	while(instances < limit) {
		int status = read(fd , &buf , 1);
		if(status == 0 || status == -1){
			close(fd);
			exit(1);
		}
		
		if(buf == '\n')
			instances+=1;
		printf("%c", buf );
	}

	close(fd);
	exit(0);
}