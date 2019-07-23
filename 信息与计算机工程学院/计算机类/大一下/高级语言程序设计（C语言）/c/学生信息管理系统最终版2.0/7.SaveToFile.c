#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"



//当文件中已经存在文件时，写不进去
//追加续写失败

void Save_To_File(node *phead)
{
    int choose,s=0,flag=0;
    FILE *fp;
    node *p=phead->next;

    printf("\t  666.返回上一级  1.覆盖原文件  2.追加保存\n");

    printf("\t请选择保存方式:");
    scanf("%d",&choose);
    while( choose!=666 && choose!=1 && choose!=2 )
    {
        printf("获取的选择不符合格式，请重新输入！\n");
        printf("\t请选择保存方式:");
        scanf("%d",&choose);
    }
    switch(choose)
    {

    case 666:
        break;

    case 1://覆盖原文件
        if( (fp=fopen("filel.txt","w")) == NULL )
        {
            printf("操作失败！\n");
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
            printf("保存成功!\n");
        }
        if(flag==0)
        {
            printf("保存失败!\n");
        }
        fclose;
        break;

    case 2://追加保存
        if( (fp=fopen("filel.txt","a")) == NULL )
        {
            printf("操作失败！\n");
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
            printf("保存成功！\n");
        }
        if(flag==0)
        {
            printf("保存失败!\n");
        }
        fclose;
        break;

    }
}

