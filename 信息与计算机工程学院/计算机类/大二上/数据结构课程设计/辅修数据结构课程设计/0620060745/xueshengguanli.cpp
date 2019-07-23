#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h> 
#define N 4/*ѧ������*/ 
#define M 3 /*�γ�����*/ 

void input(); //����
void display();//��ʾ���� 
void select(); //��ѯ
void statistics(); //ͳ��
void dataSave(); //�ļ�����
void dataLoad(); //�ļ�����
void menu(); //�˵�


float courses[N][M]; 
FILE *fp; 

void input() /*����ɼ�*/ 
{ 
int i=0; 
int j=0;
for(i=0;i<N;i++) 
{ 
printf("ѧ��%d��\n",i+1); 
for(j=0;j<M;j++) 
{ 
printf("��%d�ųɼ��ķ���Ϊ��",j+1); 
scanf("%f",&courses[i][j]); 
} 
printf("\n\n"); 
} 
printf("\n\n"); 
printf("������ϣ���������������˵���"); 
getch(); 
} 

void display() //��ʾѧ���ɼ�
{ 
int i=0; 
int j=0; 
for(i=0;i<N;i++) 
{ 
printf("ѧ��%d�ŵĳɼ��ֱ�Ϊ��",i+1); 
for(j=0;j<M;j++) 
printf("%0.2f ",courses[i][j]); 
printf("\n"); 
} 
printf("\n��������������˵���"); 
getch(); 
} 

void select(int no) //��ѯ
{ 
int i=0; 
printf("��ѡ���˲鿴ѧ��%d�ŵĳɼ���",no); 
for(i=0;i<M;i++) 
{ 
printf("%0.2f ",courses[no-1][i]); 
} 
printf("\n��������������˵���"); 
getch(); 
} 

void statistics() /*ͳ��*/ 
{ 
float cAverage[M]; /*ÿ�ſγ�ƽ����*/ 
float sAverage[N]; /*ÿ��ѧ��ƽ����*/ 
float temp=0; 
int i=0; 
int j=0; 
/*��ƽ����*/ 
printf("���ƿγ�ƽ����Ϊ��"); /*���ƿγ�ƽ����*/ 
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
printf("\nѧ���ɼ�ƽ����Ϊ��"); 
for(j=0;j<N;j++) /*ѧ���ɼ�ƽ����*/ 
{ 
for(i=0;i<M;i++) 
{ 
temp=temp+courses[j][i]; 
} 
sAverage[j]=temp/N; 
printf("%0.2f\t",sAverage[j]); 
temp=0; 
} 

/*����(ð�ݷ�)*/ 
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
printf("\n���ƿγ̵�ǰ����:"); 
for(i=0;i<3;i++) 
{ 
printf("\n��%d����%0.2f",i+1,cAverage[i]); 
} 
printf("\nѧ���ܳɼ�ǰ����:"); 
for(i=0;i<3;i++) 
{ 
printf("\n��%d����%0.2f",i+1,sAverage[i]); 
} 
printf("\n\n��������������˵���"); 
getch(); 
} 

void menu() 
{ 
int num=0; 
int n=0; 
printf("\n\t\t\tѧ���ɼ�����ϵͳ\n\n"); 
printf("\t\t\t1.����ѧ���ɼ�\n\t\t\t2.��ʾ��������\n\t\t\t3.��ѧ����Ų�ѯ\n\t\t\t4.ͳ��\n\t\t\t5.�˳�\n"); 
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
printf("������Ҫ��ѯ��ѧ���ţ�"); 
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

void dataLoad() /*�����ļ�*/ 
{ 
int i=0; 
fp=fopen("record.txt","r+"); /*����ԭ�ļ�*/ 
if(fp!=NULL) /*���ļ�β����*/ 
for(i=0;i<N&&!feof(fp);i++) 
fread(&courses[i],sizeof(courses),1,fp); 
else fp=fopen("record.txt","w"); /*���������½�һ���ļ�*/ 
} 

void dataSave() /*�ļ�����*/ 
{ 
int i; 
fp=fopen("record.txt","w"); 
for(i=0;i<N;i++) 
if(fwrite(&courses[i],sizeof(courses),1,fp)!=1) 
{ 
fclose(fp); /*�ر��ļ�ָ��*/ 
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
system("cls"); /*����*/ 
menu(); 
} 
} 
