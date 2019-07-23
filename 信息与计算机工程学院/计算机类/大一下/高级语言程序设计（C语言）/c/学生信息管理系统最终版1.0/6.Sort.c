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
        printf("\t 666.������һ��\n");
        printf("\t 1.��ѧ����������       2.��ѧ�Ž�������\n");
        printf("\t 3.��������������       4.��������������\n");
        printf("\t 5.����ѧ�ɼ���������   6.����ѧ�ɼ���������\n ");
        printf("\t 7.��Ӣ��ɼ���������   8.��Ӣ��ɼ���������\n");
        printf("\t 9.�����ĳɼ���������  10.�����ĳɼ���������\n");
        printf("\t11.��ƽ���ɼ���������  12.��ƽ���ɼ���������\n");
        printf("\t13.���ܳɼ���������    14.���ܳɼ���������\n");

        printf("\t��ѡ������ʽ:");
        scanf("%d",&choose);

        while(  choose!=666 && choose!=1 && choose!=2 && choose!=3 &&
                choose!=4 && choose!=5 && choose!=7 && choose!=8 &&
                choose!=9 && choose!=10 && choose!=11&& choose!=12 &&
                choose!=13 && choose!=14 )
        {
            printf("��ȡ��ѡ�񲻷��ϸ�ʽ�����������룡\n");
            printf("\t��ѡ������ʽ:");
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
            printf("�Ѱ�ѧ�Ž�����������!\n");
            break;

        case 2:
            Num_Sort_Down(phead);
            printf("�Ѱ�ѧ�Ž��н�������!\n");
            break;

        case 3:
            Name_Sort_Up(phead);
            printf("�Ѱ�����������������!\n");
            break;

        case 4:
            Name_Sort_Down(phead);
            printf("�Ѱ��������н�������!\n");
            break;

        case 5:
            Math_Score_Sort_Up(phead);
            printf("�Ѱ���ѧ�ɼ�������������!\n");
            break;

        case 6:
            Math_Score_Sort_Down(phead);
            printf("�Ѱ���ѧ�ɼ����н�������!\n");
            break;

        case 7:
            English_Score_Sort_Up(phead);
            printf("�Ѱ�Ӣ��ɼ�������������!\n");
            break;

        case 8:
            English_Score_Sort_Down(phead);
            printf("�Ѱ�Ӣ��ɼ����н�������!\n");
            break;

        case 9:
            Chinese_Score_Sort_Up(phead);
            printf("�Ѱ����ĳɼ�������������!\n");
            break;

        case 10:
            Chinese_Score_Sort_Down(phead);
            printf("�Ѱ����ĳɼ����н�������!\n");
            break;

        case 11:
            Sum_Score_Sort_Up(phead);
            printf("�Ѱ��ܳɼ�������������!\n");
            break;

        case 12:
            Sum_Score_Sort_Down(phead);
            printf("�Ѱ��ܳɼ����н�������!\n");
            break;

        case 13:
            Ave_Score_Sort_Up(phead);
            printf("�Ѱ�ƽ���ɼ�������������!\n");
            break;

        case 14:
            Ave_Score_Sort_Down(phead);
            printf("�Ѱ�ƽ���ɼ����н�������!\n");
            break;

        }
    }
}

void translate(node *p,node *q)
{
    int tnum;        //ѧ���ı��
    char tname[20];  //ѧ��������
    char tsex;        //ѧ�����Ա�

    double tmath_score; //ѧ������ѧ�ɼ�
    double tenglish_score; //ѧ����Ӣ��ɼ�
    double tchinese_score; //ѧ�������ĳɼ�
    double tave_score; //ѧ����ƽ���ɼ�
    double tsum_score;//ѧ�����ܳɼ�

    int trank;//ѧ��������

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

//��ѧ����Ϣ������������

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

//��ѧ����Ϣ���н�������

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




