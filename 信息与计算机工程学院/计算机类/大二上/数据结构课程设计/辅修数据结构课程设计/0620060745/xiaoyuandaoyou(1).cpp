#define INFINITY 10000 
#define MAX_VERTEX_NUM 40 
#define MAX 40 
#include<stdlib.h> 
#include<stdio.h> 
#include<conio.h> 
#include<string.h> 
typedef struct ArCell 
{ 
int adj; //·������ 
}ArCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; 
typedef struct //ͼ�ж����ʾ��Ҫ���㣬��ž���ı�š����ơ�������Ϣ�� 
{ 
char name[30]; 
int num; 
char introduction[100];//�����Ϣ 
}informationtype; 
typedef struct 
{ 
informationtype vexs[MAX_VERTEX_NUM]; 
AdjMatrix arcs; 
int vexnum,arcnum; 
}MGraph; 
MGraph b; 

void cmd(void); 
MGraph InitGraph(void); 
void Menu(void); 
void Browser(MGraph *G); 
void ShortestPath_DIJ(MGraph * G); 
void Floyd(MGraph *G); 
void Search(MGraph *G); 
int LocateVex(MGraph *G,char* v); 
MGraph * CreatUDN(MGraph *G); 
void print(MGraph *G); 


void cmd(void) 
{ 
int i; 
b=InitGraph(); 
Menu(); 
scanf("%d",&i); 
while(i!=5) 
{ 
switch(i) 
{ 
case 1:system("cls");Browser(&b);Menu();break; 
case 2:system("cls");ShortestPath_DIJ(&b);Menu();break; 
case 3:system("cls");Floyd(&b);Menu();break; 
case 4:system("cls");Search(&b);Menu();break; 
case 5:exit(1);break; 
default:break; 
} 

scanf("%d",&i); 
} 
}

 
MGraph InitGraph(void) //��ʼ��
{ 
MGraph G; 
int i,j; 
G.vexnum=10; 
G.arcnum=14; 
for(i=0;i<G.vexnum;i++) 
G.vexs[i].num=i; 
strcpy(G.vexs[0].name,"��ʳ����"); 
strcpy(G.vexs[0].introduction,"������ʳ�ǣ������������ġ�\n�㼯���ַ�ζ�����������ţ�"); 
strcpy(G.vexs[1].name,"�ۺϰ칫¥"); 
strcpy(G.vexs[1].introduction,"Ҳ������¥��������ʩ��ȫ"); 
strcpy(G.vexs[2].name,"ѧ����Ԣ"); 
strcpy(G.vexs[2].introduction,"����ѧ����Ԣ��14��"); 
strcpy(G.vexs[3].name,"ҽԺ"); 
strcpy(G.vexs[3].introduction,"УҽԺ,�豸һ�㣬�ɹ�ѧУѧ��һ�㲡��Ĳ鿴���շѽϵ�"); 
strcpy(G.vexs[4].name,"ͼ���"); 
strcpy(G.vexs[4].introduction,"������ʮ���,��ʩ���ã���¥�������ѧ����ϰ�ң�5¥Ϊ���������ң���������"); 
strcpy(G.vexs[5].name,"������"); 
strcpy(G.vexs[5].introduction,"�ִ����ܽ��ܵ�,�����ƺ,���˶�������ĳ���");
strcpy(G.vexs[6].name,"��¥"); 
strcpy(G.vexs[6].introduction,"λ��ѧУ���Ÿ�����ѧУ����Ľ���֮һ�������ƾõ���ʷ���Ļ�");  
strcpy(G.vexs[7].name,"��һ��ѧ¥"); 
strcpy(G.vexs[7].introduction,"¥�߰˲�,��¥Ϊ����ѧԺ����¥���϶�Ϊ������"); 
strcpy(G.vexs[8].name,"�ڶ���ѧ¥"); 
strcpy(G.vexs[8].introduction,"ѧУ���Ľ�ѧ¥,��10�㣬�е���,��ѧ���Ͽ���ϰ"); 
strcpy(G.vexs[9].name,"�ֳ�"); 
strcpy(G.vexs[9].introduction,"�����������������£���������Ʒ�ַ��࣬����ɢ��������"); 
for(i=0;i<G.vexnum;i++) 
for(j=0;j<G.vexnum;j++) 
G.arcs[i][j].adj=INFINITY; 
G.arcs[0][1].adj=500; 
G.arcs[0][2].adj=100; 
G.arcs[0][6].adj=300; 
G.arcs[1][7].adj=300; 
G.arcs[2][3].adj=120; 
G.arcs[3][6].adj=220; 
G.arcs[3][4].adj=100; 
G.arcs[4][5].adj=300; 
G.arcs[4][9].adj=250; 
G.arcs[5][9].adj=350; 
G.arcs[6][7].adj=90; 
G.arcs[6][9].adj=200; 
G.arcs[7][8].adj=150; 
G.arcs[8][9].adj=200; 
for(i=0;i<G.vexnum;i++) 
for(j=0;j<G.vexnum;j++) 
G.arcs[j][i].adj=G.arcs[i][j].adj; 
return G; 
}//��ʼ������

 
void Menu() //�˵�
{printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
 printf("\n                                                                              \n");
 printf("\n                       ������ҵ��ѧУ԰����ͼ                                 \n");
 printf("\n                           (������Ϣ��ѯ)                                     \n");
 printf("\n                                                                              \n");
 printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
 printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~1.�ۿ�У԰��ȫò~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
 printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~2.�鿴��������·��~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
 printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~3.ѡ��������Ŀ�ĵ�~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
 printf(" ~~~~~~~~~~~~~~~~~~~~~~~~4.�鿴���������Ϣ����~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
 printf(" ~~~~~~~~~~~~~~~~~~~~~~~5.�����ϣ����˳���ϵͳ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
 printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
 printf("Option-:"); 
}

 
void Browser(MGraph *G)//��� 
{ 
int v; 
printf("��������������������������������������������������������������������������������\n"); 
printf(" ���     ��������            ���                                                          \n"); 
for(v=0;v<G->vexnum;v++) 
printf("%-4d       %-16s     %-56s\n",G->vexs[v].num,G->vexs[v].name,G->vexs[v].introduction); 
printf("��������������������������������������������������������������������������������\n"); 
} 

 
void ShortestPath_DIJ(MGraph * G) // �������㵽��������֮������·��,v0Ϊ���
{ 
int v,w,i,min,t=0,x,flag=1,v0; 
int final[20], D[20], p[20][20]; 
while(flag) 
{ 
printf("������һ����ʼ������:"); 
scanf("%d",&v0); 
if(v0<0||v0>G->vexnum) 
{ 
printf("�����Ų�����!���������뾰����:"); 
scanf("%d",&v0); 
} 
if(v0>=0&&v0<G->vexnum) 
flag=0; 
} 
for(v=0;v<G->vexnum;v++) 
{ 
final[v]=0; 
D[v]=G->arcs[v0][v].adj; 

for(w=0;w<G->vexnum;w++) 
p[v][w]=0; //��0��ʾ�٣���·��Ϊ��
if(D[v]<INFINITY)//INFINITY��ʾ�������������ֵ 
{ 
p[v][v0]=1;p[v][v]=1; 
} 
} 
D[v0]=0;final[v0]=1; //��ʼ����V0����������������·���Ķ��㼯S
for(i=1;i<G->vexnum;i++) 
{ 
min=INFINITY; //��ǰ��֪��V0������������
for(w=0;w<G->vexnum;w++) 
if(!final[w]) 
if(D[w]<min){v=w;min=D[w];} //w��v0����
final[v]=1; //��v0�����V�ӵ�S��
for(w=0;w<G->vexnum;w++) //���µ�ǰ���·��������
if(!final[w]&&(min+G->arcs[v][w].adj<D[w])) //�޸�D[w]��p[w]��w����V-S
{ 
D[w]=min+G->arcs[v][w].adj; 
for(x=0;x<G->vexnum;x++) 
p[w][x]=p[v][x]; 
p[w][w]=1; 
} 
} 
for(v=0;v<G->vexnum;v++) 
{ 
if(v0!=v) printf("%s",G->vexs[v0].name); 
for(w=0;w<G->vexnum;w++) 
{ 
if(p[v][w]&&w!=v0) printf("-->%s",G->vexs[w].name); 
t++; 
} 
if(t>G->vexnum-1&&v0!=v)printf(" ��·�߳�%dm\n\n",D[v]); 
} 

}//ShortestPath_DIJ end

 
void Floyd(MGraph *G) //�����㵽Ŀ�ĵ�·��
{ 
int v,u,i,w,k,j,flag=1,p[10][10][10],D[10][10]; 
for(v=0;v<G->vexnum;v++) 
for(w=0;w<G->vexnum;w++) 
{ 
D[v][w]=G->arcs[v][w].adj; 
for(u=0;u<G->vexnum;u++) 
p[v][w][u]=0; 
if(D[v][w]<INFINITY) 
{ 
p[v][w][v]=1;p[v][w][w]=1; 
} 
} 
for(u=0;u<G->vexnum;u++) 
for(v=0;v<G->vexnum;v++) 
for(w=0;w<G->vexnum;w++) 
if(D[v][u]+D[u][w]<D[v][w]) 
{ 
D[v][w]=D[v][u]+D[u][w]; 
for(i=0;i<G->vexnum;i++) 
p[v][w][i]=p[v][u][i]||p[u][w][i]; 
} 

while(flag) 
{ 
printf("�����������ı��:"); 
scanf("%d",&k); 
printf("������Ŀ�ĵصı��:"); 
scanf("%d",&j); 
if(k<0||k>G->vexnum||j<0||j>G->vexnum) 
{ 
printf("�����Ų�����!����������������Ŀ�ĵصı��:"); 
scanf("%d%d",&k,&j); 
} 
if(k>=0&&k<G->vexnum&&j>=0&&j<G->vexnum) 
flag=0; 
} 
printf("%s",G->vexs[k].name); 
for(u=0;u<G->vexnum;u++) 
if(p[k][j][u]&&k!=u&&j!=u) 
printf("-->%s",G->vexs[u].name); 
printf("-->%s",G->vexs[j].name); 
printf(" ��·�߳�%dm\n",D[k][j]); 
}//Floyd end

 
void Search(MGraph *G) //��ѯ
{ 
int k,flag=1; 
while(flag) 
{ 
printf("������Ҫ��ѯ�ľ�����:"); 
scanf("%d",&k); 
if(k<0||k>G->vexnum) 
{ 
printf("�����Ų�����!���������뾰����:"); 
scanf("%d",&k); 
} 
if(k>=0&&k<G->vexnum) 
flag=0; 
} 
printf("\n"); 
printf("��� ��������  ���  \n"); 
printf("%-4d %-16s %-56s \n",G->vexs[k].num,G->vexs[k].name,G->vexs[k].introduction); 
printf("\n"); 

}//Search end
 

int LocateVex(MGraph *G,char* v) 
{ 
int c=-1,i; 
for(i=0;i<G->vexnum;i++) 
if(strcmp(v,G->vexs[i].name)==0) 
{c=i;break;} 
return c; 
} 
void print(MGraph *G) 
{ 
int v,w,t=0; 
for(v=0;v<G->vexnum;v++) 
for(w=0;w<G->vexnum;w++) 
{ if(G->arcs[v][w].adj==INFINITY) 
printf("�� "); 
else printf("%-7d",G->arcs[v][w].adj); 
t++; 
if(t%G->vexnum==0) 
printf("\n"); 
} 
}
 
void main(void)
{
 cmd(); 
} 
