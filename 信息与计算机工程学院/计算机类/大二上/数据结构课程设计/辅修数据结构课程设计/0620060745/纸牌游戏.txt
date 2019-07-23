#include <iostream.h>
struct card
{
int num;
int state;
card *next;
};

void playCard()
{
int i;
card*first=new card;
card *p=first,*q;
for(i=1;i<=52;i++)
{
   q=new card; 
   q->num=i;
   q->state=1;//正面向上
   p->next=q;
   p=q;
}
p->next=NULL;

p=first;
for(i=2;i<=52;i++)
{
   p=first;
   for(int a=0;a<i;a++)
   {
    p=p->next;
   }

   while(p!=0)
   {    
    if(a%i==0)
    { 
     p->state=p->state*(-1);//反向
    }
    p=p->next;
    a++;
   }
}

p=first;
cout<<"这时正面向上的牌有:"<<endl;
while(p!=0)
{
   if(p->state==1)
    cout<<p->num<<" ";
   p=p->next;
}
cout<<endl;

}
void main()
{
playCard();
}
