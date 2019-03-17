#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

//IN ALL FUNCTIONS SAME******* IS PRESENT

void _i(char *argv[]){
	//SAME*************
	DIR *p;
	struct dirent *d;
	char buf,opt;
	int r=0,fd;
	//DIR OPEN CHECK
	if((p = opendir(".")) == NULL)exit(1);

	//SRC CHECK
	int src = open(argv[2],O_RDONLY);
	if(src==-1) exit(1);

	//TO CHECK IF DEST EXISTS ALREADY
	while((d = readdir(p))!=NULL){
		if(strcmp(argv[3],d->d_name)==0){
			r = 1;
			break;
		}}
	//SAME**************
	if(r==1){
		printf("overwrite y/n\n");
		scanf("%c" , &opt);
		if(opt == 'n')
			exit(1);
		fd = open(argv[3] , O_WRONLY | O_TRUNC);}
	else fd = creat(argv[3] , O_CREAT | 0666);

	//SAME**************
	//COPY CONTENTS FROM SRC TO DEST
	while(read(src , &buf , 1))
		write(fd , &buf , 1);

	close(src);
	close(fd);
	//SAME**************
}

void _f(char *argv[]){
	//SAME*************
	DIR *p;
	struct dirent *d;
	char buf;
	int r=0,fd;
	//DIR OPEN CHECK
	if((p = opendir(".")) == NULL)exit(1);

	//SRC CHECK
	int src = open(argv[2],O_RDONLY);
	if(src==-1) exit(1);

	//TO CHECK IF DEST EXISTS ALREADY
	while((d = readdir(p))!=NULL){
		if(strcmp(argv[3],d->d_name)==0){
			r = 1;
			break;
		}}
	//SAME*************
	if(r==1) fd = open(argv[3] , O_WRONLY | O_TRUNC);
	else fd = creat(argv[3] , O_CREAT | 0666);

	//SAME*************
	//COPY CONTENTS FROM SRC TO DEST
	while(read(src , &buf , 1))
		write(fd , &buf , 1);
	close(src);
	close(fd);
	//SAME*************
}

void _n(char *argv[]){
	//SAME*************
	DIR *p;
	struct dirent *d;
	char buf;
	int r=0,fd;
	//DIR OPEN CHECK
	if((p = opendir(".")) == NULL)exit(1);

	//SRC CHECK
	int src = open(argv[2],O_RDONLY);
	if(src==-1) exit(1);

	//TO CHECK IF DEST EXISTS ALREADY
	while((d = readdir(p))!=NULL){
		if(strcmp(argv[3],d->d_name)==0){
			r = 1;
			break;
		}}
	if(r==1) exit(1);
	else fd = creat(argv[3] , O_CREAT | 0666);

	//COPY CONTENTS FROM SRC TO DEST
	while(read(src , &buf , 1))
		write(fd , &buf , 1);
	close(src);
	close(fd);
	//SAME*************
}

int main(int argc, char *argv[]){
	//ARG LEN CHECK
	if(argc < 4){ 
		printf("TOO FEW ARGUEMENTS\n");
		exit(1);}

	//ARG CHECK
	if(strcmp(argv[1],"-i")==0)
		_i(argv);
	else if (strcmp(argv[1],"-f")==0)
		_f(argv);
	else if (strcmp(argv[1],"-n")==0)
		_n(argv);

	exit(0);
}