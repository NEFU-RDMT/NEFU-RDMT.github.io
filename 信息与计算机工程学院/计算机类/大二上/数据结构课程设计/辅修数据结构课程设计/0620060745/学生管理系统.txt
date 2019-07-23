#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h> 
#define N 4/*学生人数*/ 
#define M 3 /*课程门数*/ 

void input(); //输入
void display();//显示数据 
void select(); //查询
void statistics(); //统计
void dataSave(); //文件保存
void dataLoad(); //文件读入
void menu(); //菜单


float courses[N][M]; 
FILE *fp; 

void input() /*输入成绩*/ 
{ 
int i=0; 
int j=0;
for(i=0;i<N;i++) 
{ 
printf("学生%d号\n",i+1); 
for(j=0;j<M;j++) 
{ 
printf("第%d门成绩的分数为：",j+1); 
scanf("%f",&courses[i][j]); 
} 
printf("\n\n"); 
} 
printf("\n\n"); 
printf("输入完毕！按任意键返回主菜单！"); 
getch(); 
} 

void display() //显示学生成绩
{ 
int i=0; 
int j=0; 
for(i=0;i<N;i++) 
{ 
printf("学生%d号的成绩分别为：",i+1); 
for(j=0;j<M;j++) 
printf("%0.2f ",courses[i][j]); 
printf("\n"); 
} 
printf("\n按任意键返回主菜单！"); 
getch(); 
} 

void select(int no) //查询
{ 
int i=0; 
printf("您选择了查看学生%d号的成绩：",no); 
for(i=0;i<M;i++) 
{ 
printf("%0.2f ",courses[no-1][i]); 
} 
printf("\n按任意键返回主菜单！"); 
getch(); 
} 

void statistics() /*统计*/ 
{ 
float cAverage[M]; /*每门课程平均分*/ 
float sAverage[N]; /*每个学生平均分*/ 
float temp=0; 
int i=0; 
int j=0; 
/*算平均分*/ 
printf("单科课程平均分为："); /*单科课程平均分*/ 
for(i=0;i<M;i++) 
{ 
for(j=0;j<N;j++) 
{ 
temp=temp+courses[j][i]; 
} 
cAverage[i]=temp/M; 
printf("%0.2f\t",cAverage[i]); 
temp=0; 
} 
temp=0; 
printf("\n学生成绩平均分为："); 
for(j=0;j<N;j++) /*学生成绩平均分*/ 
{ 
for(i=0;i<M;i++) 
{ 
temp=temp+courses[j][i]; 
} 
sAverage[j]=temp/N; 
printf("%0.2f\t",sAverage[j]); 
temp=0; 
} 

/*排序(冒泡法)*/ 
for(i=0;i<M;i++) 
for(j=0;j<M-i-1;j++) 
if(cAverage[j]<cAverage[j+1]) 
{ 
temp=cAverage[j]; 
cAverage[j]=cAverage[j+1]; 
cAverage[j+1]=temp; 
} 
for(j=0;j<N;j++) 
for(i=0;i<N-j-1;i++) 
if(sAverage[i]<sAverage[i+1]) 
{ 
temp=sAverage[i]; 
sAverage[i]=sAverage[i+1]; 
sAverage[i+1]=temp; 
} 
printf("\n单科课程的前三名:"); 
for(i=0;i<3;i++) 
{ 
printf("\n第%d名：%0.2f",i+1,cAverage[i]); 
} 
printf("\n学生总成绩前三名:"); 
for(i=0;i<3;i++) 
{ 
printf("\n第%d名：%0.2f",i+1,sAverage[i]); 
} 
printf("\n\n按任意键返回主菜单！"); 
getch(); 
} 

void menu() 
{ 
int num=0; 
int n=0; 
printf("\n\t\t\t学生成绩管理系统\n\n"); 
printf("\t\t\t1.输入学生成绩\n\t\t\t2.显示所有数据\n\t\t\t3.按学生序号查询\n\t\t\t4.统计\n\t\t\t5.退出\n"); 
printf("\t\t\tchoose:"); 
scanf("%d",&num); 
switch(num) 
{ 
case 1: 
system("cls"); 
input(); 
break; 
case 2: 
system("cls"); 
display(); 
break; 
case 3: 
system("cls"); 
printf("请输入要查询的学生号："); 
scanf("%d",&n); 
select(n); 
break; 
case 4: 
system("cls"); 
statistics(); 
break; 
case 5: 
dataSave(); 
exit(1); 
default:break; 
} 
} 

void dataLoad() /*读入文件*/ 
{ 
int i=0; 
fp=fopen("record.txt","r+"); /*存在原文件*/ 
if(fp!=NULL) /*到文件尾返回*/ 
for(i=0;i<N&&!feof(fp);i++) 
fread(&courses[i],sizeof(courses),1,fp); 
else fp=fopen("record.txt","w"); /*不存在则新建一个文件*/ 
} 

void dataSave() /*文件保存*/ 
{ 
int i; 
fp=fopen("record.txt","w"); 
for(i=0;i<N;i++) 
if(fwrite(&courses[i],sizeof(courses),1,fp)!=1) 
{ 
fclose(fp); /*关闭文件指针*/ 
printf("file write error\n"); 
getch(); 
} 
} 

void main() 
{ 
int i=0; 
int j=0; 
dataLoad(); 
while(1) 
{ 
system("cls"); /*清屏*/ 
menu(); 
} 
} 
