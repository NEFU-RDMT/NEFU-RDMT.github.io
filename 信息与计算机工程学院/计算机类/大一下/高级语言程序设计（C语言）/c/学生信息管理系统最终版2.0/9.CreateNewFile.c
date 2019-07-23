
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

void Create_New_File(node *phead)
{
    int choose;
    printf("\t  666.返回上一级  1.新建文件并保存  2.保存至已有其他文件\n");
    printf("\t请选择创建方式:");
    scanf("%d",&choose);

    while( choose!=666 && choose!=1 && choose!=2 )
    {
        printf("获取的选择不符合格式，请重新输入！\n");
        printf("\t请选择创建方式:");
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

//新建文件并保存
void New1(node *phead)
{
    FILE *fp;
    node *p=phead->next;
    int flag=0;
    char fname[100];//文件名
    printf("请输入文件名(需要输入.txt)\n");
    scanf("%s",fname);//输入文件名
    fp=fopen(fname,"w");
    if(fp==NULL)
    {
        printf("操作失败!\n");
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
        printf("保存成功！\n");
    }

    if(flag==0)
    {
        printf("保存失败!\n");
    }
    fclose(fp);
}
//保存至已有其他文件
void New2(node *phead)
{
    int choose2;
    FILE *fp;
    node *p=phead->next;
    int flag=0;
    char fname[100];//文件名
    printf("请输入文件名(需要输入.txt)\n");
    scanf("%s",fname);//输入文件名

    printf("\t  666.返回上一级  1.覆盖保存  2.追加保存\n");

    printf("\t请选择保存方式:");
    scanf("%d",&choose2);
    while( choose2!=666 && choose2!=1 && choose2!=2 )
    {
        printf("获取的选择不符合格式，请重新输入！\n");
        printf("\t请选择保存方式:");
        scanf("%d",&choose2);
    }
    printf("\n");

    switch(choose2)
    {

    case 666:
        return;

    case 1://覆盖保存
        fp=fopen(fname,"w");
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
        fclose(fp);
        break;

    case 2://追加保存
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
            printf("保存成功!\n");
        }
        if(flag==0)
        {
            printf("保存失败!\n");
        }
        fclose(fp);
    }
}

