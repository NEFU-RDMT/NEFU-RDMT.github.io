#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"



//��ʾѧ����Ϣ
void Main_Show(node *phead)
{
    int running=1;
    int choose;
    int num;
    char name[20];
    int rank;

    while(running)
    {
        printf("\t  666.������һ��  1.��ѧ����ʾ  2.��������ʾ  3.��������ʾ  4.ȫ����ʾ\n");
        printf("\t��ѡ����ʾ��ʽ:");
        scanf("%d",&choose);

        while( choose!=666 && choose!=1 && choose!=2 && choose!=3 && choose!=4 )
        {
            printf("��ȡ��ѡ�񲻷��ϸ�ʽ�����������룡\n");
            printf("\t��ѡ����ʾ��ʽ:");
            scanf("%d",&choose);
        }
        printf("\n");

        switch( choose )
        {

        case 666:
            running=0;
            break;

        case 1:
            printf("��������Ҫ��ʾ��ѧ��ѧ��(1~100)��");
            scanf("%d",&num);
            Num_Show(phead,num);
            Rank(phead);
            break;

        case 2:
            printf("��������Ҫ��ʾ��ѧ��������");
            scanf("%s",name);
            Name_Show(phead,name[20]);
            Rank(phead);
            break;

        case 3:
            printf("��������Ҫ��ʾ��ѧ��������");
            scanf("%d",&rank);
            Rank_Show(phead,rank);
            Rank(phead);
            break;

        case 4:
            printf("������ӡȫ��ѧ����Ϣ��\n");
            All_Show(phead);
            Rank(phead);
            break;
        }

    }
}


void Num_Show(node *phead,int num)
{
    node *p=phead;
    //printf("���е�����1\n");//û����
    while( p->num!=num && p->next!=NULL )
    {
        p=p->next;
    }
    //printf("���е�����2\n");//����bug
    if(p==NULL)
    {
        printf("û�и�ѧ�ŵ�ѧ����Ϣ��\n");
    }
    else if( p != NULL )
    {
        printf("  ���    ����   �Ա�  ��ѧ�ɼ�   Ӣ��ɼ�    ���ĳɼ�    ƽ���ɼ�    �ܳɼ� ����  \n");
        Output(p);
    }
}
void Name_Show(node *phead,char name[20])
{
    node *p=phead;

    while( strcmp(p->name,name) !=0 && p->next!=NULL )
    {
        p=p->next;
    }

    if( p == NULL )
    {
        printf("û�и�������ѧ����Ϣ��\n");
    }
    else if( p != NULL )
    {
        printf("  ���    ����   �Ա�  ��ѧ�ɼ�   Ӣ��ɼ�    ���ĳɼ�    ƽ���ɼ�    �ܳɼ� ����  \n");
        Output(p);
    }
}
void Rank_Show(node *phead,int rank)
{
    node *p=phead;
    while( p->rank != rank && p->next!=NULL )
    {
        p=p->next;
    }
    if( p == NULL )
    {
        printf("û�и�������ѧ����Ϣ��\n");
    }
    else if( p != NULL )
    {
        printf("  ���    ����   �Ա�  ��ѧ�ɼ�   Ӣ��ɼ�    ���ĳɼ�    ƽ���ɼ�    �ܳɼ� ����  \n");
        Output(p);
    }
}

//��ӡȫ����Ϣ

void All_Show(node *phead)
{
    node *p = phead;

    printf("  ���    ����   �Ա�  ��ѧ�ɼ�   Ӣ��ɼ�    ���ĳɼ�    ƽ���ɼ�    �ܳɼ� ����  \n");
    while( p->next!=NULL )
    {
        Output(p);
        p = p->next;//��ָ��ָ����һ���ڵ�
    }
}
