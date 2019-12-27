#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *wre;
	wre=fopen("old.txt","w+");
	if(wre==NULL)
	{
		printf("not open\n");
	}
	printf("file open\n");
	fwrite("hi i am garima",1,14,wre);
	fclose(wre);
	return 0;
}
