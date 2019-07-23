#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

void Main_Sort(node *phead)
{
    int running=1;
    node *p = phead->next;
    int choose;
    while(running)
    {
        printf("\t 666.返回上一级\n");
        printf("\t 1.按学号升序排序       2.按学号降序排序\n");
        printf("\t 3.按姓名升序排序       4.按姓名降序排序\n");
        printf("\t 5.按数学成绩升序排序   6.按数学成绩降序排序\n ");
        printf("\t 7.按英语成绩升序排序   8.按英语成绩降序排序\n");
        printf("\t 9.按语文成绩升序排序  10.按语文成绩降序排序\n");
        printf("\t11.按平均成绩升序排序  12.按平均成绩降序排序\n");
        printf("\t13.按总成绩升序排序    14.按总成绩降序排序\n");

        printf("\t请选择排序方式:");
        scanf("%d",&choose);

        while(  choose!=666 && choose!=1 && choose!=2 && choose!=3 &&
                choose!=4 && choose!=5 && choose!=7 && choose!=8 &&
                choose!=9 && choose!=10 && choose!=11&& choose!=12 &&
                choose!=13 && choose!=14 )
        {
            printf("获取的选择不符合格式，请重新输入！\n");
            printf("\t请选择排序方式:");
            scanf("%d",&choose);
        }
        printf("\n");

        switch( choose )
        {

        case 666:
            running=0;
            break;

        case 1:

            Num_Sort_Up(phead);
            printf("已按学号进行升序排序!\n");
            break;

        case 2:
            Num_Sort_Down(phead);
            printf("已按学号进行降序排序!\n");
            break;

        case 3:
            Name_Sort_Up(phead);
            printf("已按姓名进行升序排序!\n");
            break;

        case 4:
            Name_Sort_Down(phead);
            printf("已按姓名进行降序排序!\n");
            break;

        case 5:
            Math_Score_Sort_Up(phead);
            printf("已按数学成绩进行升序排序!\n");
            break;

        case 6:
            Math_Score_Sort_Down(phead);
            printf("已按数学成绩进行降序排序!\n");
            break;

        case 7:
            English_Score_Sort_Up(phead);
            printf("已按英语成绩进行升序排序!\n");
            break;

        case 8:
            English_Score_Sort_Down(phead);
            printf("已按英语成绩进行降序排序!\n");
            break;

        case 9:
            Chinese_Score_Sort_Up(phead);
            printf("已按语文成绩进行升序排序!\n");
            break;

        case 10:
            Chinese_Score_Sort_Down(phead);
            printf("已按语文成绩进行降序排序!\n");
            break;

        case 11:
            Sum_Score_Sort_Up(phead);
            printf("已按总成绩进行升序排序!\n");
            break;

        case 12:
            Sum_Score_Sort_Down(phead);
            printf("已按总成绩进行降序排序!\n");
            break;

        case 13:
            Ave_Score_Sort_Up(phead);
            printf("已按平均成绩进行升序排序!\n");
            break;

        case 14:
            Ave_Score_Sort_Down(phead);
            printf("已按平均成绩进行降序排序!\n");
            break;

        }
    }
}

void translate(node *p,node *q)
{
    int tnum;        //学生的编号
    char tname[20];  //学生的姓名
    char tsex;        //学生的性别

    double tmath_score; //学生的数学成绩
    double tenglish_score; //学生的英语成绩
    double tchinese_score; //学生的语文成绩
    double tave_score; //学生的平均成绩
    double tsum_score;//学生的总成绩

    int trank;//学生的排名

    tnum = p->num;
    p->num = q->num;
    q->num = tnum;

    strcpy(tname,p->name);
    strcpy(p->name,q->name);
    strcpy(q->name,tname);

    tsex = p->sex;
    p->sex = q->sex;
    q->sex = tsex;

    tmath_score = p->math_score;
    p->math_score = q->math_score;
    q->math_score = tmath_score;

    tenglish_score = p->english_score;
    p->english_score = q->english_score;
    q->english_score = tenglish_score;

    tchinese_score = p->chinese_score;
    p->chinese_score = q->chinese_score;
    q->chinese_score = tchinese_score;

    tave_score = p->ave_score;
    p->ave_score = q->ave_score;
    q->ave_score = tave_score;

    tsum_score = p->sum_score;
    p->sum_score = q->sum_score;
    q->sum_score = tsum_score;

    trank = p->rank;
    p->rank = q->rank;
    q->rank = trank;
}

//对学生信息进行升序排序

void Num_Sort_Up(node *phead)
{
    node *pLast,*p;
    int i,j,n=Length(phead),t;
    if(n <= 1) return ;
    for(i=0 ; i<n-1 ; i++)
    {
        pLast = phead->next;
        p = pLast->next;
        for(j=0; j<n-i-1; j++)
        {
            if( pLast->num > p->num )
            {
                translate(pLast,p);
            }
            pLast = p;
            p = p->next;
        }
    }
}

void Name_Sort_Up(node *phead)
{
    node *pLast,*p;
    int i,j,n=Length(phead),t;
    if(n<=1) return ;
    for(i=0; i<n-1; i++)
    {
        pLast=phead->next;
        p=pLast->next;
        for(j=0; j<n-i-1; j++)
        {
            if(pLast->name > p->name)
            {
                translate(pLast,p);
            }
            pLast=p;
            p=p->next;
        }
    }

}

