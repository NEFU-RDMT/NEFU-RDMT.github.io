#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"



//���ļ����Ѿ������ļ�ʱ��д����ȥ
//׷����дʧ��

void Save_To_File(node *phead)
{
    int choose,s=0,flag=0;
    FILE *fp;
    node *p=phead->next;

    printf("\t  666.������һ��  1.����ԭ�ļ�  2.׷�ӱ���\n");

    printf("\t��ѡ�񱣴淽ʽ:");
    scanf("%d",&choose);
    while( choose!=666 && choose!=1 && choose!=2 )
    {
        printf("��ȡ��ѡ�񲻷��ϸ�ʽ�����������룡\n");
        printf("\t��ѡ�񱣴淽ʽ:");
        scanf("%d",&choose);
    }
    switch(choose)
    {

    case 666:
        break;

    case 1://����ԭ�ļ�
        if( (fp=fopen("filel.txt","w")) == NULL )
        {
            printf("����ʧ�ܣ�\n");
            exit(1);
        }
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
        fclose;
        break;

    case 2://׷�ӱ���
        if( (fp=fopen("filel.txt","a")) == NULL )
        {
            printf("����ʧ�ܣ�\n");
            exit(1);
        }
        while(p)
        {
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
        fclose;
        break;

    }
}

