#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<fcntl.h>
#include <sys/stat.h>


void _a(char *dir){
	//DIR CHECK
	DIR *p = opendir(dir);
	if(p==NULL)
		exit(1);

	struct dirent *d;
	while((d = readdir(p))!=NULL)
		printf("%s\n",d->d_name);}
void _1(char *dir){
	//DIR CHECK
	DIR *p = opendir(dir);
	if(p==NULL)
		exit(1);

	struct dirent *d;
	while((d = readdir(p))!=NULL){
		char c = (d->d_name)[0];
		if(c=='.')
			continue;
		printf("%s\n",d->d_name);
	}}
void _l(char *dir){
	DIR *p = opendir(dir);
	if(p==NULL)
		exit(1);

	struct dirent *d;
	while((d = readdir(p))!=NULL){
		char c = (d->d_name)[0];
		if(c=='.')
			continue;

		struct stat fileStat;
		stat(d->d_name,&fileStat);
		printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
		printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
        printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
        printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
        printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
        printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
        printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
        printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
        printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
        printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
		printf("\t%s\n",d->d_name);
	}}

int main(int argc, char *argv[])
{
	//ARG LEN CHECK
	if(argc == 1)
		exit(1);
	else if (argc == 2){
		// ARG CHECK
		if(strcmp(argv[1],"-a")==0)
			_a(".");
		else if (strcmp(argv[1],"-1")==0)
			_1(".");
		else if (strcmp(argv[1],"-l")==0)
			_l(".");
	}
	else if (argc == 3){
		// ARG CHECK
		if(strcmp(argv[1],"-a")==0)
			_a(argv[2]);
		else if (strcmp(argv[1],"-1")==0)
			_1(argv[2]);
		else if (strcmp(argv[1],"-l")==0)
			_l(argv[2]);
	}
	exit(0);
}