void Math_Score_Sort_Up(node *phead)
{
    node *pLast,*p;
    int i,j,n=Length(phead),t;
    if(n<=1) return ;
    for(i=0; i<n-1; i++)
    {
        pLast=phead->next;
        p=pLast->next;
        for(j=0; j<n-i-1; j++)
        {
            if(pLast->math_score > p->math_score)
            {
                translate(pLast,p);
            }
            pLast=p;
            p=p->next;
        }
    }
}

void English_Score_Sort_Up(node *phead)
{
    node *pLast,*p;
    int i,j,n=Length(phead),t;
    if(n<=1) return ;
    for(i=0; i<n-1; i++)
    {
        pLast=phead->next;
        p=pLast->next;
        for(j=0; j<n-i-1; j++)
        {
            if(pLast->english_score > p->english_score)
            {
                translate(pLast,p);
            }
            pLast=p;
            p=p->next;
        }
    }
}

void Chinese_Score_Sort_Up(node *phead)
{
    node *pLast,*p;
    int i,j,n=Length(phead),t;
    if(n<=1) return ;
    for(i=0; i<n-1; i++)
    {
        pLast=phead->next;
        p=pLast->next;
        for(j=0; j<n-i-1; j++)
        {
            if(pLast->chinese_score > p->chinese_score)
            {
                translate(pLast,p);
            }
            pLast=p;
            p=p->next;
        }
    }
}

void Ave_Score_Sort_Up(node *phead)
{
    node *pLast,*p;
    int i,j,n=Length(phead),t;
    if(n<=1) return ;
    for(i=0; i<n-1; i++)
    {
        pLast=phead->next;
        p=pLast->next;
        for(j=0; j<n-i-1; j++)
        {
            if(pLast->ave_score > p->ave_score)
            {
                translate(pLast,p);
            }
            pLast=p;
            p=p->next;
        }
    }

}

void Sum_Score_Sort_Up(node *phead)
{
    node *pLast,*p;
    int i,j,n=Length(phead),t;
    if(n<=1) return ;
    for(i=0; i<n-1; i++)
    {
        pLast=phead->next;
        p=pLast->next;
        for(j=0; j<n-i-1; j++)
        {
            if(pLast->sum_score > p->sum_score)
            {
                translate(pLast,p);
            }
            pLast=p;
            p=p->next;
        }
    }
}

//对学生信息进行降序排序

void Num_Sort_Down(node *phead)
{
    node *pLast,*p;
    int i,j,n=Length(phead),t;
    if(n <= 1) return ;
    for(i=0 ; i<n-1 ; i++)
    {
        pLast = phead->next;
        p = pLast->next;
        for(j=0; j<n-i-1; j++)
        {
            if( pLast->num < p->num )
            {
                translate(pLast,p);
            }
            pLast = p;
            p = p->next;
        }
    }

}

void Name_Sort_Down(node *phead)
{
    node *pLast,*p;
    int i,j,n=Length(phead),t;
    if(n<=1) return ;
    for(i=0; i<n-1; i++)
    {
        pLast=phead->next;
        p=pLast->next;
        for(j=0; j<n-i-1; j++)
        {
            if(pLast->name < p->name)
            {
                translate(pLast,p);
            }
            pLast=p;
            p=p->next;
        }
    }
}

void Math_Score_Sort_Down(node *phead)
{
    node *pLast,*p;
    int i,j,n=Length(phead),t;
    if(n<=1) return ;
    for(i=0; i<n-1; i++)
    {
        pLast=phead->next;
        p=pLast->next;
        for(j=0; j<n-i-1; j++)
        {
            if(pLast->math_score < p->math_score)
            {
                translate(pLast,p);
            }
            pLast=p;
            p=p->next;
        }
    }
}

void English_Score_Sort_Down(node *phead)
{
    node *pLast,*p;
    int i,j,n=Length(phead),t;
    if(n<=1) return ;
    for(i=0; i<n-1; i++)
    {
        pLast=phead->next;
        p=pLast->next;
        for(j=0; j<n-i-1; j++)
        {
            if(pLast->english_score < p->english_score)
            {
                translate(pLast,p);
            }
            pLast=p;
            p=p->next;
        }
    }
}

void Chinese_Score_Sort_Down(node *phead)
{
    node *pLast,*p;
    int i,j,n=Length(phead),t;
    if(n<=1) return ;
    for(i=0; i<n-1; i++)
    {
        pLast=phead->next;
        p=pLast->next;
        for(j=0; j<n-i-1; j++)
        {
            if(pLast->chinese_score < p->chinese_score)
            {
                translate(pLast,p);
            }
            pLast=p;
            p=p->next;
        }
    }
}

void Ave_Score_Sort_Down(node *phead)
{
    node *pLast,*p;
    int i,j,n=Length(phead),t;
    if(n<=1) return ;
    for(i=0; i<n-1; i++)
    {
        pLast=phead->next;
        p=pLast->next;
        for(j=0; j<n-i-1; j++)
        {
            if(pLast->ave_score < p->ave_score)
            {
                translate(pLast,p);
            }
            pLast=p;
            p=p->next;
        }
    }
}

void Sum_Score_Sort_Down(node *phead)
{
    node *pLast,*p;
    int i,j,n=Length(phead),t;
    if(n<=1) return ;
    for(i=0; i<n-1; i++)
    {
        pLast=phead->next;
        p=pLast->next;
        for(j=0; j<n-i-1; j++)
        {
            if(pLast->sum_score < p->sum_score)
            {
                translate(pLast,p);
            }
            pLast=p;
            p=p->next;
        }
    }
}




