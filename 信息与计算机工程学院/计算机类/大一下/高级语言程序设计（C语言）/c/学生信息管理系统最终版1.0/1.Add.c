
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

//��ѧ����Ϣ�ڵ���뵽������

void Add(node *phead)
{

    node *p=phead;
    node *q = NULL;//�½ڵ㣬���������µĶ�̬����ռ�
    node *pflag = NULL;//��ֹѭ��������
    while(1)
    {
        q=(node *)malloc( sizeof(node) );//��̬����ռ䣬�洢ѧ����Ϣ;

        pflag = Input(q);
        //printf("%d",q->num);q��ӳɹ��ˣ�

        if(pflag == NULL)//��ֹ��ѭ������Ϊ����ѧ��Ϊ0
        {
            break;
        }
        else
        {
            //printf("���е�����1\n");û����

            while( p!=NULL && p->next!=NULL )//Ѱ�������������һ���ڵ�
            {
                printf("���е�����la\n");
                p=p->next;
            }
            p->next=q;
            q->next=NULL;
            p=q;
        }
    }
    Rank(phead);
}

/*if( q == NULL )
        {
            printf("�����ڴ�ռ�ʧ��!\n");
            return NULL;
        }*/
