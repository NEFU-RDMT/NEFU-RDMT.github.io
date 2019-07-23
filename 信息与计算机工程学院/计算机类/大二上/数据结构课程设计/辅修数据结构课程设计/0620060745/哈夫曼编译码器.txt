#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define MAXVALUE 10000
typedef struct
{
int weight;
int flag;
int parent;
char ch;
int lchild;
int rchild;
}HafNode;
typedef struct
{
int bit[MAX];
int start;
int weight;
char ch;
}Code;
typedef struct
{
char bit[MAX];
char ch;
int weight;
}Coding;
void CreatHaffman(int weight[],char ch[],int n,HafNode haffTree[]) 
{//哈夫曼树生成函数,n为初始森林中的结点数
int i,j,m1,m2,x1,x2;
for (i=0;i<2*n-1;i++)
{
if(i<n)
{
haffTree[i].weight=weight[i];
haffTree[i].ch=ch[i];
}
else
haffTree[i].weight=0;
haffTree[i].parent=-1;
haffTree[i].flag=0;
haffTree[i].lchild=-1;
haffTree[i].rchild=-1;
}
for (i=0;i<n-1;i++)
{
m1=m2=MAXVALUE;
x1=x2=0;
for (j=0;j<n+i;j++)
{
if (haffTree[j].weight<m1&&haffTree[j].flag==0)
{
m2=m1;
x2=x1;
m1=haffTree[j].weight;
x1=j; 
}
else if(haffTree[j].weight<m2 && haffTree[j].flag==0)
{
m2=haffTree[j].weight;
x2=j;
}
}
haffTree[x1].parent= n + i;
haffTree[x2].parent = n + i;
haffTree[x1].flag = 1;
haffTree[x2].flag = 1;
haffTree[n+i].weight = haffTree[x1].weight + haffTree[x2].weight;
haffTree[n+i].lchild = x1;
haffTree[n+i].rchild = x2;
}
FILE *fp;
fp=fopen("huffman.txt","w+");
printf("%d\n",n);
fprintf(fp,"%d\n",n);
for (i=0;i<n;i++) 
fprintf(fp,"%c %d %d %d\n",haffTree[i].ch,haffTree[i].parent,haffTree[i].lchild,haffTree[i].rchild);
for (i=n;i<2*n-1;i++)
fprintf(fp,"%d %d %d\n",haffTree[i].parent,haffTree[i].lchild,haffTree[i].rchild); 
fclose(fp);
}
void HaffmanCode (HafNode haffTree[],int n,Code haffCode[])/*生成哈夫曼编码的函数*/
{
Code *cd=( Code *) malloc (sizeof (Code));
int i,j,child,parent; 
for (i=0; i<n; i++)
{
cd->start=n-1;/*编码起始位置的初值*/
cd->weight=haffTree[i].weight;
cd->ch=haffTree[i].ch;
child=i;
parent=haffTree[child].parent;
while (parent !=-1)
{
if (haffTree[parent].lchild==child)
cd->bit[cd->start]=0;
else
cd->bit[cd->start]=1;
cd->start--;
child =parent;
parent=haffTree[child].parent;
}

for (j=cd->start+1; j<n; j++)
haffCode[i].bit[j]=cd->bit[j];
haffCode [i].start = cd->start+1;
haffCode [i].weight=cd->weight;
haffCode [i].ch=cd->ch;
}
}
void Init(int weight[],char ch[]) //初始化操作，生成哈夫曼树及哈夫曼编码

