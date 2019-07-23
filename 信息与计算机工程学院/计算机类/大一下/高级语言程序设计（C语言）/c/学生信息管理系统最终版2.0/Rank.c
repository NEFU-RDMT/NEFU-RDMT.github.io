
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

void Rank(node *phead)
{
    int num=1;
    node *p=phead->next;

    while(p)
    {
        p->rank=num++;
        p=p->next;
    }
}
