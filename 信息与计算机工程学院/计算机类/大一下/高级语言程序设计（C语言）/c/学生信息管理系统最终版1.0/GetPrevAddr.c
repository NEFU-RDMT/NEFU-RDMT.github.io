#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

//����ָ�����ѧ���ڵ����һ���ڵ��ָ��
 node *GetPrevAdd(node *phead,int num)
{
    node *p = phead;
    while(p->next != NULL)
    {
        if(p->next->num == num) return p;
        p = p->next;
    }
    return NULL;
}
