#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>

int block(const char* File,int pronum);
int check_arg(const char* SFile,int arg_num,int pronum);
int procreate(const char* SFile,const char* DFile,int pronum,int block);

