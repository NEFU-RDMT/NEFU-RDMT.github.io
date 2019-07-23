#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"



void Main_Delete(node *phead)
{
    int running=1;
    int choose;
    int question;
    int num;
    char name[20];
    int rank;

    while(running)
    {
        printf("\t  666.������һ��  1.��ѧ��ɾ��  2.������ɾ��  3.������ɾ��\n");

        printf("\t��ѡ��ɾ����ʽ:");
        scanf("%d",&choose);

        while( choose!=666 && choose!=1 && choose!=2 && choose!=3 )
        {
            printf("��ȡ��ѡ�񲻷��ϸ�ʽ�����������룡\n");
            printf("\t��ѡ��ɾ����ʽ:");
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
            printf("�Ƿ�ɾ��ѧ��Ϊ%d��ѧ����Ϣ��(1.��  2.��):",num);
            scanf("%d",&question);

            while(question!=1 && question!=2)
            {
                printf("��ȡ��ѡ�񲻷��ϸ�ʽ�����������룡\n");
                printf("�Ƿ�ɾ��ѧ��Ϊ%d��ѧ����Ϣ��(1.��  2.��):",num);
                scanf("%d",&question);
            }
            printf("\n");
            if( question ==1 )
            {
                Num_Delete(phead,num);
                Rank(phead);
                break;
            }
            else if(question==2 )
            {
                break;
            }

        case 2:
            printf("������������");
            scanf("%s",&name);
            printf("�Ƿ�ɾ������Ϊ%s��ѧ����Ϣ��(1.��  2.��):",name);
            scanf("%d",&question);

            while(question!=1 && question!=2)
            {
                printf("��ȡ��ѡ�񲻷��ϸ�ʽ�����������룡\n");
                printf("�Ƿ�ɾ������Ϊ%s��ѧ����Ϣ��(1.��  2.��):",name);
                scanf("%d",&question);
            }

            if( question ==1 )
            {
                Name_Delete(phead,name[20]);
                Rank(phead);
                break;
            }
            else if(question==2 )
            {
                break;
            }

        case 3:
            printf("������������");
            scanf("%d",&rank);
            printf("�Ƿ�ɾ������Ϊ%d��ѧ����Ϣ��(1.��  2.��):",rank);
            scanf("%d",&question);

            while(question!=1 && question!=2)
            {
                printf("��ȡ��ѡ�񲻷��ϸ�ʽ�����������룡\n");
                printf("�Ƿ�ɾ������Ϊ%d��ѧ����Ϣ��(1.��  2.��):",rank);
                scanf("%d",&question);
            }
            printf("\n");

            if( question ==1 )
            {
                Rank_Delete(phead,rank);
                Rank(phead);
                break;
            }
            else if(question==2 )
            {
                break;
            }
        }
    }
}



//��ѧ��ɾ��ѧ����Ϣ

void Num_Delete(node *phead,int num)
{
    node *plast = phead , *p = phead;
    while(p->num != num && p->next!=NULL)
    {
        p = p->next;
    }
    if(p!=NULL)
    {
        plast->next=p->next;
        free(p);
        p=plast->next;
        printf("ɾ���ɹ���\n");
    }
    else if(p==NULL)
    {
        printf("û�и�ѧ��ѧ����Ϣ��\n");
    }
}

//������ɾ��ѧ����Ϣ

void Name_Delete(node *phead,char name[])
{
    node *plast = phead , *p = phead;
    while( strcmp(p->name,name) != 0 && p->next!=NULL )
    {
        p = p->next;
    }
    if(p!=NULL)
    {
        plast->next=p->next;
        free(p);
        p=plast->next;
        printf("ɾ���ɹ���\n");
    }
    else if(p==NULL)
    {
        printf("û�и�����ѧ����Ϣ��\n");
    }
}

//������ɾ��ѧ����Ϣ

void Rank_Delete(node *phead,int rank)
{
    node *plast = phead , *p = phead;
    while(p->rank != rank && p->next!=NULL )
    {
        p = p->next;
    }
    if(p!=NULL)
    {
        plast->next=p->next;
        free(p);
        p=plast->next;
        printf("ɾ���ɹ���\n");
    }
    else if(p==NULL)
    {
        printf("û�и�����ѧ����Ϣ��\n");
    }
}



