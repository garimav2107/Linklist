#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int menu(int x)
{
	printf("enter choice:\n1.connect\n2.update\n3.print\n4.add node\n5.delet\n6.count\n7.import\n8.export\n9.exit\n");
	scanf("%d",&x);
	return x;
}
struct list
{
	char name1[10];
	char add[20];
	char gen[10];
	int age;
	char mono;
	struct list *prev;
	struct list *next;
};
struct list *head;
int connect()
{
	int n,i;
	struct list *ptr,*old,*new;
	printf("no of node=");
	scanf("%d",&n);
	head=(struct list*)malloc(sizeof(struct list));
	head->prev=NULL;
	head->next=(struct list*)malloc(sizeof(struct list));
	ptr=head->next;
	old=head;
	printf("head=%p\thead->next=%p\n",old,head->next);
	for(i=2;i<n;i++)
	{
		//ptr=(struct list*)malloc(sizeof(struct list));
		ptr->prev=old;
		printf("%p\t",old);
		ptr->next=(struct list*)malloc(sizeof(struct list));
		old=ptr;
		ptr=ptr->next;
		printf("%p\n",ptr);
		if(i==(n-1))
		{
			ptr=NULL;
		}
	}
	return 0;
}
int update()
{
	struct list *a;
	a=head;
	while(a!=NULL)
	{
		printf("enter name=");
		scanf("%s",a->name1);
		printf("enter age=");
		scanf("%d",&a->age);
		printf("enter mono=");
		scanf("%s",&a->mono);
		printf("enter add=");
		scanf("%s",a->add);
		printf("enter gender=");
		scanf("%s",a->gen);
		a=a->next;
	}
	return 0;
}
int print()
{
	struct list *pr;
	pr=head;
	printf("------information-----------\n");
	while(pr!=NULL)
	{
		printf("name=%s\t",pr->name1);
		printf("age=%d\t",pr->age);
		printf("add=%s\t",pr->add);
		printf("mo.no=%s\t",&pr->mono);
		printf("gender=%s\t",pr->gen);
		pr=pr->next;
	}
	return 0;
}
int addnode()
{
	int x,i;
	struct list *add,*new,*ptr,*qtr,*rt;
	printf("No of position=");
	scanf("%d",&x);
	add=head;
	for(i=1;i<(x-1);i++)
	{
		add=add->next;
	}
	//printf("%p",add);
	new=(struct list*)malloc(sizeof(struct list));
	printf("enter name=");
	scanf("%s",new->name1);
	printf("enter age=");
	scanf("%d",&new->age);
	if(add->prev==NULL)
	{
		new->next=head;
		head=new;
	}
	if(add->next!=NULL)
	{
		ptr=add->next;
		add->next=new;
		//new->next=(struct list*)malloc(sizeof(struct list));
		new->prev=add;
		new->next=ptr;
		ptr->prev=add;
	}
	else
        {
                new->next=NULL;
                add->next=new;
                new->prev=add;
        }

	return 0;
}
int delet()
{
	int x,i;
	struct list *del,*qtr,*str,*rt;
	printf("enter no of pos delet=");
	scanf("%d",&x);
	del=head;
	for(i=0;i<(x-1);i++)
	{
		del=del->next;
	}
	if(del->next!=NULL)
	{
		qtr=del->next;
		str=del->prev;
		qtr->prev=str;
		str->next=qtr;
	}
	else
	{
		rt=del->next;
		rt=NULL;
	}
	return 0;
}
int count()
{
	int i=0;
	struct list *co;
	co=head;
	while(co!=NULL)
	{
		i++;
		co=co->next;
	}
	printf("no of node=%d\n",i);
	return 0;
}
int import()
{
	struct list *ptr1,*start,*pr;
	int z,s=0,i=0,j=0,k=0,t=0,di,add_size,age_size,name_size,gen_size,mono_size,*pt,*st;
	char read[200],*re,*q;
	re=&read[0];
        pt=&k;
	st=&s;
        start=head;
        pr=head;
        while (start->next!=NULL)
	{
        	start=start->next;
	}
	FILE *im;
	im=fopen("newa.txt","r+");
	if(im==NULL)
	{
        	printf("file creation failure\n");
	}
        printf("file creation sucess\n");
	fread(read,1,sizeof(read),im);
	for(i=0;read[i]!='\0';i++)
	{
        	if(read[i]==';')
		{
			t++;
		}
	}
	printf("%s\n%d\n",read,t);
	printf("start add=%p\n",start);
	for(z=0;z<t;z++)
	{
		printf("hello---\n");
		if(start->next==NULL)
		{
			ptr1=(struct list*)malloc(sizeof(struct list));
			//ptr1->next=NULL;
			ptr1->prev=start;
			start->next=ptr1;
		}
		q=strchr(re,',');
		name_size=q-re;
		printf("name size=%d\t",name_size);
		memcpy(ptr1->name1,re,name_size);
		q++;
		re=q;
                q=strchr(re,',');
                age_size=q-re;
                printf("age size=%d\t",age_size);
                k=0;
                for(j=0;j<age_size;j++)
                {
                        k=(k*10) + ((*re)-'0');
                        re++;
                }
                re=re-age_size;
                memcpy(&ptr1->age,pt,age_size);
                q++;
		re=q;
                q=strchr(re,',');
                mono_size=q-re;
                printf("mono size=%d\t",mono_size);
                /*s=0;
               for(j=0;j<mono_size;j++)
                {
                        s=(s*10)+((*re)-'0');
                        re++;
                }*/
                //re=re-mono_size;
                memcpy(&ptr1->mono,re,mono_size);
		q++;
		re=q;
		q=strchr(re,',');
		add_size=q-re;
		printf("add size=%d\t",add_size);
		memcpy(ptr1->add,re,add_size);
		q++;
		re=q;
		q=strchr(re,';');
		gen_size=q-re;
		printf("gen size=%d\n",gen_size);
		memcpy(ptr1->gen,re,gen_size);
		q++;
		re=q;
		start=ptr1;
	}
	printf("add=%p\n",pr);
	while(pr!=NULL)
	{
		printf("name=%s\n",pr->name1);
		printf("age=%d\n",pr->age);
		printf("mono=%s\n",&pr->mono);
		printf("add=%s\n",pr->add);
		printf("gen=%s\n",pr->gen);
		pr=pr->next;
	}
	fclose(im);
	return 0;
}
int export()
{
	struct list *b;
	b=head;
	FILE *wr;
	wr=fopen("newa.txt","w+");
	if(wr==NULL)
	{
		printf("file not open");
	}
	printf("file open\n");
	//fprintf(wr,"name\tage\tmono\tadd\tgen\n");
	while(b!=NULL)
	{
		fprintf(wr,"%s,",b->name1);
		fprintf(wr,"%d,",b->age);
		fprintf(wr,"%s,",&b->mono);
		fprintf(wr,"%s,",b->add);
		fprintf(wr,"%s;\n",b->gen);
		b=b->next;
	}
	fclose(wr);
	return 0;
}
int main()
{
	int y,x;
	while(y!=9)
	{
		y=menu(y);
		if(y==1)
		{
			connect();
		}
		if(y==2)
		{
			update();
		}
		if(y==3)
		{
			print();
		}
		if(y==4)
		{
			addnode();
		}
		if(y==5)
		{
			delet();
		}
		if(y==6)
		{
			count();
		}
		if(y==7)
		{
			import();
		}
		if(y==8)
		{
			export();
		}
	}
	return 0;
}
	
