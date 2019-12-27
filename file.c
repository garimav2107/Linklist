#include<stdio.h>
#include<stdlib.h>
int main()
{	
	FILE *fp;
	fp=fopen("new.txt","w+");
	if(fp==NULL)
	{
		printf("file not open\n");
		exit(0);
	}
	printf("file open");
	fwrite("hi....how are you?",1,18,fp);
	fclose(fp);
}
