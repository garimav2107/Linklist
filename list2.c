#include<stdio.h>
#include<stdlib.h>
struct node
{
	char day[20];
	char month[20];;
	int time;
	struct node *inc_day;
	struct node *dec_day;
};
struct node *start;
int menu(int x)
{
	printf("enter choice:\n1.addinfo\n2.edit info\n3.print all info\n4.exit\n");
	scanf("%d",&x);
	return x;
}
int linkall()
{
	int i,n;
	printf("enter no of info=");
	scanf("%d",&n);
	struct node *old_day,*presnt;
	start=(struct node*)malloc(sizeof(struct node));
	start->dec_day=NULL;
	start->inc_day=(struct node*)malloc(sizeof(struct node));
	old_day=start;
	presnt=start->inc_day;
	for(i=2;i<n;i++)
	{
		presnt->dec_day=old_day;
		presnt->inc_day=(struct node*)malloc(sizeof(struct node));
		old_day=presnt;
		presnt=presnt->inc_day;
		if(i==(n-1))
		{
			presnt=NULL;
		}
	}
	return 0;
}
int addinfo()
{
	struct node *add;
	add=start;
	while(add!=NULL)
	{
		printf("enter day=");
		scanf("%s",add->day);
		printf("enter month=");
		scanf("%s",add->month);
		printf("enter time=");
		scanf("%d",&add->time);
		add=add->inc_day;
	}
	return 0;
}
int printinfo()
{
	struct node *pri;
	pri=start;
	printf("month\tday\ttime\n");
	while(pri!=NULL)
	{
		printf("%s\t",pri->month);
		printf("%s\t",pri->day);
		printf("%d.00 o'clock\n",pri->time);
		pri=pri->inc_day;
	}
	return 0;
}
int main()
{
	int choice;
	choice=menu(choice);
	while(choice!=4)
	{
		if(choice==1)
		{
			linkall();
		}
		if(choice==2)
		{
			addinfo();
		}
		if(choice==3)
		{
			printinfo();
		}
		choice=menu(choice);
	}
	return 0;
}


