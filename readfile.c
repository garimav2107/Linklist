#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *re;
	char data[18];
	re=fopen("old.txt","r");
	if(re==NULL)
	{
		printf("file not read");
	}
	printf("file read\n");
	fread(&data,1,14,re);
	printf("%s",data);
	fclose(re);
	return 0;
}
