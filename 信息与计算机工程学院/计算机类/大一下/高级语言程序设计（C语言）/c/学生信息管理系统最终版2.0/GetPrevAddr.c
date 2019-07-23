#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

//返回指定编号学生节点的上一个节点的指针
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
