#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *read;
	char data[20];
	read=fopen("new.txt","r+");
	if(read==NULL)
	{
		printf("file not read");
	}
	printf("file read\n");
	fread(data,1,18,read);
	printf("%s\n",data);
//	printf("close file\n");
	fclose(read);
	return 0;
}
