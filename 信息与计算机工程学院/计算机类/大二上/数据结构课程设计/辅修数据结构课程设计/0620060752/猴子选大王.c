#include <stdio.h> 
#include <stdlib.h>
typedef struct monkey 
{ 
	int num; 
	struct monkey *next; 
} Monkey,*LINK; 
void main() 
{ 
	LINK p,head,p2; 
	int i,n,m;
	printf("请输入猴子数目：\n");
	scanf("%d",&n);
	printf("请输入淘汰第几个猴子：\n");
	scanf("%d",&m);
	head=p=p2=(LINK)malloc(sizeof(Monkey)); 
	for(i=1;i<n;i++) 
	{ 
		p=(LINK)malloc(sizeof(Monkey)); 
		p2->next=p; 
		p2=p; 
	} 
	p2->next=head; 
	p=head; 
	for(i=1;i<=n;i++) 
	{ 
		p->num=i; 
		//printf("%d号猴子：%d\n",p->num,p->num); 
		p=p->next; 
	} 
	i=0; 
	p=head; 
	while(1) 
	{ 
		i++; 
		//printf("%d号猴子报：%d\n",p->num,i);
		if(p->next==p) break; 

		if(i==m) 
		{ 
			i=0; 
			//printf("%d号猴被淘汰\n",p->num); 
			printf("\n"); 
			p2->next=p->next; 
			p=p2->next; 
			continue; 
		} 
		else 
		{ 
			if(i==m-1) p2=p; 
			p=p->next; 
		} 
	}
	printf("猴子大王是:%d\n",p->num); 
}