{
FILE *fp;
int i,j,n;
char ch1,wj[15];
printf("现在进行初始化操作。。。\n请选择:\nA.键盘输入 B.文件输入\n");
scanf("%c",&ch1);
if (ch1=='A')
{
printf("请输入字符集大小n:\n");
scanf("%d",&n);
}
if (ch1=='B')
{
printf("请输入文件名:\n");
scanf("%s",wj);
fp=fopen(wj,"r"); 
fscanf(fp,"%d",&n);
} 
HafNode *myHaffTree=(HafNode *)malloc(sizeof (HafNode)*(2*n+1));
Code *myHaffCode =(Code *)malloc (sizeof (Code)*n);
for (i=0;i<n;i++)
{
if (ch1=='A')
{
printf("请输入字符和权值:\n");
scanf("%s %d",&ch[i],&weight[i]);
}
if (ch1=='B')
fscanf(fp,"%s %d",&ch[i],&weight[i]);
}
if (ch1=='B')
fclose(fp);
CreatHaffman(weight,ch,n,myHaffTree);
HaffmanCode(myHaffTree,n,myHaffCode);
fp=fopen("hfmtree.txt","w+"); 
for (i=0;i<n;i++)
{
printf("%c %d ",myHaffCode[i].ch,myHaffCode[i].weight);
fprintf(fp,"%c %d ",myHaffCode[i].ch,myHaffCode[i].weight);
for ( j=myHaffCode[i].start; j<n; j++)
{ 
printf("%d",myHaffCode[i].bit[j]);
fprintf(fp,"%d",myHaffCode[i].bit[j]);
}
fprintf(fp,"\n");
printf("\n");
}
fclose(fp);
printf("初始化成功!\n");
}
void Caozuo_C() //哈夫曼编码过程的函数，用于将文件编码
{
FILE *fp,*fp1,*fp2;
char zf[500];
fp=fopen("hfmtree.txt","r");
Coding ch[100];
char c;
int i=0;
while (feof(fp)==0)
{ 
fscanf(fp,"%s %d %s",&ch[i].ch,&ch[i].weight,&ch[i].bit);
i++;
}
fclose(fp); 
printf("现在进行编码操作。。。\n请选择:\nA.键盘输入 B.文件输入\n");
scanf("%s",&c);
if (c=='A')
{
printf("请输入字符串:\n");
scanf("%s",zf);
} 
char ch1[20],ch2[20];
int j;
if (c=='B')
{
printf("请输入正文的文件名:\n");
scanf("%s",&ch1);
fp1=fopen(ch1,"r");
}
printf("请输入保存结果的文件名:\n");
scanf("%s",&ch2); 
fp2=fopen(ch2,"w+");
if (c=='A')
{
int len,k;
len=strlen(zf);
for (k=0;k<len;k++)
for (j=0;j<i;j++)
if (ch[j].ch==zf[k])
{
fprintf(fp2,"%s",ch[j].bit);
printf("%s",ch[j].bit);
}
printf("\n"); 
}
if (c=='B')
{
while(feof(fp1)==0)
{ 
fscanf(fp1,"%c",&c);
for (j=0;j<i;j++) //对文件中的每一个字符进行编码

if (ch[j].ch==c)
{
fprintf(fp2,"%s",ch[j].bit);
printf("%s",ch[j].bit);
}
}
fprintf(fp2,"\n"); 
printf("\n");
fclose(fp1);
} 
fclose(fp2);
printf("编码完成!结果已存入%s中.\n\n",ch2);
}
void Caozuo_D() //译码操作
{
FILE *fp,*fp1; 
fp=fopen("huffman.txt","r");
int i,n;
fscanf(fp,"%d",&n);
HafNode *myHaffTree=(HafNode *)malloc(sizeof (HafNode)*(2*n+1));
for (i=0;i<n;i++)
fscanf(fp,"%s %d %d %d\n",&myHaffTree[i].ch,&myHaffTree[i].parent,&myHaffTree[i].lchild,&myHaffTree[i].rchild);
for (i=n;i<2*n-1;i++)
fscanf(fp,"%d %d %d\n",&myHaffTree[i].parent,&myHaffTree[i].lchild,&myHaffTree[i].rchild);
fclose(fp);


printf("译码的文件名:\n");
char ch1[20],ch2[20];
scanf("%s",ch1);
printf("保存结果的文件名:\n");
scanf("%s",ch2); 
fp=fopen(ch1,"r");
fp1=fopen(ch2,"w+");
char ch;
i=2*n-2;
while (!feof(fp))
{
fscanf(fp,"%c",&ch); 
if (ch=='0') //若编码为０，则找此结点的左孩子；
    i=myHaffTree[i].lchild;
if (ch=='1') //若编码为１，则找此结点的右孩子；　
    i=myHaffTree[i].rchild; 
if (i<n)
{
printf("%c",myHaffTree[i].ch);
fprintf(fp1,"%c",myHaffTree[i].ch);
i=2*n-2;
}
}
printf("\n");
fprintf(fp1,"\n");
fclose(fp);
fclose(fp1);
printf("译码过程完成!已将结果存入%s中.\n\n",ch2);
}

