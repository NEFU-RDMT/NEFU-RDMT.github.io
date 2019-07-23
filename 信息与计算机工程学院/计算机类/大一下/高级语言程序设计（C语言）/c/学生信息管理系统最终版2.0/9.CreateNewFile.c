
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

void Create_New_File(node *phead)
{
    int choose;
    printf("\t  666.������һ��  1.�½��ļ�������  2.���������������ļ�\n");
    printf("\t��ѡ�񴴽���ʽ:");
    scanf("%d",&choose);

    while( choose!=666 && choose!=1 && choose!=2 )
    {
        printf("��ȡ��ѡ�񲻷��ϸ�ʽ�����������룡\n");
        printf("\t��ѡ�񴴽���ʽ:");
        scanf("%d",&choose);
    }
    switch(choose)
    {
    case 666:
        break;

    case 1:
        New1(phead);
        break;

    case 2:
        New2(phead);
        break;

    }
}

//�½��ļ�������
void New1(node *phead)
{
    FILE *fp;
    node *p=phead->next;
    int flag=0;
    char fname[100];//�ļ���
    printf("�������ļ���(��Ҫ����.txt)\n");
    scanf("%s",fname);//�����ļ���
    fp=fopen(fname,"w");
    if(fp==NULL)
    {
        printf("����ʧ��!\n");
        exit(1);
    }

    while(p)
    {

        Output(p);
        fprintf(fp,"%d %s %c %.2lf %.2lf %.2lf %.2lf %.2lf %d\n",p->num,p->name,p->sex,p->math_score,p->english_score,p->chinese_score,p->sum_score,p->ave_score,p->rank);
        p=p->next;
        flag=1;
    }
    if(flag==1)
    {
        printf("����ɹ���\n");
    }

    if(flag==0)
    {
        printf("����ʧ��!\n");
    }
    fclose(fp);
}
//���������������ļ�
void New2(node *phead)
{
    int choose2;
    FILE *fp;
    node *p=phead->next;
    int flag=0;
    char fname[100];//�ļ���
    printf("�������ļ���(��Ҫ����.txt)\n");
    scanf("%s",fname);//�����ļ���

    printf("\t  666.������һ��  1.���Ǳ���  2.׷�ӱ���\n");

    printf("\t��ѡ�񱣴淽ʽ:");
    scanf("%d",&choose2);
    while( choose2!=666 && choose2!=1 && choose2!=2 )
    {
        printf("��ȡ��ѡ�񲻷��ϸ�ʽ�����������룡\n");
        printf("\t��ѡ�񱣴淽ʽ:");
        scanf("%d",&choose2);
    }
    printf("\n");

    switch(choose2)
    {

    case 666:
        return;

    case 1://���Ǳ���
        fp=fopen(fname,"w");
        while(p)
        {
            fprintf(fp,"%d %s %c %.2lf %.2lf %.2lf %.2lf %.2lf %d\n",p->num,p->name,p->sex,p->math_score,p->english_score,p->chinese_score,p->sum_score,p->ave_score,p->rank);
            p=p->next;
            flag=1;

        }
        if(flag==1)
        {
            printf("����ɹ�!\n");
        }
        if(flag==0)
        {
            printf("����ʧ��!\n");
        }
        fclose(fp);
        break;

    case 2://׷�ӱ���
        fp=fopen(fname,"a");
        while(p)
        {
            fprintf(fp,"%d %s %c %.2lf %.2lf %.2lf %.2lf %.2lf %d\n",p->num,p->name,p->sex,p->math_score,p->english_score,p->chinese_score,p->sum_score,p->ave_score,p->rank);
            p=p->next;
            flag=1;
            //printf("**%d**",s++);
        }
        if(flag==1)
        {
            printf("����ɹ�!\n");
        }
        if(flag==0)
        {
            printf("����ʧ��!\n");
        }
        fclose(fp);
    }
}

