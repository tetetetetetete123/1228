#include"pcpy.h"

int procreate(const char * SFile,const char * DFile,int pronum,int blocksize)
{
	int flag;
	pid_t pid;

	int pos;
	char cblock[10];
	char cpos[10];
	bzero(cblock,sizeof(cblock));
	bzero(cpos,sizeof(cpos));

	for(flag = 0;flag < pronum;flag++)
	{
		pid = fork();
		if(pid == 0)
			break;
	}
	if(pid > 0)
	{
		printf("parent pro pid[%d] 非阻塞回收..\n",getpid());
		pid_t zpid;

		while((zpid = waitpid(-1,NULL,WNOHANG))!= -1)
		{
			if(zpid > 0)
				printf("parent wait success:zombie pid [%d]\n",zpid);
		}
	}
	else if(pid == 0)
	{
		//偏移量计算
		pos = flag * blocksize;
		sprintf(cblock,"%d",blocksize);
		sprintf(cpos,"%d",pos);
		//重载
		execl("/home/colin/20210322/PROCESS/processcpy/Copy","./Copy",SFile,DFile,cblock,cpos,NULL);
	}
	else
	{
		perror("FORK CALL FAILED");
		exit(-1);
	}
	return 0;

	

}
