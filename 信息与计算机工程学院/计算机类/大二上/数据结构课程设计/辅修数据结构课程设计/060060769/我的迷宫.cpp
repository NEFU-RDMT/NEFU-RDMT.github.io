#include<stdio.h> 
#define N1 11 
#define N2 10 

int getpath(int maze[N1][N2])//���Թ���̽·�ĺ��� 
{ 
int stack[N1*N2][2]; 
int i,x=1,y=1,ok,top=0;//��ͨ·���ϵ�һ���㣨��ڵ㣩���������·������stack 
stack[top][0]=x; 
stack[top][1]=y;//ѭ��̽·����1����ǰ����1���˻�һ�� 

while (1) 
{ 
ok=0;//��־�ܷ���ǰ 
if (maze[x][y+1]==0) 
{y=y+1;ok=1;}//���� 
else 
if (maze[x+1][y]==0) 
{x=x+1;ok=1;}//���� 
else 
if (maze[x][y-1]==0) 
{y=y-1;ok=1;}//���� 
else 
if (maze[x-1][y]==0) 
{x=x-1;ok=1;}//���� 

if (!ok)//4�������ͨ 
{ 
top--; 
if (top==0)//ջ�գ��޳�· 
{ 
printf("�Թ��޳�·\n"); 
return 0; 
} 
x=stack[top][0];//���˺�·�������һ�����X�������X 
y=stack[top][1];//���˺�·�������һ�����Y�������Y 
} 
else//������ͨ�� 
{ 
maze[x][y]=2;//���Ѿ��߹��ĵ���Ϊ2 
top++; 
stack[top][0]=x;//�½���ĵ��X�������·������ 
stack[top][1]=y;//�½���ĵ��Y�������·������ 

if (x==N1-2&&y==N2-2)//������� 
{ 
printf("·��Ϊ��\n"); 
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

void printmaze(int maze[N1][N2])//����Թ����麯�� 

{ 
int i,j; 
printf("�Թ�����Ϊ��\n"); 
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
 