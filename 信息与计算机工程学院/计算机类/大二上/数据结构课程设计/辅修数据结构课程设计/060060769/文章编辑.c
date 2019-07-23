#include<iostream.h> 
#include<stdio.h> 
#include<ctype.h> 
#include<stdlib.h>
#include<string.h>

#define N 10
 typedef struct node
{ int k,m,n,l;
  char aa[80];
  struct node* next;
}LNode,*LinkedList;

 LinkedList Init()
{  LinkedList L;
  L=(LNode*)malloc(sizeof(LNode));
  if(L==NULL)
	{
	  printf("Input the story:\n");
	}
	L->next=NULL;
	return L;
}
 void print(LinkedList L);
void input(LNode *L)
{
  char aa[80];
 LinkedList  p,q;
 q=L;
 while(1)
 { fflush(stdin);
   gets(aa);
   if(strcmp(aa,"eof")==0)
	 break;

   p = (LNode*)malloc(sizeof(LNode));
   strcpy(p->aa,aa);
   p->next = NULL;
   q->next = p;
   q = q->next;
 }
	  // print(L);

}
int LinkedListlength(LinkedList L,int *k,int *m,int *n)
{  LinkedList  p = L->next;
  int o=0;int i=0;int l=0;
  *k = 0; *m = 0; *n = 0;
  
   for(;p;p=p->next)
   { 
	  for(i=0;i<80&&p->aa[i]!=0;i++)
      {
	  if(p->aa[i]>='a'&&p->aa[i]<='z' || p->aa[i]>='A'&&p->aa[i]<='Z') (*k)++;
	  else if(p->aa[i]>='0'&&p->aa[i]<='9') (*m)++;

	  else if(p->aa[i]==32) (*n)++;
	  l++;
	  }
   
   }
	  printf("the string's num is %d\n",*k);
	  printf("the num's num is %d\n",*m);
	  printf("the blank's num is %d\n",*n);
	  printf("the total num is %d\n",l);
     p = L->next;
	while(p!=NULL)
   {
	 o++;p=p->next;
   }  return o;   }


void print(LinkedList L)
{LinkedList p;int i;
  p=L->next;
  for(;p;p=p->next)
   { for(i=0;i<80&&p->aa[i]!=0;i++)
  printf("%c",p->aa[i]);
   printf("\n");
 
  }
}



int charnumber(LinkedList L,int k)
{int i;
 char s;
 LinkedList p;

 p=L->next;
 k=0;
   printf("please input the char:\n");
  fflush(stdin);
	scanf("%c",&s);    //fflush(stdin);
   for(;p;p=p->next)
   { for(i=0;i<80&&p->aa[i]!=0;i++)
     {
	 if(p->aa[i]==s) k++;
     }
	  
	 }
     return k;}



	  /* for(p=L,q=s;*q!='\0'&&p->next;p=p->next,q++)

		  {
		   if(p->aa!=*q) break;
		   if(*q=='\0') n++;}
			L=L->next;}  */
  
   





 void main()
{ LNode *L;int k=0,m=0,n=0,l; int t,h,result;
   h=0;
  L= Init();
  input(L);
	 //  print(L);


while(1)
{	  printf("1.coculate the story:\n");
	  printf("2.rewrite the story:\n");
	  printf("3.coculate the string:\n");
	  printf("4.Exit:\n");
   scanf("%d",&t);
   switch(t)
   {case 1:
       l=LinkedListlength(L,&k,&m,&n) ;
	   printf("length = %d,%d,%d,%d\n",k,m,n,l);
	  // print(L);
	   break;
	case 2:
       print(L); 
    break;
	case 3:
	  {result=charnumber(L,h);printf("%d\n",result);}
    break;
    case 4:
	 return;
   }
}

}



