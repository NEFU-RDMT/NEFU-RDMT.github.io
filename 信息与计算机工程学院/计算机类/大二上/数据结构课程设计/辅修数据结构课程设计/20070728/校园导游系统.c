#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define INFINITY  10000           
#define MAX_VERTEX_NUM      20
#define MAX 40
typedef struct ArCell
{
	int adj;    //·������
}ArCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct   //ͼ�ж����ʾ��Ҫ���㣬��ž���ı�š����ơ�������Ϣ��
{
	int num;
    char name[100];
    char pro[500];//���
}info;
typedef struct
{
	info vexs[MAX_VERTEX_NUM];
    AdjMatrix arcs;
    int vexnum,arcnum;
}MGraph;
MGraph b;

MGraph InitGraph(void);
void Menu(void);
void Browser(MGraph *G);
void ShortestPath_DIJ(MGraph * G);
void ShorttestPath_FLOYD(MGraph *G);
void Search(MGraph *G);

void main()
{
	int i;
    b=InitGraph();
    Menu();
    scanf("%d",&i);
    while(i!=5)
	{
		switch(i)
		{
		case 1:
			system("cls");
			Browser(&b);
			Menu();
			break;
		case 2:
			system("cls");
			Search(&b);
			Menu();
			break;
			system("cls");
			ShortestPath_DIJ(&b);
			Menu();
			break;
		case 3:
			system("cls");
			ShorttestPath_FLOYD(&b);
			Menu();
			break;
		case 4:
			system("cls");
			ShortestPath_DIJ(&b);
			Menu();
			break;
		case 5:
			exit(1);
			break;
		default:
			break;
		}
		scanf("%d",&i);
	}
}
MGraph InitGraph()
{
	MGraph G;
    int i,j;
    G.vexnum=10;
    G.arcnum=10;
	for(i=0;i<G.vexnum;i++)
		G.vexs[i].num=i;
	strcpy(G.vexs[0].name,"����¥");
    strcpy(G.vexs[0].pro,"                �칫����\n");
    strcpy(G.vexs[1].name,"ʳ��");
    strcpy(G.vexs[1].pro,"                ��ʳ����\n");
    strcpy(G.vexs[2].name,"����¥");
    strcpy(G.vexs[2].pro,"                ��Ϣ��Ժ�칫�����ڵ�\n");
    strcpy(G.vexs[3].name,"����¥");
    strcpy(G.vexs[3].pro,"                ʵ��¥���������\n");
    strcpy(G.vexs[4].name,"����¥");
    strcpy(G.vexs[4].pro,"                ��ѧ����ѧԺ\n");
    strcpy(G.vexs[5].name,"����ʵϰ����");
    strcpy(G.vexs[5].pro,"                ��ʵϰ\n");
    strcpy(G.vexs[6].name,"����¥");
    strcpy(G.vexs[6].pro,"                ����Ʋ��Ժ\n");
    strcpy(G.vexs[7].name,"������");
    strcpy(G.vexs[7].pro,"                �Ա�������`����`��������\n");
    strcpy(G.vexs[8].name,"һ�Ž�ѧ¥");
    strcpy(G.vexs[8].pro,"                ��Ҫ�Խ��ݽ���Ϊ��\n");
    strcpy(G.vexs[9].name,"���Ž�ѧ¥");
    strcpy(G.vexs[9].pro,"                С����Ϊ��");
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++) 
			G.arcs[i][j].adj=INFINITY;
		G.arcs[0][1].adj=G.arcs[1][0].adj=100;
        G.arcs[1][2].adj=G.arcs[2][1].adj=250;
        G.arcs[2][3].adj=G.arcs[3][2].adj=150;
        G.arcs[3][4].adj=G.arcs[4][3].adj=400;
        G.arcs[4][5].adj=G.arcs[5][4].adj=100;
        G.arcs[5][6].adj=G.arcs[6][5].adj=230;
        G.arcs[6][7].adj=G.arcs[7][6].adj=300;
        G.arcs[7][8].adj=G.arcs[8][9].adj=190;
        G.arcs[8][9].adj=G.arcs[9][8].adj=100;
		return G;
}
void Menu()
{ 
 printf("\n********************************************************************************\n");
 printf("*******************************��ӭ����У԰����ϵͳ*****************************\n");
 printf("                              1.��ʾУ԰ȫ��                                   \n");
 printf("                              2.�鿴������Ϣ                                   \n");
 printf("                              3.ѡ��������Ŀ�ĵ�                             \n");
 printf("                              4.�鿴����·��                                   \n");
 printf("                              5.�˳�ϵͳ                                       \n");
 printf("*******************************************************************************\n");
 printf("��ѡ��");
}
void Browser(MGraph *G)
{
	int i;
    printf("��� ��������                             ���                                         \n");
    for(i=0;i<G->vexnum;i++)
    printf("%-4d%-20s%-20s\n",G->vexs[i].num,G->vexs[i].name,G->vexs[i].pro);
}


void Search(MGraph *G)
{
	int k,flag=1;
    while(flag)
	{
		printf("������Ҫ��ѯ�ľ�����:");
        scanf("%d",&k);
        if(k<0||k>G->vexnum)
		{
			printf("���㲻����!����������:");
            scanf("%d",&k);
		}
		if(k>=0&&k<G->vexnum)
			flag=0;
	}
	printf("��� ��������                             ���                                         \n");
    printf("%-4d%-20s%-20s\n",G->vexs[k].num,G->vexs[k].name,G->vexs[k].pro);
}


void ShortestPath_DIJ(MGraph * G)
{
	int v,w,i,min,t=0,x,flag=1,v0;
    int final[20], D[20], p[20][20];
    while(flag)
	{
		printf("������һ����ʼ������:");
        scanf("%d",&v0);
        if(v0<0||v0>G->vexnum)
		{
			printf("���㲻����!����������:");
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
			if(p[v][w]&&w!=v0) 
				printf("-->%s",G->vexs[w].name);
			t++;
		}
		if(t>G->vexnum-1&&v0!=v)
			printf("\t��·�߳�%dm\n\n",D[v]);
	}

}
void ShorttestPath_FLOYD(MGraph *G)
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
					printf("�����������:\n");
					scanf("%d",&k);
                    printf("������Ŀ�ĵ�:\n");
                    scanf("%d",&j);
					if(k<0||k>G->vexnum||j<0||j>G->vexnum)
					{
						printf("���㲻����!����������:");
						printf("�����������:\n");
					    scanf("%d",&k);
                        printf("������Ŀ�ĵ�:\n");
                        scanf("%d",&j);
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
}




