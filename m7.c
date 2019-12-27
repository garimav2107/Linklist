#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct pr{
	char name[10];
	char gender[10];
	int age;
	long int number;
	int data;
	struct pr *sy;
	struct pr  *ve;
};
struct pr *head;
int freepr(struct pr *head);
int connect()
{
	int i,n;
        struct pr *old,*ptr;
        printf("enter the nodes");
	scanf("%d",&n);
	head=(struct pr*)malloc(sizeof(struct pr));
	old=head;
	head->ve=(struct pr*)malloc(sizeof(struct pr));
	ptr=head->ve;
	for(i=0;i<n;i++)
	{
         ptr->sy=old;
        ptr->ve=(struct pr*)malloc(sizeof(struct pr));
        old=ptr;
        ptr=ptr->ve;
	printf("%p\t",old);
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
struct pr *pt;
pt=head;
while(pt!=NULL)
{
printf("enter the name");
scanf("%s",&pt->name[0]);
printf("enter the gender");
scanf("%s",&pt->gender[0]);
printf("enter the age");
scanf("%d",&pt->age);
printf("enter the number");
scanf("%ld",&pt->number);
printf("\n");
pt=pt->ve;
}
return 0;	
}
int print()
{
	struct pr *w;
	w=head;
	while(w!=NULL)
	{
         printf("name  %s" ,&w->name[0]);
	 printf("  gender %s",&w->gender[0]);
	 printf("  age %d",w->age);
	 printf("  number %ld",w->number);
         printf("\n");
	 w=w->ve;
	}
	return 0;
}
int add()
{
int i=1,pos;
struct pr *a,*s,*d;
printf("enter the position you want  to add");
scanf("%d",&pos);
s=head;
while(i<pos)
{
	s=s->ve;
	i++;
}
a=(struct pr*)malloc(sizeof(struct pr));
printf("enter the name");
scanf("%s",&a->name[0]);
printf("enter the gender");
scanf("%s",&a->gender[0]);
printf("enter the age");
scanf("%d",&a->age);
printf("enter the number");
scanf("%ld",&a->number);
if(s->ve==NULL)
{
	a->ve=NULL;
	s->ve=a;
	a->sy=s;

}
else
{
d=s->ve;
s->ve=a;
a->sy=s;
a->ve=d;
d->sy=a;
}

return 0;
}
int rem()
{
int i=0,posi;
struct pr *w,*q,*t;
printf("enter the position you want to delete");
scanf("%d",&posi);
w=head;
while(i<posi)
{
	w=w->ve;
	i++;
}
q=w->ve;
t=w->sy;
q->sy=t;
t->ve=q;
return 0;
}
int menu()
{
	int choice;
	printf("1. conectlist\n 2.update\n 3.print\n 4.add\n 5.remove\n 6.count\n 7.export\n 8.import\n  9.exit\n");
	printf("enter the choice");
	scanf("%d",&choice);
	return choice;
}
int cou()
{
	int count=0;
struct pr *hon;	
hon=head;
while(hon!=NULL)
{
	count++;
	hon=hon->ve;
}
printf("the count %d\n",count);
return 0;	
}
int export()
{
struct pr *lp;
lp=head;
FILE *ln;
ln=fopen("nnn.txt","w+");
if(ln==NULL)
{
    printf("file is not opend");
    exit(0);
}
printf("file is  open");
while(lp!=NULL)
{
fprintf(ln,"%s,",&lp->name[0]);
fprintf(ln,"%s,",&lp->gender[0]);
fprintf(ln,"%d,",lp->age);
fprintf(ln,"%ld;\n",lp->number);
lp=lp->ve;
}
fclose(ln);
}
int import()
{
	struct pr *nptr,*name,*temp;
	int size,i=0,m=0,k=0,*pt,j;
	char a[200];
	char *p,*ap;
	ap=&a[0];
	pt=&k;
	name=head;
	temp=head;
	while (name->ve!=NULL)
{
	name=name->ve;
}
FILE *iptr;
iptr=fopen("nnn.txt","r+");
if(iptr==NULL)
{
	printf("file creation failure\n");
}
else
{
	printf("file creation sucess\n");
}
while((a[i]=fgetc(iptr))!=EOF)
{
	if(a[i]==';')
	{
		m++;
	}
	i++;
}

//a[0---all]
printf("%s",&a[0]);
printf(" address in name %p\n",name);
for(i=0;i<m;i++)
{
	if(name->ve==NULL)
	{
		nptr=(struct pr*)malloc(sizeof(struct pr));
		nptr->ve=NULL;
		nptr->sy=name;
		name->ve=nptr;
	}
	p=strchr(ap,',');
	size=p-ap;
	memcpy(nptr->name,ap,size);
	p++;
	ap=p;
	p=strchr(ap,',');
	size=p-ap;
	 printf("size %d\n",size);
	 ap=ap++;
	memcpy(nptr->gender,ap,size);
	p++;
	ap=p;
	  p=strchr(ap,',');
        size=p-ap;
        printf("size %d\n",size);
          k=0;
        for(j=0;j<size;j++)
        {
                k=(k*10) + ((*ap)-'0');
                printf(" k %d\n",k);
                ap++;
        }
        ap=ap-size;

        memcpy(&nptr->age,pt,size);
        p++;
        ap=p;
  p=strchr(ap,';');
        size=p-ap;
        printf("size %d\n",size);
        k=0;
        for(j=0;j<size;j++)
        {
                k=(k*10) + ((*ap)-'0');
                printf(" k %d\n",k);
                ap++;
        }
        ap=ap-size;
        memcpy(&nptr->number,pt,size);
        p++;
        ap=p;
	name=nptr;
}
printf("address in temp %p\n",temp);
while(temp!=NULL)
{
	printf("name %s\n",temp->name);
	printf("gender %s\n",temp->gender);
	printf("age  %d\n",temp->age);
	printf("number %ld\n",temp->number);
	temp=temp->ve;
}
	fclose(iptr);
	return 0;
}

int main()
{
	int choice=0,a,b,c,d,e,f,g,x,z;
	while(choice!=9)
	{
		choice=menu();
		if(choice==1)
		{
			printf("connect\n");
			a=connect();
		}
		else if (choice==2)
		{
                          printf("update\n");
			  b=update();
		}
		else if(choice==3)
		{
			printf("print\n");
			c=print();
		}
		else if(choice==4)
		{
			printf("add\n");
			d=add();
		}
		else if(choice==5)
		{
			printf("remove\n");
			e=rem();
		}
		else if(choice==6)
		{
			printf("count\n");
			f=cou();
		}
		else if(choice==7)
		{
			printf("export\n");
                           x=export();
		}
		else if(choice==8)
		{
			printf("import\n");
			z=import();
		}
		else
		{
			g=freepr(head);
			printf("exit\n");
		}
	}
		return 0;
}

          int freepr(struct pr *head)
{
        struct pr *pt,*temp;
        pt=head;
        while(pt!=NULL)
        {
                temp=pt->ve;
                free(pt);
                pt=temp;
        }
}
                  