void PrintTree(HafNode *huf,int n,int p,FILE *fp)
{
int i;
if (n==-1)
return;
PrintTree(huf,huf[n].rchild,p+1,fp);
for (i=0;i<p;i++)
{
printf("    ");
fprintf(fp," ");
}
if (p>=0&&huf[n].rchild==-1)
{
printf("----");
printf("%c\n",huf[n].ch); //如果此结点为叶子结点，则将此结点输出；

fprintf(fp,"---%c\n",huf[n].ch);
}
else 
{
printf("@\n"); //如果此结点为非叶子结点，则输出"@";
fprintf(fp,"@\n");
}
PrintTree(huf,huf[n].lchild,p+1,fp);
}
void Caozuo_T() //打印哈夫曼树的操作
{
FILE *fp;
fp=fopen("huffman.txt","r");
int i,n;
fscanf(fp,"%d",&n);
HafNode *myHaffTree=(HafNode *)malloc(sizeof (HafNode)*(2*n+1));
for (i=0;i<n;i++)
fscanf(fp,"%s %d %d %d\n",&myHaffTree[i].ch,&myHaffTree[i].parent,&myHaffTree[i].lchild,&myHaffTree[i].rchild);
for (i=n;i<2*n-1;i++)
fscanf(fp,"%d %d %d\n",&myHaffTree[i].parent,&myHaffTree[i].lchild,&myHaffTree[i].rchild);
fclose(fp);
printf("保存结果的文件名:\n");
char ch1[20];
scanf("%s",ch1);
fp=fopen(ch1,"w+");
PrintTree(myHaffTree,2*n-2,0,fp);
fclose(fp);
printf("打印哈夫曼树结束!结果存在%s中.\n\n",ch1); 
}
void Caozuo_P() //打印代码文件的操作；
{
FILE *fp1,*fp2;
printf("文件名：\n");
char ch1[20],ch2[20];
scanf("%s",ch1);
printf("结果文件名：\n");
scanf("%s",ch2);
fp1=fopen(ch1,"r");
fp2=fopen(ch2,"w+");
int count=0;
char ch;
while (!feof(fp1))
{
fscanf(fp1,"%c",&ch); 
printf("%c",ch);
fprintf(fp2,"%c",ch);
count++;
if (count==50)
{
printf("\n");
fprintf(fp2,"\n");
count=0;
}
}
printf("\n");
fprintf(fp2,"\n");
fclose(fp1);
fclose(fp2);
printf("打印代码结束!结果存入%s中.\n\n",ch2);
}
void print()
{
printf("***********************************************\n");
printf("***** ***** ***** ***** ***** ***** ***** *****\n");
printf("***** ***** ***** ***** ***** ***** ***** *****\n");
printf("*****      欢迎使用哈夫曼编／译码器       *****\n");
printf("***********************************************\n");
printf("***** ***** ***** ***** ***** ***** ***** *****\n");
printf("***** ***** ***** ***** ***** ***** ***** *****\n");
printf("***** ***** C.编码     D.译码 ***** ***** *****\n");
printf("***** *****   T.打印哈夫曼树  ***** ***** *****\n");
printf("***** *****   P.打印代码文件  ***** ***** *****\n");
printf("***** *****   E.请退出该系统  ***** ***** *****\n");
printf("***** ***** ***** ***** ***** ***** ***** *****\n");
printf("***** ***** ***** ***** ***** ***** ***** *****\n");
printf("***********************************************\n");

}
int main()

{
int n=4;
int weight[100];
char ch[100],cha;
print();
Init(weight,ch);
while (1)
{
printf("请输入要执行的操作:\nC.编码　　　D.译码　　　T.打印哈夫曼树　　　P.打印代码文件　　　E.退出\n");
printf("请输入要执行的操作:\n");
scanf("%s",&cha);
if (cha=='E')
break; 
switch (cha)
{
case 'C':Caozuo_C();break; //执行编码操作
case 'D':Caozuo_D();break; //执行译码操作
case 'T':Caozuo_T();break; //打印哈夫曼树
case 'P':Caozuo_P();break; //打印代码文件
}
}
return 0; 
}

