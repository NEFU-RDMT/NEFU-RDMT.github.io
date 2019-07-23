#include <iostream.h>
#include <cstdlib>
#include <conio.h>
#define M  100
 int exitrow, exitcol;

typedef struct
{
	int x;
    int y;
}fangxiang;
fangxiang move[4]={{1,0},{0,-1},{-1,0},{0,1}};
int mark[6][6]={0};


typedef struct
{
	int row;
    int col;
    int dir;
}node;
typedef struct
{
    node elem[M];          
    int top;
}stack;  
  
void initstack(stack *s)
{
  s->top=-1;
}

void push(stack *s,node e)
{    
	s->top++;
    s->elem[s->top]=e;
  
}

node pop(stack *s,node e)
{
    e=s->elem[s->top];
    s->top--;
    return e;
}


int empty(stack *s)
{
	if(s->top==-1)
       return 0;
    else 
      return 1;
}

void path(int m[6][6])
{ 
	int row ,col,nextrow,nextcol,found=0,dir;
	node postion; 
    stack s;
	mark[1][1]=1;
    initstack(&s);
    postion.row=1;
	postion.col=1;
	postion.dir=0;
    push(&s,postion);
	while(empty(&s)&&!found)
	{   
		postion=pop(&s,postion);
	    row=postion.row;
        col=postion.col;
        dir=postion.dir;
		while(dir<4)
		{      
			nextrow=row+move[dir].x;
            nextcol=col+move[dir].y;
            mark[row][col]=1;
			if(nextrow==exitrow&&nextcol==exitcol)
			{   
				found=1;
                postion.row=row;
                postion.col=col;
                postion.dir=dir;
                push(&s,postion);
                cout<<"found";
	            break;
			}
			else{
				if(!mark[nextrow][nextcol]&&!m[nextrow][nextcol])
				{    
					postion.row=row;
                    postion.col=col;
                    postion.dir=dir;
                    push(&s,postion); 
                    row=nextrow;
                    col=nextcol;
                    dir=0;
				}
				else 
					dir++;
			}
		}
	}
	if(found==1)
	{   
		while(empty(&s))
		{      
			postion=pop(&s,postion);
            cout<<endl<<postion.row<<"   "<<postion.col<<endl;
		}
	}
	else
		cout<<"没有出路"<<endl;
}


int main()
{
	int a[6][6]={  
        {1,1,1,1,1,1}, 
        {1,0,0,0,0,1}, 
        {1,0,1,0,1,1}, 
        {1,0,1,0,0,1}, 
        {1,0,1,0,0,1},
        {1,1,1,1,1,1},};
		cout<<" 1 1 1 1 1 1 "<<endl;  
        cout<<" 1 0 0 0 0 1 "<<endl; 
        cout<<" 1 0 1 0 1 1 "<<endl;  
        cout<<" 1 0 1 0 0 1 "<<endl;
        cout<<" 1 0 1 0 0 1 "<<endl; 
        cout<<" 1 1 1 1 1 1 "<<endl;     
        cout<<"入口为：1  1 "<<endl;
        cout<<"请输入出口：";
        cin>>exitrow>>exitcol;   
        cout<<"路径为:"<<endl;
        path(a);
        cout<<"出口为："<<exitrow<<"  "<<exitcol<<endl; 
      return 0;


}























