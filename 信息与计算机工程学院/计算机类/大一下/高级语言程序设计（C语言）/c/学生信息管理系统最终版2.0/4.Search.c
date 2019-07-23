#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"



//����ѧ����Ϣ

void Main_Search(node *phead)
{
    int running=1;
    int num;        //ѧ���ı��
    char name[20];  //ѧ��������
    int rank;//ѧ��������

    int choose;

    while(running)
    {
        printf("\t  666.������һ��  1.��ѧ�Ų���  2.����������  3.����������\n");
        printf("\t��ѡ����ҷ�ʽ:");
        scanf("%d",&choose);

        while( choose!=666 && choose!=1 && choose!=2 && choose!=3 )
        {
            printf("��ȡ��ѡ�񲻷��ϸ�ʽ�����������룡\n");
            printf("\t��ѡ����ҷ�ʽ:");
            scanf("%d",&choose);
        }
        printf("\n");

        switch( choose )
        {

        case 666:
            running=0;
            break;

        case 1:
            printf("������ѧ��(1~100)��");
            scanf("%d",&num);
            Num_Search(phead,num);
            break;

        case 2:
            printf("������������");
            scanf("%s",name);
            Name_Search(phead,name[20]);
            break;

        case 3:
            printf("���������Σ�");
            scanf("%s",rank);
            Rank_Search(phead,rank);
            break;
        }
    }
}

//��ѧ�Ų���

void Num_Search(node *phead,int num)
{
    node *p=phead;
    while( p->num != num && p->next!=NULL )
    {
        p=p->next;
    }
    if(p==NULL)
    {
        printf("û�и�ѧ�ŵ�ѧ����Ϣ��\n");

    }
    else if(p!=NULL)
    {
        printf("  ���    ����   �Ա�  ��ѧ�ɼ�   Ӣ��ɼ�    ���ĳɼ�    ƽ���ɼ�    �ܳɼ� ����  \n");
        Output(p);
    }
}

//����������

void Name_Search(node *phead,char name[20])
{
    node *p=phead;

    while(strcmp(p->name,name)!=0 && p->next!=NULL )
    {
        p=p->next;
    }

    if(p==NULL)
    {
        printf("û�и�������ѧ����Ϣ��\n");

    }
    else if(p!=NULL)
    {
        printf("  ���    ����   �Ա�  ��ѧ�ɼ�   Ӣ��ɼ�    ���ĳɼ�    ƽ���ɼ�    �ܳɼ� ����  \n");
        Output(p);
    }
}

//����������

void Rank_Search(node *phead,int rank)
{
    node *p=phead;

    while(p->rank != rank && p->next!=NULL )
    {
        p=p->next;
    }
    if(p==NULL)
    {
        printf("û�и�������ѧ����Ϣ��\n");

    }
    else if(p!=NULL)
    {
        printf("  ���    ����   �Ա�  ��ѧ�ɼ�   Ӣ��ɼ�    ���ĳɼ�    ƽ���ɼ�    �ܳɼ� ����  \n");
        Output(p);
    }
}

