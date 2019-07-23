
#define INFINITY 10000 /*无穷大*/ 
#define MAX_VERTEX_NUM 40 
#define MAX 40 
#include<stdlib.h> 
#include<stdio.h> 
#include<conio.h> 
#include<string.h> 
typedef struct ArCell 
{ 
int adj; //路径长度 
}ArCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; 
typedef struct //图中顶点表示主要景点，存放景点的编号、名称、简介等信息， 
{ 
char name[30]; 
int num; 
char introduction[100];//简介 
}infotype; 
typedef struct 
{ 
infotype vexs[MAX_VERTEX_NUM]; 
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
/******************************************************/ 
void main(void) 
{ 

system("mode con: cols=140 lines=130"); 
cmd(); 
} 
/******************************************************/ 

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
MGraph InitGraph(void) 
{ 
MGraph G; 
int i,j; 
G.vexnum=10; 
G.arcnum=14; 
for(i=0;i<G.vexnum;i++) 
G.vexs[i].num=i; 
strcpy(G.vexs[0].name,"美食城"); 
strcpy(G.vexs[0].introduction,"标准化食堂"); 
strcpy(G.vexs[1].name,"学校主楼"); 
strcpy(G.vexs[1].introduction,"年时已久，较破旧"); 
strcpy(G.vexs[2].name,"5号学生宿舍楼"); 
strcpy(G.vexs[2].introduction,"校园内楼层最高，环境最好的寝室楼"); 
strcpy(G.vexs[3].name,"校医院"); 
strcpy(G.vexs[3].introduction,"校医院,设施不是很齐全，只能看小病，收费较便宜"); 
strcpy(G.vexs[4].name,"图书馆"); 
strcpy(G.vexs[4].introduction,"设施良好，有电子阅览室等，环境幽雅"); 
strcpy(G.vexs[5].name,"体育场"); 
strcpy(G.vexs[5].introduction,"现代化塑胶跑道,人造草坪,适宜锻炼身体的场所"); 
strcpy(G.vexs[6].name,"林场"); 
strcpy(G.vexs[6].introduction,"绿树成荫,适宜休息和散步"); 
strcpy(G.vexs[7].name,"第二教学楼"); 
strcpy(G.vexs[7].introduction,"学院最大的教学楼,共9层，教室较多,因为紧靠马路，噪音较大，环境较差"); 
strcpy(G.vexs[8].name,"第一教学楼"); 
strcpy(G.vexs[8].introduction,"学院第二大教学楼,环境较差"); 
strcpy(G.vexs[9].name,"行政楼"); 
strcpy(G.vexs[9].introduction,"校行政单位办公场所，设施齐全"); 
for(i=0;i<G.vexnum;i++) 
for(j=0;j<G.vexnum;j++) 
G.arcs[i][j].adj=INFINITY; 
G.arcs[0][1].adj=100; 
G.arcs[0][2].adj=200; 
G.arcs[0][6].adj=400; 
G.arcs[1][7].adj=300; 
G.arcs[2][3].adj=120; 
G.arcs[3][6].adj=220; 
G.arcs[3][4].adj=100; 
G.arcs[4][5].adj=300; 
G.arcs[4][9].adj=250; 
G.arcs[5][9].adj=350; 
G.arcs[6][7].adj=60; 
G.arcs[6][9].adj=200; 
G.arcs[7][8].adj=50; 
G.arcs[8][9].adj=20; 
for(i=0;i<G.vexnum;i++) 
for(j=0;j<G.vexnum;j++) 
G.arcs[j][i].adj=G.arcs[i][j].adj; 
return G; 
}//InitGraph end 
void Menu() 
{ 
printf("\n 东北林业大学导游图\n"); 
printf(" ┏━━━━━━━━━━━━━━━━━━━━┓\n"); 
printf(" ┃ 1.浏览校园全景 ┃\n"); 
printf(" ┃ 2.查看所有游览路线 ┃\n"); 
printf(" ┃ 3.选择出发点和目的地 ┃\n"); 
printf(" ┃ 4.查看景点信息 ┃\n"); 
printf(" ┃ 5.退出系统 ┃\n"); 
printf(" ┗━━━━━━━━━━━━━━━━━━━━┛\n"); 
printf("Option-:"); 
} 
void Browser(MGraph *G) 
{ 
int v; 
printf("┏━━┳━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"); 
printf("┃编号┃景点名称 ┃简介 ┃\n"); 
for(v=0;v<G->vexnum;v++) 
printf("┃%-4d┃%-16s┃%-56s┃\n",G->vexs[v].num,G->vexs[v].name,G->vexs[v].introduction); 
printf("┗━━┻━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"); 
} 

// 迪杰斯特拉算法来计算出起点到各个顶点之间的最短路径,v0为起点 
void ShortestPath_DIJ(MGraph * G) 
{ 
int v,w,i,min,t=0,x,flag=1,v0; 
int final[20], D[20], p[20][20]; 
while(flag) 
{ 
printf("请输入一个起始景点编号:"); 
scanf("%d",&v0); 
if(v0<0||v0>G->vexnum) 
{ 
printf("景点编号不存在!请重新输入景点编号:"); 
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
p[v][w]=0; 
if(D[v]<INFINITY) 
{ 
p[v][v0]=1;p[v][v]=1; 
} 
} 
D[v0]=0;final[v0]=1; 
for(i=1;i<G->vexnum;i++) 
{ 
min=INFINITY; 
for(w=0;w<G->vexnum;w++) 
if(!final[w]) 
if(D[w]<min){v=w;min=D[w];} 
final[v]=1; 
for(w=0;w<G->vexnum;w++) 
if(!final[w]&&(min+G->arcs[v][w].adj<D[w])) 
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
if(t>G->vexnum-1&&v0!=v)printf(" 总路线长%dm\n\n",D[v]); 
} 

}//ShortestPath_DIJ end 
void Floyd(MGraph *G) 
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
printf("请输入出发点和目的地的编号:"); 
scanf("%d%d",&k,&j); 
if(k<0||k>G->vexnum||j<0||j>G->vexnum) 
{ 
printf("景点编号不存在!请重新输入出发点和目的地的编号:"); 
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
printf(" 总路线长%dm\n",D[k][j]); 
}//Floyd end 
void Search(MGraph *G) 
{ 
int k,flag=1; 
while(flag) 
{ 
printf("请输入要查询的景点编号:"); 
scanf("%d",&k); 
if(k<0||k>G->vexnum) 
{ 
printf("景点编号不存在!请重新输入景点编号:"); 
scanf("%d",&k); 
} 
if(k>=0&&k<G->vexnum) 
flag=0; 
} 
printf("┏━━┳━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"); 
printf("┃编号┃景点名称 ┃简介 ┃\n"); 
printf("┃%-4d┃%-16s┃%-56s┃\n",G->vexs[k].num,G->vexs[k].name,G->vexs[k].introduction); 
printf("┗━━┻━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"); 

}//Search end 

int LocateVex(MGraph *G,char* v) 
{ 
int c=-1,i; 
for(i=0;i<G->vexnum;i++) 
if(strcmp(v,G->vexs[i].name)==0) 
{c=i;break;} 
return c; 
} 
MGraph * CreatUDN(MGraph *G)//初始化图形，接受用户输入 
{ 
int i,j,k,w; 
char v1[20],v2[20]; 
printf("请输入图的顶点数,弧数:"); 
scanf("%d%d",&G->vexnum,&G->arcnum); 
printf("请输入景点的编号:、名称、简介:\n"); 
for(i=0;i<G->vexnum;i++) 
{ 
printf("景点编号:"); 
scanf("%d",&G->vexs->num); 
printf("景点名称:"); 
scanf("%s",G->vexs[i].name); 
printf("景点简介:"); 
scanf("%s",G->vexs->introduction); 
} 
for(i=0;i<G->vexnum;i++) 
for(j=0;j<G->vexnum;j++) 
G->arcs[i][j].adj=INFINITY; 
printf("请输入路径长度:\n"); 
for(k=0;k<G->arcnum;k++) 
{ 
printf("第%d条边:\n",k+1); 
printf("景点对(x,y):"); 
scanf("%s",v1); 
scanf("%s",v2); 
printf("路径长度:"); 
scanf("%d",&w); 
i=LocateVex(G,v1); 
j=LocateVex(G,v2); 
if(i>=0&&j>=0) 
{ 
G->arcs[i][j].adj=w; 
G->arcs[j][i]=G->arcs[i][j]; 
} 
} 
return G; 
} 



void print(MGraph *G) 
{ 
int v,w,t=0; 
for(v=0;v<G->vexnum;v++) 
for(w=0;w<G->vexnum;w++) 
{ if(G->arcs[v][w].adj==INFINITY) 
printf("∞ "); 
else printf("%-7d",G->arcs[v][w].adj); 
t++; 
if(t%G->vexnum==0) 
printf("\n"); 
} 
}