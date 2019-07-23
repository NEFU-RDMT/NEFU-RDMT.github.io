#include<stdio.h> 
#define N1 11 
#define N2 10 

int getpath(int maze[N1][N2])//在迷宫中探路的函数 
{ 
int stack[N1*N2][2]; 
int i,x=1,y=1,ok,top=0;//可通路径上第一个点（入口点）的坐标进入路径数组stack 
stack[top][0]=x; 
stack[top][1]=y;//循环探路。加1则向前，减1则退回一步 

while (1) 
{ 
ok=0;//标志能否向前 
if (maze[x][y+1]==0) 
{y=y+1;ok=1;}//向右 
else 
if (maze[x+1][y]==0) 
{x=x+1;ok=1;}//向下 
else 
if (maze[x][y-1]==0) 
{y=y-1;ok=1;}//向左 
else 
if (maze[x-1][y]==0) 
{x=x-1;ok=1;}//向上 

if (!ok)//4方向均不通 
{ 
top--; 
if (top==0)//栈空，无出路 
{ 
printf("迷宫无出路\n"); 
return 0; 
} 
x=stack[top][0];//回退后路径上最后一个点的X坐标存入X 
y=stack[top][1];//回退后路径上最后一个点的Y坐标存入Y 
} 
else//若能走通， 
{ 
maze[x][y]=2;//将已经走过的点标记为2 
top++; 
stack[top][0]=x;//新进入的点的X坐标进入路径数组 
stack[top][1]=y;//新进入的点的Y坐标进入路径数组 

if (x==N1-2&&y==N2-2)//到达出口 
{ 
printf("路径为：\n"); 
for(i=0;i<top;i++) 
{ 
printf("(%d,%d)-->",stack[i][0],stack[i][1]); 
if((i+1)%5==0) 
printf("\n"); 
} 
printf("(%d,%d)\n",stack[top][0],stack[top][1]); 
return 1; 
} 
} 
} 
} 

void printmaze(int maze[N1][N2])//输出迷宫数组函数 

{ 
int i,j; 
printf("迷宫数组为：\n"); 
for (i=0;i<N1;i++) 
{ 
for (j=0;j<N2;j++) 
printf("%2d",maze[i][j]); 
printf("\n"); 
} 
} 

main() 
{ 
int A[N1][N2]= 
{ 
1,1,1,1,1,1,1,1,1,1, 
1,0,0,1,0,0,0,1,0,1, 
1,0,0,1,0,0,0,1,0,1, 
1,0,0,0,0,1,1,0,1,1, 
1,0,1,1,1,0,0,1,0,1, 
1,0,0,0,1,0,0,0,0,1, 
1,0,1,0,0,0,1,0,1,1, 
1,0,1,1,1,1,0,0,1,1, 
1,1,1,0,0,0,1,0,1,1, 
1,1,1,0,0,0,0,0,0,1, 
1,1,1,1,1,1,1,1,1,1}; 

printmaze(A); 
getpath(A); 
} 
 